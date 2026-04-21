# PROC Domain Stories

## PROC-STORY-001

**AS A** user
**I WANT** every safe cell in a minefield to be replaced with the correct adjacent mine count
**SO THAT** the annotated field is correct

**Architecture Reference:** Chapter 5 Building Block View - Field Processor, Chapter 6 Runtime View - Main Processing Scenario

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

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 6 Runtime View - Main Processing Scenario

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

**Architecture Reference:** Chapter 5 Building Block View - Field Processor, Chapter 11 Risks and Technical Debts - R-2

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
**I WANT** all processing tests to pass when running `./runTests` inside the Docker container
**SO THAT** regressions in adjacent-count computation are detected in a clean, isolated local environment

**Architecture Reference:** Chapter 8 Cross-Cutting Concepts - Testability, Chapter 7 Deployment View - Build and Run

#### PROC-INFRA-001.1-S1: Processing tests pass inside Docker

**GIVEN**
- the `kata-tests` Docker image has been built via `docker build -t kata-tests .`
- Google Test cases for `processField` exist in `tests/`

**WHEN**
- `docker run --rm kata-tests` is executed

**THEN**
- `./runTests` runs inside the container
- all processing tests pass
- the container exits with code `0`

### PROC-INFRA-001.2

**AS A** developer
**I WANT** both the `minesweeper` and `runTests` binaries to be compiled inside the Docker image
**SO THAT** the field processor can be built and tested consistently in a local containerised environment

**Architecture Reference:** Chapter 7 Deployment View - Build and Run, Chapter 2 Constraints - T-1

#### PROC-INFRA-001.2-S1: Binaries compile inside Docker

**GIVEN**
- the `kata-tests` Docker image has been built via `docker build -t kata-tests .`
- the Dockerfile compiles `minesweeper` from all source files and `runTests` from `tests/*.cpp` using `g++ -std=c++17`

**WHEN**
- `docker run --rm kata-tests` is executed

**THEN**
- `./runTests` runs inside the container
- all tests pass
- the container exits with code `0`

---

## PROC-STORY-002

**AS A** developer
**I WANT** the program to compile and run reproducibly as a single C++ binary
**SO THAT** processing logic can be verified consistently

**Architecture Reference:** Chapter 7 Deployment View - Build and Run, Chapter 2 Constraints - T-1

### PROC-STORY-002-S1: Binary compiles with the standard C++17 command

**GIVEN**
- a C++17 compiler is available on the developer machine
- `main.cpp` is present

**WHEN**
- `g++ -std=c++17 -o minesweeper main.cpp` is executed

**THEN**
- the command exits with code `0`
- a single executable `minesweeper` is produced

### PROC-STORY-002-S2: Binary produces correct output for a known input

**GIVEN**
- the `minesweeper` binary has been compiled
- a sample input file with known expected output exists

**WHEN**
- `./minesweeper < input.txt` is executed

**THEN**
- stdout matches the expected annotated output exactly

---

## INFRA Sub-Stories

### PROC-INFRA-002.1

**AS A** developer
**I WANT** the full test suite to run inside Docker and exit cleanly
**SO THAT** end-to-end pipeline correctness is verified in a clean local container environment

**Architecture Reference:** Chapter 7 Deployment View - Build and Run, Chapter 6 Runtime View - Main Processing Scenario

#### PROC-INFRA-002.1-S1: Full test suite passes inside Docker

**GIVEN**
- the `kata-tests` Docker image has been built via `docker build -t kata-tests .`
- Google Test cases covering the full pipeline exist in `tests/`

**WHEN**
- `docker run --rm kata-tests` is executed

**THEN**
- `./runTests` runs inside the container
- all tests pass
- the container exits with code `0`

---

## Traceability Verification

| Scenario ID | Architecture Reference | Parent Story | Testable Assertion |
|---|---|---|---|
| PROC-STORY-001-S1 | Chapter 6 Runtime View - Main Processing Scenario | PROC-STORY-001 | safe interior cell is replaced with the correct adjacent mine count |
| PROC-STORY-001-S2 | Chapter 5 Building Block View - Field Processor | PROC-STORY-001 | mine cell remains `*` |
| PROC-STORY-001-S3 | Chapter 5 Building Block View - Field Processor | PROC-STORY-001 | safe cell with no adjacent mines becomes `0` |
| PROC-FE-001.1-S1 | Chapter 6 Runtime View - Main Processing Scenario | PROC-FE-001.1 | computed value appears in printed output |
| PROC-BE-001.1-S1 | Chapter 5 Building Block View - Field Processor | PROC-BE-001.1 | all valid neighboring positions are checked exactly once |
| PROC-BE-001.2-S1 | Chapter 11 Risks and Technical Debts - R-2 | PROC-BE-001.2 | corner cell uses only valid in-bounds neighbors |
| PROC-BE-001.2-S2 | Chapter 11 Risks and Technical Debts - R-2 | PROC-BE-001.2 | edge cell uses only valid in-bounds neighbors |
| PROC-BE-001.3-S1 | Chapter 5 Building Block View - Field Processor | PROC-BE-001.3 | mine cell bypasses numeric processing |
| PROC-INFRA-001.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | PROC-INFRA-001.1 | `docker run --rm kata-tests` runs `./runTests`; all processing tests pass; exit code 0 |
| PROC-INFRA-001.2-S1 | Chapter 7 Deployment View - Build and Run | PROC-INFRA-001.2 | `docker build -t kata-tests .` compiles both binaries; `docker run --rm kata-tests` exits with code 0 |
| PROC-STORY-002-S1 | Chapter 7 Deployment View - Build and Run | PROC-STORY-002 | binary compiles with standard C++17 command |
| PROC-STORY-002-S2 | Chapter 7 Deployment View - Build and Run | PROC-STORY-002 | binary produces correct output when run with a sample input file |
| PROC-INFRA-002.1-S1 | Chapter 6 Runtime View - Main Processing Scenario | PROC-INFRA-002.1 | `docker run --rm kata-tests` runs `./runTests`; all tests pass; exit code 0 |
