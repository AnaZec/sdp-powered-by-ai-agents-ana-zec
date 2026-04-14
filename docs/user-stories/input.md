# INPUT Domain Stories

## INPUT-STORY-001

**AS A** user
**I WANT** the program to parse one or more minefields from standard input
**SO THAT** each field can be processed correctly

**Architecture Reference:** Chapter 3 Context and Scope - External Interfaces, Chapter 5 Building Block View - Input Parser

### INPUT-STORY-001-S1: Parse a single well-formed field

**GIVEN**
- stdin contains a header line `R C` followed by R lines of `.` and `*` characters
- the input is terminated by `0 0`

**WHEN**
- the Input Parser reads stdin

**THEN**
- exactly one `Field` struct is returned
- the struct contains the correct row count, column count, and grid rows

### INPUT-STORY-001-S2: Parse multiple fields in sequence

**GIVEN**
- stdin contains two or more fields, each preceded by its own `R C` header
- the sequence is terminated by `0 0`

**WHEN**
- the Input Parser reads stdin

**THEN**
- one `Field` struct is returned per field in the input
- each struct contains the correct dimensions and grid for its respective field

### INPUT-STORY-001-S3: Return empty result for terminator-only input

**GIVEN**
- stdin contains only the line `0 0`

**WHEN**
- the Input Parser reads stdin

**THEN**
- an empty collection of fields is returned
- no output is produced by the application

---

## FE Sub-Stories

### INPUT-FE-001.1

**AS A** user
**I WANT** the program to accept input piped from a file or typed interactively
**SO THAT** I can supply minefields in the standard way for a console application

**Architecture Reference:** Chapter 3 Context and Scope - External Interfaces, Chapter 7 Deployment View - Build and Run

#### INPUT-FE-001.1-S1: Accept piped file input

**GIVEN**
- a text file containing valid minefield input exists on the developer machine

**WHEN**
- the binary is launched with the file redirected to stdin (`./minesweeper < input.txt`)

**THEN**
- the program reads all fields from the file
- annotated output is written to stdout

---

## BE Sub-Stories

### INPUT-BE-001.1

**AS A** developer
**I WANT** `parseFields(istream&)` to read and group header and grid lines into `Field` structs
**SO THAT** downstream components receive a well-defined data structure

**Architecture Reference:** Chapter 5 Building Block View - Input Parser, Chapter 8 Cross-Cutting Concepts - Testability

#### INPUT-BE-001.1-S1: Produce a correctly populated Field struct

**GIVEN**
- an `istream` containing a header `4 4` followed by four grid rows

**WHEN**
- `parseFields` is called with that stream

**THEN**
- the returned vector contains one `Field`
- `Field.rows` equals `4`, `Field.cols` equals `4`
- `Field.grid` contains exactly four strings matching the input rows

### INPUT-BE-001.2

**AS A** developer
**I WANT** the parser to stop reading when it encounters `0 0`
**SO THAT** the pipeline terminates correctly per the kata specification

**Architecture Reference:** Chapter 5 Building Block View - Input Parser, Chapter 6 Runtime View - Edge Case: Empty Input

#### INPUT-BE-001.2-S1: Stop on terminator line

**GIVEN**
- an `istream` containing one valid field followed by `0 0`

**WHEN**
- `parseFields` is called

**THEN**
- only the fields before `0 0` are returned
- the terminator line does not appear as a field or grid row

---

## INFRA Sub-Stories

### INPUT-INFRA-001.1

**AS A** developer
**I WANT** parser unit tests to run automatically
**SO THAT** regressions in input parsing are detected early

**Architecture Reference:** Chapter 8 Cross-Cutting Concepts - Testability, Chapter 7 Deployment View - Build and Run

#### INPUT-INFRA-001.1-S1: Run parser tests via the build system

**GIVEN**
- unit tests for `parseFields` exist and use a `stringstream` as input
- the build system is configured to compile and run tests

