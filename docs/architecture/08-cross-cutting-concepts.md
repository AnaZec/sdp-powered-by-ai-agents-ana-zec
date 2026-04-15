# 8. Cross-cutting Concepts

## 8.1 Error Handling

| Scenario | Handling |
|----------|----------|
| Malformed header (non-integer R or C) | Undefined — kata assumes well-formed input. |
| Grid row shorter than declared column count | Undefined — kata assumes well-formed input. |
| Empty stdin | Parser returns empty vector; no output is produced. |

The kata specifies valid input only. No defensive error handling is required beyond graceful termination on `0 0`.

## 8.2 Logging

No logging is required. The application is a batch console tool with no persistent state or operational monitoring needs.

## 8.3 Testability

Each component exposes a pure function interface, making unit testing straightforward without I/O mocking:

| Component | Testable unit |
|-----------|--------------|
| Input Parser | `parseFields(istream&)` — pass a `stringstream` in tests. |
| Field Processor | `processField(Field&)` — pass a `Field` struct directly. |
| Output Formatter | `printField(ostream&, Field, int)` — capture output via `ostringstream`. |

## 8.4 Coding Conventions

- C++17 standard.
- No global mutable state.
- Each component implemented as a free function or a small stateless struct.
