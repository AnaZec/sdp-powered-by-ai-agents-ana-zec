# User Stories

## Domains

The following domains are derived from the bounded contexts identified in the Module 2 architecture:

- **INPUT** — Input Parser: reads standard input, parses minefield dimensions and rows, groups them into `Field` structures, and stops processing when `0 0` is encountered
- **PROC** — Field Processor: computes the number of adjacent mines for every safe cell in a field
- **OUTPUT** — Output Formatter: prints annotated fields to standard output using the required `Field #N:` headers and blank-line separators

These domains directly map to the bounded contexts defined in the Building Block View (Chapter 5) and are used as the basis for story IDs and traceability.

## Prioritized Story Inventory

### Core Stories (Pareto 20%)

- `INPUT-STORY-001`
  **AS A** user
  **I WANT** the program to parse one or more minefields from standard input
  **SO THAT** each field can be processed correctly

- `PROC-STORY-001`
  **AS A** user
  **I WANT** every safe cell to be replaced with the correct adjacent mine count
  **SO THAT** the annotated minefield is correct

- `OUTPUT-STORY-001`
  **AS A** user
  **I WANT** each processed field to be printed in the required kata output format
  **SO THAT** the result matches the specification exactly

### Supporting Stories (Remaining 80%)

- `INPUT-STORY-002`
  **AS A** user
  **I WANT** input processing to stop when `0 0` is encountered
  **SO THAT** the program terminates according to the kata rules

- `INPUT-STORY-003`
  **AS A** user
  **I WANT** multiple fields to be read sequentially from one input stream
  **SO THAT** all provided minefields are processed in one run

- `OUTPUT-STORY-002`
  **AS A** user
  **I WANT** fields to be numbered as `Field #1`, `Field #2`, and so on
  **SO THAT** each output block is clearly identified

- `OUTPUT-STORY-003`
  **AS A** user
  **I WANT** blank lines to separate printed fields correctly
  **SO THAT** the output formatting matches the kata requirements

- `PROC-INFRA-001`
  **AS A** developer
  **I WANT** the program to compile and run reproducibly as a single C++ binary
  **SO THAT** processing logic can be verified consistently

## Pareto Prioritization

The core stories represent the minimal viable functionality required for the Minesweeper Field Processor kata. They are prioritized because they deliver the highest user value and directly exercise the three most important architecture components: input parsing, field processing, and output formatting.

## Progress Tracking

📊 Pareto Progress: 0/3 core stories (0%)
🎯 Core functionality coverage: ~0% of 80% target