**WHEN**
- the test target is invoked

**THEN**
- all parser tests execute without requiring real stdin
- any failing test causes the build to report failure

### INPUT-INFRA-001.2

**AS A** developer
**I WANT** the application to compile to a single binary with a standard C++17 command
**SO THAT** the input parsing component is always built and runnable in the same way

**Architecture Reference:** Chapter 7 Deployment View - Build and Run

#### INPUT-INFRA-001.2-S1: Compile and run the binary

**GIVEN**
- a C++17 compiler is available on the developer machine
- the source file `main.cpp` is present

**WHEN**
- `g++ -std=c++17 -o minesweeper main.cpp` is executed

**THEN**
- a single executable `minesweeper` is produced with no errors
- running `./minesweeper < input.txt` produces annotated output on stdout

---

## INPUT-STORY-002

**AS A** user
**I WANT** input processing to stop when `0 0` is encountered
**SO THAT** the program terminates according to the kata rules

**Architecture Reference:** Chapter 5 Building Block View - Input Parser, Chapter 1 Introduction and Goals - F-4

### INPUT-STORY-002-S1: Halt after reading the terminator

**GIVEN**
- stdin contains one or more valid fields followed by the line `0 0`

**WHEN**
- the Input Parser reads stdin

**THEN**
- parsing stops at `0 0`
- only the fields read before the terminator are returned

### INPUT-STORY-002-S2: Produce no output when terminator is the only input

**GIVEN**
- stdin contains only `0 0`

**WHEN**
- the full pipeline runs

**THEN**
- the parser returns an empty collection
- nothing is written to stdout

---

## BE Sub-Stories

### INPUT-BE-002.1

**AS A** developer
**I WANT** the parser loop to exit as soon as it reads a header of `0 0`
**SO THAT** no further lines are consumed after the terminator

**Architecture Reference:** Chapter 5 Building Block View - Input Parser, Chapter 6 Runtime View - Edge Case: Empty Input

#### INPUT-BE-002.1-S1: Exit loop on zero-dimension header

**GIVEN**
- an `istream` whose next header line is `0 0`

**WHEN**
- `parseFields` reads that header

**THEN**
- the parsing loop exits immediately
- no grid rows are read for that header
- the returned vector contains only previously parsed fields

---

## INFRA Sub-Stories

### INPUT-INFRA-002.1

**AS A** developer
**I WANT** a unit test that verifies terminator handling using a `stringstream`
**SO THAT** the stop-on-`0 0` behaviour is automatically verified

**Architecture Reference:** Chapter 8 Cross-Cutting Concepts - Testability

#### INPUT-INFRA-002.1-S1: Terminator test via stringstream

**GIVEN**
- a `stringstream` containing `"0 0\n"` is prepared

**WHEN**
- `parseFields` is called with that stream

**THEN**
- the returned vector is empty
- the test passes without any real stdin interaction

---

## INPUT-STORY-003

**AS A** user
**I WANT** multiple fields to be read sequentially from one input stream
**SO THAT** all provided minefields are processed in one run

**Architecture Reference:** Chapter 5 Building Block View - Input Parser, Chapter 6 Runtime View - Main Processing Scenario

### INPUT-STORY-003-S1: All fields are parsed from a single stream

**GIVEN**
- stdin contains three fields, each with its own `R C` header and grid rows
- the stream ends with `0 0`

**WHEN**
- the Input Parser reads stdin

**THEN**
- three `Field` structs are returned
- they appear in the same order as in the input

### INPUT-STORY-003-S2: Each output block corresponds to the correct input field

**GIVEN**
- stdin contains two fields with different dimensions and mine layouts

**WHEN**
- the full pipeline runs

**THEN**
- the first output block reflects the first input field
- the second output block reflects the second input field

---

## BE Sub-Stories

### INPUT-BE-003.1

