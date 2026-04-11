# 5. Building Block View

## 5.1 Container Diagram

```plantuml
@startuml c4-container
!include https://raw.githubusercontent.com/plantuml-stdlib/C4-PlantUML/master/C4_Container.puml

Person(user, "User", "Runs the application")
System_Boundary(systemBoundary, "Minesweeper Field Processor") {
  Container(parser, "Input Parser", "C++ module", "Reads stdin and parses fields into structured data")
  Container(processor, "Field Processor", "C++ module", "Computes adjacent mine counts for each cell")
  Container(formatter, "Output Formatter", "C++ module", "Formats and prints annotated fields to stdout")
}

Rel(user, parser, "Provides input via", "stdin")
Rel(parser, processor, "Passes parsed fields to")
Rel(processor, formatter, "Passes annotated fields to")
Rel(formatter, user, "Prints output via", "stdout")

@enduml
```

## 5.2 Component Descriptions

| Component | Responsibility |
|-----------|---------------|
| Input Parser | Reads lines from stdin, groups them into `Field` structs (dimensions + grid rows), stops on `0 0`. |
| Field Processor | For each field, replaces each `.` cell with the count of adjacent `*` cells (8-directional). |
| Output Formatter | Prints `Field #N:` header followed by the annotated grid; separates fields with a blank line. |

## 5.3 Data Structure

The single shared data structure passed between components:

```cpp
struct Field {
    int rows, cols;
    vector<string> grid; // rows x cols, cells are '.' or '*'
};
```

## 5.4 Component Diagram

```plantuml
@startuml c4-component
!include https://raw.githubusercontent.com/plantuml-stdlib/C4-PlantUML/master/C4_Component.puml

Container_Boundary(app, "Minesweeper Field Processor") {
  Component(parser, "Input Parser", "parseFields()", "Reads stdin, returns vector<Field>")
  Component(processor, "Field Processor", "processField()", "Annotates a single Field in-place")
  Component(formatter, "Output Formatter", "printField()", "Prints a single annotated Field to stdout")
  Component(main, "Main", "main()", "Orchestrates the pipeline")
}

Rel(main, parser, "Calls")
Rel(main, processor, "Calls for each field")
Rel(main, formatter, "Calls for each field")

@enduml
```
