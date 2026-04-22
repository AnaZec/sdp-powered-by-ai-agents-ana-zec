---

# Minesweeper Field Processor

A modular, containerized implementation of the **Minesweeper Kata**, developed within a master's-level **Software Development Processes** course focused on **AI-assisted software engineering**.

This project demonstrates how structured development processes—such as requirements engineering, architecture design, CI/CD, and TDD—can be **formalized and partially automated using AI agents**, while still ensuring correctness through testing and validation.

---

## 📌 Overview

The goal of this project is twofold:

1. **Solve the Minesweeper Kata** as a clean, testable, and modular system
2. **Demonstrate a full software development lifecycle**, supported by AI agents and engineering best practices

Rather than treating the kata as a simple algorithmic problem, it is modeled as a **data-processing pipeline**, enabling:

* clear separation of concerns
* traceability from requirements to implementation
* systematic test coverage
* extensibility and maintainability

---

## 🎯 Problem Definition

The Minesweeper Kata is a classic grid-processing problem:

* **Input:** A rectangular grid where:

  * `*` represents a mine
  * `.` represents an empty cell

* **Output:** A transformed grid where:

  * Mines remain `*`
  * Each empty cell contains the number of adjacent mines (0–8)

### Example

**Input**

```
*...
....
.*..
....
```

**Output**

```
*1..
221.
1*1.
111.
```

---

## 🏗️ System Architecture

The system is designed using a **layered architecture**, aligned with the arc42 methodology:

### 🔹 Input Layer

* Parses raw input stream
* Validates format and constraints
* Converts input into internal data structures

### 🔹 Processing Layer

* Core domain logic
* Computes adjacency counts for each cell
* Independent of I/O and formatting

### 🔹 Output Layer

* Transforms processed data into required textual format
* Handles presentation and formatting concerns

This separation ensures:

* high testability
* clear responsibility boundaries
* maintainability and extensibility

📖 Full architectural documentation is available in the Sphinx docs (arc42).

---

## 🤖 AI-Agent Driven Development

A key aspect of this project is the use of **custom AI agents** to support the development lifecycle.

### Implemented Agents

* **Git Agent**
  Automates issue creation, branching strategy, and pull requests

* **Architecture Agent**
  Generates system architecture based on the arc42 template
  Defines:
    * system structure and decomposition
    * component responsibilities
    * architectural decisions and constraints

* **Requirements Agent**
  Derives structured user stories from architecture documentation
  Includes:

  * GIVEN–WHEN–THEN scenarios
  * Pareto prioritization
  * DDD building blocks

* **TDD/BDD Agent**
  Enforces strict development discipline:

  * Writes one test at a time
  * Confirms RED → GREEN cycles
  * Ensures regression safety

* **CI/CD Agent**
  Automates:

  * builds
  * test execution
  * documentation deployment

### Development Workflow

The system follows a strict progression:

```
INFRA → BE → FE → E2E
```

Combined with:

```
RED → GREEN → REFACTOR
```

This ensures:

* correctness before complexity
* incremental delivery
* traceable evolution of the system

---

## 🛠️ Technology Stack

| Category         | Technology       |
| ---------------- | ---------------- |
| Language         | C++              |
| Containerization | Docker           |
| Documentation    | Sphinx           |
| CI/CD            | GitHub Actions   |
| Architecture     | arc42 + C4 model |

---

## 🐳 Build and Run

### Build the container

```bash
docker build -t minesweeper-kata .
```

### Run the application

```bash
docker run --rm -i minesweeper-kata ./minesweeper <<EOF
4 4
*...
....
.*..
....
0 0
EOF
```

---

## 🧪 Running Tests

All tests are executed inside the Docker container:

```bash
docker build -t minesweeper-kata .
docker run --rm minesweeper-kata
```

The test suite includes:

* INFRA-level validation tests
* Backend logic tests
* Integration tests
* End-to-end (E2E) scenarios

---

## 📚 Documentation

📖 **Live Documentation:**
[https://anazec.github.io/sdp-powered-by-ai-agents-ana-zec/](https://anazec.github.io/sdp-powered-by-ai-agents-ana-zec/)

The documentation includes:

* arc42 architecture (all chapters)
* C4 diagrams (system context, containers)
* User stories and scenarios
* Design decisions and trade-offs
* Development process and agent behavior

---

## 📂 Project Structure

```
.
├── src/                # Core implementation
├── tests/              # Test suite (INFRA → BE → FE → E2E)
├── docs/               # architecture, user-stories, Sphinx documentation
├── .github/workflows/  # CI/CD pipelines
├── Dockerfile          # Container definition
└── README.md
```

---

## 🎓 Course Progress

This project is developed incrementally through course modules:

* ✅ **Module 1 — Git**
  Workflow automation via Git agent

* ✅ **Module 2 — Architecture**
  arc42-based system design

* ✅ **Module 3 — Requirements**
  AI-assisted user story generation

* ✅ **Module 4 — CI/CD**
  Automated pipelines and deployment

* ✅ **Module 5 — TDD/BDD**
  Multi-agent test-driven development system

* ✅ **Module 6 — Integration Project**
  End-to-end system combining all agents

---

## 🚀 Key Engineering Takeaways

* TDD is used as a **design tool**, not just testing
* Architecture and requirements are **first-class artifacts**
* AI agents can **augment but not replace engineering discipline**
* Strong separation of concerns leads to **testable and maintainable systems**

---

## 👩‍💻 Author

**Ana Zec**
M.Sc. Student, Automotive Software Engineering
