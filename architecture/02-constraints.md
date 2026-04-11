# 2. Architecture Constraints

## 2.1 Technical Constraints

| ID  | Constraint | Rationale |
|-----|-----------|-----------|
| T-1 | Implementation language is C++. | Kata requirement. |
| T-2 | Console application only; no GUI, no web interface. | Kata requirement. |
| T-3 | All processing is in-memory; no database or file system persistence. | Kata requirement. |
| T-4 | Input is read from stdin; output is written to stdout. | Standard kata I/O convention. |

## 2.2 Organizational Constraints

| ID  | Constraint | Rationale |
|-----|-----------|-----------|
| O-1 | The three components (Input Parser, Field Processor, Output Formatter) are the mandated structural decomposition. | Chosen structure per kata design. |

## 2.3 Conventions

| ID  | Constraint | Rationale |
|-----|-----------|-----------|
| C-1 | Input format: each field is preceded by a header line `R C` (rows, columns), followed by R lines of `.` and `*` characters. Input ends with `0 0`. | Minesweeper kata specification. |
| C-2 | Output format: each field is printed as `Field #N:` followed by the annotated grid. Fields are separated by a blank line. | Minesweeper kata specification. |
