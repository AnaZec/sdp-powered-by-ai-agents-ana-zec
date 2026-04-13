# User Stories

## Domains

The following domains are derived from the bounded contexts identified in the architecture:

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

- `PROC-STORY-002`
  **AS A** developer
  **I WANT** the program to compile and run reproducibly as a single C++ binary
  **SO THAT** processing logic can be verified consistently

## Pareto Prioritization

The three core stories represent the minimal viable functionality of the Minesweeper Field Processor kata. They are chosen because:

1. `INPUT-STORY-001` — without parsing, no field can enter the pipeline; it unblocks every other story
2. `PROC-STORY-001` — the central computation; directly delivers the user-visible value of the kata
3. `OUTPUT-STORY-001` — without formatted output, no result is observable; closes the pipeline end-to-end

Together they exercise all three architecture components (Input Parser, Field Processor, Output Formatter) and the full pipeline runtime flow described in Chapter 6. All supporting stories are refinements or edge cases of these three.

## Progress Tracking

📊 Pareto Progress: 3/3 core stories (100%)
🎯 Core functionality coverage: ~80% of 80% target

| Story Bundle | Status |
|---|---|
| `PROC-STORY-001` | ✅ Approved |
| `INPUT-STORY-001` | ✅ Approved |
| `OUTPUT-STORY-001` | ✅ Approved |
| `INPUT-STORY-002` | ✅ Approved |
| `INPUT-STORY-003` | ✅ Approved |
| `OUTPUT-STORY-002` | ✅ Approved |
| `OUTPUT-STORY-003` | ✅ Approved |
| `PROC-STORY-002` | ✅ Approved |
