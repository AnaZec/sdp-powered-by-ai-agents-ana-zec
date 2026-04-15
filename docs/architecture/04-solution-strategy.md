# 4. Solution Strategy

## 4.1 Approach

The system is structured as a linear pipeline of three components, each with a single responsibility:

```
stdin → Input Parser → Field Processor → Output Formatter → stdout
```

Each stage operates on a well-defined data structure, making the pipeline easy to test and reason about independently.

## 4.2 Key Decisions

| Decision | Choice | Rationale |
|----------|--------|-----------|
| Structure | Three-component pipeline | Matches the chosen decomposition; separates concerns cleanly. |
| Data representation | `vector<string>` per field | Simple, sufficient for in-memory grid manipulation in C++. |
| Processing | Synchronous, sequential | Single-threaded console app; no concurrency needed. |
| I/O | stdin / stdout | Kata convention; no file or network I/O required. |

## 4.3 Component Responsibilities

- **Input Parser**: reads raw lines from stdin, groups them into fields (header + grid rows), stops on `0 0`.
- **Field Processor**: for each field, iterates every cell and counts adjacent mines using 8-directional neighbour checks.
- **Output Formatter**: prints each annotated field with the `Field #N:` header and blank-line separator.
