# OUTPUT Domain Stories

## OUTPUT-STORY-001

**AS A** user
**I WANT** each processed field to be printed in the required kata output format
**SO THAT** the result matches the specification exactly

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 2 Constraints - C-2

### OUTPUT-STORY-001-S1: Print a single annotated field with correct header

**GIVEN**
- one annotated `Field` struct exists
- it is the first field in the output sequence

**WHEN**
- the Output Formatter prints the field

**THEN**
- the first line of output is `Field #1:`
- the following lines contain the annotated grid rows exactly

### OUTPUT-STORY-001-S2: Separate consecutive fields with a blank line

**GIVEN**
- two or more annotated fields exist

**WHEN**
- the Output Formatter prints all fields in sequence

**THEN**
- a blank line appears between each pair of consecutive fields
- no trailing blank line appears after the last field

### OUTPUT-STORY-001-S3: Preserve mine positions in output

**GIVEN**
- an annotated field contains cells that were mines (`*`)

**WHEN**
- the Output Formatter prints the field

**THEN**
- every mine cell appears as `*` in the output
- no mine cell is replaced with a numeric value

---

## FE Sub-Stories

### OUTPUT-FE-001.1

**AS A** user
**I WANT** the output to appear on stdout so I can read it or redirect it to a file
**SO THAT** the result is accessible in the standard console way

**Architecture Reference:** Chapter 3 Context and Scope - External Interfaces, Chapter 7 Deployment View - Build and Run

#### OUTPUT-FE-001.1-S1: Write annotated output to stdout

**GIVEN**
- the binary is run with valid minefield input on stdin

**WHEN**
- processing completes

**THEN**
- the annotated fields are written to stdout
- the output can be captured by redirecting stdout to a file

---

## BE Sub-Stories

### OUTPUT-BE-001.1

**AS A** developer
**I WANT** `printField(ostream&, Field, int)` to write the `Field #N:` header and grid rows to the given stream
**SO THAT** the formatter is independently testable without writing to real stdout

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 8 Cross-Cutting Concepts - Testability

#### OUTPUT-BE-001.1-S1: Emit correct header and grid to an ostream

**GIVEN**
- an annotated `Field` with two rows `1*` and `11` is passed as the second field (index 2)

**WHEN**
- `printField` is called with an `ostringstream`, the field, and index `2`

**THEN**
- the stream contains `Field #2:` on the first line
- the next two lines are `1*` and `11`

### OUTPUT-BE-001.2

**AS A** developer
**I WANT** the blank-line separator to be emitted between fields but not after the last one
**SO THAT** the output matches the kata format exactly

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 2 Constraints - C-2

#### OUTPUT-BE-001.2-S1: No trailing blank line after the last field

**GIVEN**
- two fields are printed in sequence

**WHEN**
- both calls to `printField` complete

**THEN**
- exactly one blank line appears between the two field blocks
- the output does not end with a blank line

---

## INFRA Sub-Stories

### OUTPUT-INFRA-001.1

**AS A** developer
**I WANT** formatter unit tests to run automatically
**SO THAT** regressions in output formatting are detected early

**Architecture Reference:** Chapter 8 Cross-Cutting Concepts - Testability, Chapter 7 Deployment View - Build and Run

#### OUTPUT-INFRA-001.1-S1: Run formatter tests via the build system

**GIVEN**
- unit tests for `printField` exist and capture output via `ostringstream`
- the build system is configured to compile and run tests

**WHEN**
- the test target is invoked

**THEN**
- all formatter tests execute without writing to real stdout
- any failing test causes the build to report failure

### OUTPUT-INFRA-001.2

**AS A** developer
**I WANT** end-to-end output to be verifiable by diffing stdout against a known-good file
**SO THAT** the full pipeline can be validated in one command

**Architecture Reference:** Chapter 7 Deployment View - Build and Run, Chapter 6 Runtime View - Main Processing Scenario

#### OUTPUT-INFRA-001.2-S1: Diff binary output against expected output

**GIVEN**
- a known-good expected output file exists
- the binary is compiled

**WHEN**
- `./minesweeper < input.txt | diff - expected.txt` is executed

**THEN**
- the command exits with code `0`
- no differences are reported

---

## OUTPUT-STORY-002

**AS A** user
**I WANT** fields to be numbered as `Field #1`, `Field #2`, and so on
**SO THAT** each output block is clearly identified

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 2 Constraints - C-2

### OUTPUT-STORY-002-S1: First and second fields carry correct numbers

**GIVEN**
- two annotated fields are ready for output

**WHEN**
- the Output Formatter prints both fields

**THEN**
- the first block begins with `Field #1:`
- the second block begins with `Field #2:`

### OUTPUT-STORY-002-S2: Field number increments for each successive field

**GIVEN**
- N annotated fields are ready for output

**WHEN**
- the Output Formatter prints all N fields

**THEN**
- field K begins with `Field #K:` for every K from 1 to N

---

## BE Sub-Stories

### OUTPUT-BE-002.1

**AS A** developer
**I WANT** `printField` to accept a 1-based index and embed it in the `Field #N:` header
**SO THAT** numbering is controlled by the caller and testable in isolation

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 9 Architecture Decisions - ADR-001

#### OUTPUT-BE-002.1-S1: Header contains the supplied index

**GIVEN**
- `printField` is called with an `ostringstream` and index `3`

**WHEN**
- the function writes its output