**AS A** developer
**I WANT** `parseFields` to accumulate all fields into a vector before returning
**SO THAT** `main()` can iterate over them in order

**Architecture Reference:** Chapter 5 Building Block View - Input Parser, Chapter 9 Architecture Decisions - ADR-001

#### INPUT-BE-003.1-S1: Return all fields in input order

**GIVEN**
- an `istream` containing two fields followed by `0 0`

**WHEN**
- `parseFields` is called

**THEN**
- the returned vector has exactly two elements
- element 0 matches the first field, element 1 matches the second field

---

## INFRA Sub-Stories

### INPUT-INFRA-003.1

**AS A** developer
**I WANT** a unit test that supplies multiple fields via a `stringstream`
**SO THAT** sequential parsing is automatically verified

**Architecture Reference:** Chapter 8 Cross-Cutting Concepts - Testability

#### INPUT-INFRA-003.1-S1: Multi-field stringstream test

**GIVEN**
- a `stringstream` containing two valid fields followed by `0 0`

**WHEN**
- `parseFields` is called with that stream

**THEN**
- the returned vector contains exactly two `Field` structs
- each struct has the dimensions and grid matching its respective input block

---

## Traceability Verification

| Scenario ID | Architecture Reference | Parent Story | Testable Assertion |
|---|---|---|---|
| INPUT-STORY-001-S1 | Chapter 5 Building Block View - Input Parser | INPUT-STORY-001 | single field parsed into correct Field struct |
| INPUT-STORY-001-S2 | Chapter 5 Building Block View - Input Parser | INPUT-STORY-001 | multiple fields each produce a correct Field struct |
| INPUT-STORY-001-S3 | Chapter 6 Runtime View - Edge Case: Empty Input | INPUT-STORY-001 | terminator-only input returns empty collection |
| INPUT-FE-001.1-S1 | Chapter 7 Deployment View - Build and Run | INPUT-FE-001.1 | binary accepts piped file and writes output to stdout |
| INPUT-BE-001.1-S1 | Chapter 5 Building Block View - Input Parser | INPUT-BE-001.1 | Field struct has correct rows, cols, and grid |
| INPUT-BE-001.2-S1 | Chapter 6 Runtime View - Edge Case: Empty Input | INPUT-BE-001.2 | parser stops at `0 0` and excludes terminator from results |
| INPUT-INFRA-001.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | INPUT-INFRA-001.1 | parser tests run via build system without real stdin |
| INPUT-INFRA-001.2-S1 | Chapter 7 Deployment View - Build and Run | INPUT-INFRA-001.2 | single binary compiles and runs with stdin redirection |
| INPUT-STORY-002-S1 | Chapter 5 Building Block View - Input Parser | INPUT-STORY-002 | parser halts and returns only fields read before `0 0` |
| INPUT-STORY-002-S2 | Chapter 6 Runtime View - Edge Case: Empty Input | INPUT-STORY-002 | `0 0` as first line yields empty result and no output |
| INPUT-BE-002.1-S1 | Chapter 5 Building Block View - Input Parser | INPUT-BE-002.1 | loop exits immediately when header row equals `0 0` |
| INPUT-INFRA-002.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | INPUT-INFRA-002.1 | terminator test passes using stringstream with `0 0` |
| INPUT-STORY-003-S1 | Chapter 5 Building Block View - Input Parser | INPUT-STORY-003 | all fields in a multi-field stream are returned in order |
| INPUT-STORY-003-S2 | Chapter 6 Runtime View - Main Processing Scenario | INPUT-STORY-003 | each output field corresponds to the correct input field |
| INPUT-BE-003.1-S1 | Chapter 5 Building Block View - Input Parser | INPUT-BE-003.1 | vector contains one Field per input field in correct order |
| INPUT-INFRA-003.1-S1 | Chapter 8 Cross-Cutting Concepts - Testability | INPUT-INFRA-003.1 | multi-field stringstream test returns correct field count |
