# 6. Runtime View

## 6.1 Main Processing Scenario

The primary runtime scenario: user pipes a file with multiple fields into the application.

```plantuml
@startuml runtime-main
actor User
participant "main()" as Main
participant "Input Parser" as Parser
participant "Field Processor" as Processor
participant "Output Formatter" as Formatter

User -> Main : launch with stdin
Main -> Parser : parseFields(stdin)
loop for each field until "0 0"
  Parser -> Parser : read header (R C)
  Parser -> Parser : read R grid rows
end
Parser --> Main : vector<Field>

loop for each Field
  Main -> Processor : processField(field)
  Processor -> Processor : for each '.' cell, count adjacent '*'
  Processor --> Main : annotated Field

  Main -> Formatter : printField(field, index)
  Formatter -> User : print "Field #N:" + grid to stdout
end

@enduml
```

## 6.2 Edge Case: Empty Input

If stdin contains only `0 0`, the parser returns an empty vector and no output is produced.

```plantuml
@startuml runtime-empty
actor User
participant "main()" as Main
participant "Input Parser" as Parser

User -> Main : launch with "0 0" on stdin
Main -> Parser : parseFields(stdin)
Parser -> Parser : read header "0 0" → stop
Parser --> Main : empty vector<Field>
Main -> User : (no output)

@enduml
```
