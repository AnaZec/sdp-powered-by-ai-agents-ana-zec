# Minesweeper Field Processor — Documentation

This repository provides the official documentation for the **Minesweeper Field Processor kata**, generated using Sphinx.

The documentation is designed to ensure **clarity, traceability, and reproducibility** across all stages of development — from requirements definition through implementation and validation.

---

## 📚 Scope of Documentation

The documentation reflects both the **system architecture** and the **development process**, including:

* **System Overview** — project context and usage guidelines
* **Architecture (arc42)** — complete system design, constraints, and runtime behavior
* **User Stories** — formally defined requirements with traceable scenarios

All user stories follow a layered implementation strategy:

> **INFRA → Backend → Frontend → End-to-End (E2E)**

---

## 🗂️ Documentation Structure

| Section          | Purpose                                                     |
| ---------------- | ----------------------------------------------------------- |
| **Overview**     | Introduction and high-level system description              |
| **Architecture** | arc42-based system design (structure, behavior, deployment) |
| **User Stories** | Requirements specification and scenario definitions         |

---

## ⚙️ Local Setup

### Prerequisites

* Python ≥ 3.10

---

### Install Dependencies

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r docs/requirements.txt
```

---

### Build Documentation

```bash
cd docs
make html
```

---

### Preview Documentation

Open the generated site:

```bash
docs/_build/html/index.html
```

Or serve it locally:

```bash
python -m http.server -d docs/_build/html 8000
```

Then navigate to:

```
http://localhost:8000
```

---

## 🐳 Execution Environment

The application is fully containerized to ensure a **consistent and reproducible runtime environment**.

### Build and Run

```bash
docker build -t kata-tests .
docker run --rm -i kata-tests ./minesweeper <<EOF
4 4
*...
....
.*..
....
0 0
EOF
```

This enables execution with input provided via standard input.

This approach guarantees:

* Environment isolation
* Platform-independent execution
* Validation of infrastructure-level requirements

---

## 🧪 Testing Strategy

Testing is performed within the containerized environment:

```bash
docker build -t kata-tests .
docker run --rm kata-tests
```

> Note: Adjust the execution command if a specific test runner (e.g., `ctest`) is configured.

---

## 🚀 Continuous Deployment

The documentation site is automatically built and deployed using **GitHub Actions**.

### Setup

```bash
mkdir -p .github/workflows
mv docs/docs-deploy.yml .github/workflows/docs-deploy.yml
```

Then:

* Navigate to **Settings → Pages**
* Set **Source** to **GitHub Actions**

---

### Published Site

After pushing to the `main` branch, the documentation will be available at:

```
https://anazec.github.io/sdp-powered-by-ai-agents-ana-zec/
```

---

## 🧠 Development Methodology

This project follows a structured **Test-Driven Development (TDD)** and **Behavior-Driven Development (BDD)** approach:

* Requirements are defined using **GIVEN–WHEN–THEN** scenarios
* Implementation progresses through layered validation:

  * Infrastructure
  * Backend
  * Frontend
  * End-to-End behavior
* Code evolution follows the **RED → GREEN → REFACTOR** cycle

This methodology ensures:

* Clear separation of concerns
* High test coverage
* Strong alignment between requirements and implementation

---

## 👩‍💻 Author

Ana Zec
M.Sc. Student, Automotive Software
