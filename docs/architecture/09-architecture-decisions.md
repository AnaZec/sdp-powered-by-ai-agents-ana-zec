# 09. Architecture Decisions

## ADR-001: Three-Component Pipeline Structure

### Status
Accepted

### Context
The system needs to read, process, and output minesweeper fields. A clear decomposition strategy is needed.

### Decision
Split the application into three components: Input Parser, Field Processor, and Output Formatter, orchestrated by `main()`.

### Rationale
Each component has a single responsibility. The pipeline structure makes data flow explicit and each stage independently testable.

### Consequences
- (+) Clean separation of concerns.
- (+) Each component can be tested in isolation.
- (-) Slight overhead of passing data structures between stages, negligible at this scale.

---

## ADR-002: `vector<string>` as Grid Representation

### Status
Accepted

### Context
The field grid needs an in-memory representation that supports row/column indexing for neighbour lookups.

### Decision
Represent each field's grid as a `vector<string>`, where each string is one row.

### Rationale
Simple, idiomatic C++. Character access via `grid[r][c]` is direct. No custom data structure needed for this problem size.

### Consequences
- (+) Minimal code, easy to read and manipulate.
- (-) Mutates the grid in-place during processing; a copy would be needed if the original must be preserved (not required here).

---

## ADR-003: Synchronous Single-Threaded Execution

### Status
Accepted

### Context
Multiple fields must be processed sequentially.

### Decision
Process all fields in a single thread, sequentially.

### Rationale
The problem size is small and bounded. Concurrency would add complexity with no benefit.

### Consequences
- (+) Simple, deterministic execution.
- (-) Not scalable to very large inputs, which is outside the kata scope.
