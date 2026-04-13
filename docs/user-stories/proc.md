# PROC Domain Stories

## PROC-STORY-001

**AS A** user
**I WANT** every safe cell in a minefield to be replaced with the correct adjacent mine count
**SO THAT** the annotated field is correct

**Architecture Reference:** Chapter 5 Building Block View - Field Processor, Chapter 6 Runtime View - Field Processing Flow

### PROC-STORY-001-S1: Count adjacent mines for an interior safe cell

**GIVEN**
- a parsed field exists
- the target cell is not a mine
- the target cell has mines in neighboring positions

**WHEN**
- the field processor computes the annotated output for the field

**THEN**
- the target cell is replaced with the correct number of adjacent mines
- the value reflects all valid neighboring positions
- the mine layout remains unchanged

### PROC-STORY-001-S2: Preserve mine cells unchanged

**GIVEN**
- a parsed field exists
- the target cell contains a mine

**WHEN**
- the field processor computes the annotated output for the field

**THEN**
- the mine cell remains `*`
- no numeric value is written into that position

### PROC-STORY-001-S3: Assign zero when no adjacent mines exist

**GIVEN**
- a parsed field exists
- the target cell is safe
- none of its valid neighboring cells contains a mine

**WHEN**
- the field processor computes the annotated output for the field

**THEN**
- the target cell is replaced with `0`

---

## FE Sub-Stories

### PROC-FE-001.1

**AS A** user
**I WANT** processed cell values to appear in the final printed field
**SO THAT** I can see the annotated result of the computation

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 6 Runtime View - Output Generation Flow

#### PROC-FE-001.1-S1: Display computed numeric values

**GIVEN**
- the field processor has produced an annotated field
- a safe cell has computed value `3`

**WHEN**
- the output formatter prints the processed field

**THEN**
- the corresponding output position contains `3`

---

## BE Sub-Stories

### PROC-BE-001.1

**AS A** developer
**I WANT** the processor to inspect all valid neighboring cells around a safe position
**SO THAT** adjacent mine counts are computed correctly

**Architecture Reference:** Chapter 5 Building Block View - Field Processor

#### PROC-BE-001.1-S1: Count mines in all neighboring directions

**GIVEN**
- a safe cell exists in the field
- neighboring cells may appear horizontally, vertically, or diagonally

**WHEN**
- the processor evaluates that cell

**THEN**
- all valid neighboring positions are checked exactly once
- the resulting count equals the number of neighboring mines

### PROC-BE-001.2

**AS A** developer
**I WANT** boundary cells to be processed safely
**SO THAT** edge and corner positions are counted without invalid memory access

**Architecture Reference:** Chapter 5 Building Block View - Field Processor, Chapter 6 Runtime View - Cell Evaluation

#### PROC-BE-001.2-S1: Process a corner cell correctly

**GIVEN**
- the target cell is located in a corner of the field

**WHEN**
- the processor evaluates its adjacent mine count

**THEN**
- only valid in-bounds neighbors are considered
- the correct adjacent mine count is produced

#### PROC-BE-001.2-S2: Process an edge cell correctly

**GIVEN**
- the target cell is located on an edge but not in a corner

**WHEN**
- the processor evaluates its adjacent mine count

**THEN**
- only valid in-bounds neighbors are considered
- the correct adjacent mine count is produced

### PROC-BE-001.3

**AS A** developer
**I WANT** mine cells to bypass numeric processing
**SO THAT** mines remain unchanged in the annotated field

**Architecture Reference:** Chapter 5 Building Block View - Field Processor

#### PROC-BE-001.3-S1: Skip numeric conversion for a mine

**GIVEN**
- the current cell contains `*`

**WHEN**
- the processor evaluates the field

**THEN**
- the cell remains `*`
- no adjacent-mine count is computed for that position

---

## INFRA Sub-Stories

### PROC-INFRA-001.1

**AS A** developer
**I WANT** processing logic tests to run automatically
**SO THAT** regressions in adjacent-count computation are detected early

**Architecture Reference:** Chapter 7 Deployment View - Single Binary Execution, Chapter 8 Cross-Cutting Concepts - Testability

#### PROC-INFRA-001.1-S1: Run processing tests in CI

**GIVEN**
- automated tests exist for field processing
- the CI workflow is configured

**WHEN**
- changes are pushed or a pull request is opened

**THEN**
- the processing tests are executed automatically
- the pipeline fails if any processing test fails

### PROC-INFRA-001.2

**AS A** developer
**I WANT** the application to build reproducibly as a single C++ binary
**SO THAT** the field processor can be run consistently in local and CI environments

**Architecture Reference:** Chapter 7 Deployment View - Single Compiled Binary

#### PROC-INFRA-001.2-S1: Build and run the processor binary

**GIVEN**
- a C++17 compiler is available
- the source code is present

**WHEN**
- the project is compiled and executed with redirected standard input

**THEN**
- a single runnable binary is produced
- the binary accepts minefield input and produces annotated output

---

## Traceability Verification

| Scenario ID | Architecture Reference | Parent Story | Testable Assertion |
|---|---|---|---|
| PROC-STORY-001-S1 | Chapter 6 Runtime View - Field Processing Flow | PROC-STORY-001 | safe interior cell is replaced with the correct adjacent mine count |
| PROC-STORY-001-S2 | Chapter 5 Building Block View - Field Processor | PROC-STORY-001 | mine cell remains `*` |
| PROC-STORY-001-S3 | Chapter 5 Building Block View - Field Processor | PROC-STORY-001 | safe cell with no adjacent mines becomes `0` |
| PROC-FE-001.1-S1 | Chapter 6 Runtime View - Output Generation Flow | PROC-FE-001.1 | computed value appears in printed output |
| PROC-BE-001.1-S1 | Chapter 5 Building Block View - Field Processor | PROC-BE-001.1 | all valid neighboring positions are checked exactly once |
| PROC-BE-001.2-S1 | Chapter 6 Runtime View - Cell Evaluation | PROC-BE-001.2 | corner cell uses only valid in-bounds neighbors |
| PROC-BE-001.2-S2 | Chapter 6 Runtime View - Cell Evaluation | PROC-BE-001.2 | edge cell uses only valid in-bounds neighbors |
| PROC-BE-001.3-S1 | Chapter 5 Building Block View - Field Processor | PROC-BE-001.3 | mine cell bypasses numeric processing |
| PROC-INFRA-001.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | PROC-INFRA-001.1 | CI runs processing tests and fails on errors |
| PROC-INFRA-001.2-S1 | Chapter 7 Deployment View - Single Compiled Binary | PROC-INFRA-001.2 | single binary builds and runs with stdin input |
