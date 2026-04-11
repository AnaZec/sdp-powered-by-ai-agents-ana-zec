# 7. Deployment View

## 7.1 Overview

The Minesweeper Field Processor is a single compiled binary. There is no deployment infrastructure — the user compiles and runs it locally.

## 7.2 Deployment Diagram

```plantuml
@startuml deployment
!include https://raw.githubusercontent.com/plantuml-stdlib/C4-PlantUML/master/C4_Container.puml

Node(machine, "Developer Machine", "Linux / macOS / Windows") {
  Container(binary, "minesweeper", "C++ executable", "Compiled binary, reads stdin, writes stdout")
}

Person(user, "User", "Runs the binary")
Rel(user, binary, "Executes", "CLI / pipe")

@enduml
```

## 7.3 Build and Run

| Step | Command |
|------|---------|
| Compile | `g++ -std=c++17 -o minesweeper main.cpp` |
| Run with file | `./minesweeper < input.txt` |
| Run interactive | `./minesweeper` (type input manually) |

No external dependencies, libraries, or runtime environment beyond a standard C++17 compiler.