**THEN**
- the first line of the stream is `Field #3:`

---

## INFRA Sub-Stories

### OUTPUT-INFRA-002.1

**AS A** developer
**I WANT** a unit test that verifies the `Field #N:` label for several index values
**SO THAT** numbering correctness is automatically checked

**Architecture Reference:** Chapter 8 Cross-Cutting Concepts - Testability

#### OUTPUT-INFRA-002.1-S1: Numbering test via ostringstream

**GIVEN**
- `printField` is called with indices `1`, `2`, and `5` in separate test cases

**WHEN**
- each call completes

**THEN**
- the captured output starts with `Field #1:`, `Field #2:`, and `Field #5:` respectively

---

## OUTPUT-STORY-003

**AS A** user
**I WANT** blank lines to separate printed fields correctly
**SO THAT** the output formatting matches the kata requirements

**Architecture Reference:** Chapter 2 Constraints - C-2, Chapter 5 Building Block View - Output Formatter

### OUTPUT-STORY-003-S1: Blank line appears between two consecutive fields

**GIVEN**
- two annotated fields are printed in sequence

**WHEN**
- the Output Formatter prints both fields

**THEN**
- exactly one blank line separates the two field blocks

### OUTPUT-STORY-003-S2: No blank line after the last field

**GIVEN**
- the Output Formatter has printed the final field

**WHEN**
- output is complete

**THEN**
- the output does not end with a blank line

---

## BE Sub-Stories

### OUTPUT-BE-003.1

**AS A** developer
**I WANT** `printField` to emit a blank line before the `Field #N:` header when the index is greater than 1
**SO THAT** separation is handled inside the formatter without extra logic in `main()`

**Architecture Reference:** Chapter 5 Building Block View - Output Formatter, Chapter 9 Architecture Decisions - ADR-001

#### OUTPUT-BE-003.1-S1: Blank line precedes all fields except the first

**GIVEN**
- `printField` is called with index `1` and then with index `2`

**WHEN**
- both calls complete

**THEN**
- the output for index `1` has no leading blank line
- the output for index `2` is preceded by exactly one blank line

---

## INFRA Sub-Stories

### OUTPUT-INFRA-003.1

**AS A** developer
**I WANT** a unit test that captures two consecutive `printField` calls and checks separator placement
**SO THAT** blank-line formatting is automatically verified

**Architecture Reference:** Chapter 8 Cross-Cutting Concepts - Testability

#### OUTPUT-INFRA-003.1-S1: Separator placement test via ostringstream

**GIVEN**
- an `ostringstream` is used to capture output
- `printField` is called twice with indices `1` and `2`

**WHEN**
- both calls complete

**THEN**
- the captured string contains exactly one blank line between the two field blocks
- the captured string does not end with a blank line

---

## Traceability Verification

| Scenario ID | Architecture Reference | Parent Story | Testable Assertion |
|---|---|---|---|
| OUTPUT-STORY-001-S1 | Chapter 5 Building Block View - Output Formatter | OUTPUT-STORY-001 | first field is printed with `Field #1:` header |
| OUTPUT-STORY-001-S2 | Chapter 2 Constraints - C-2 | OUTPUT-STORY-001 | blank line separates consecutive fields; no trailing blank line |
| OUTPUT-STORY-001-S3 | Chapter 5 Building Block View - Output Formatter | OUTPUT-STORY-001 | mine cells appear as `*` in output |
| OUTPUT-FE-001.1-S1 | Chapter 3 Context and Scope - External Interfaces | OUTPUT-FE-001.1 | annotated output is written to stdout and capturable |
| OUTPUT-BE-001.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | OUTPUT-BE-001.1 | `printField` emits correct header and grid rows to ostream |
| OUTPUT-BE-001.2-S1 | Chapter 2 Constraints - C-2 | OUTPUT-BE-001.2 | exactly one blank line between fields, none after last |
| OUTPUT-INFRA-001.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | OUTPUT-INFRA-001.1 | formatter tests run via build system without real stdout |
| OUTPUT-INFRA-001.2-S1 | Chapter 6 Runtime View - Main Processing Scenario | OUTPUT-INFRA-001.2 | binary output matches expected file via diff |
| OUTPUT-STORY-002-S1 | Chapter 5 Building Block View - Output Formatter | OUTPUT-STORY-002 | first field header is `Field #1:`, second is `Field #2:` |
| OUTPUT-STORY-002-S2 | Chapter 2 Constraints - C-2 | OUTPUT-STORY-002 | field index increments by one for each successive field |
| OUTPUT-BE-002.1-S1 | Chapter 5 Building Block View - Output Formatter | OUTPUT-BE-002.1 | `printField` uses the supplied 1-based index in the header |
| OUTPUT-INFRA-002.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | OUTPUT-INFRA-002.1 | ostringstream test confirms correct `Field #N:` label |
| OUTPUT-STORY-003-S1 | Chapter 2 Constraints - C-2 | OUTPUT-STORY-003 | blank line appears between field blocks |
| OUTPUT-STORY-003-S2 | Chapter 2 Constraints - C-2 | OUTPUT-STORY-003 | no blank line after the final field |
| OUTPUT-BE-003.1-S1 | Chapter 5 Building Block View - Output Formatter | OUTPUT-BE-003.1 | blank line emitted before field block when index > 1 |
| OUTPUT-INFRA-003.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | OUTPUT-INFRA-003.1 | ostringstream test confirms separator placement |
