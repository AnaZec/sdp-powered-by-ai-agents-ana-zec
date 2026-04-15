# 1. Introduction and Goals

## 1.1 Purpose

The Minesweeper Field Processor is a console application that reads one or more minesweeper fields from standard input, computes the number of adjacent mines for each safe cell, and prints the annotated fields to standard output.

## 1.2 Functional Requirements

| ID  | Requirement |
|-----|-------------|
| F-1 | Read multiple minesweeper fields from stdin, separated by a header line containing row and column counts. |
| F-2 | For each cell that is not a mine (`.`), compute the count of adjacent mines (8-directional). |
| F-3 | Print each annotated field to stdout, preserving mine positions (`*`) and replacing safe cells with their adjacent mine count. |
| F-4 | A field with dimensions `0 0` signals end of input. |

## 1.3 Quality Goals

| Priority | Quality Goal | Motivation |
|----------|-------------|------------|
| 1 | Correctness | Output must exactly match the expected minesweeper format. |
| 2 | Simplicity | The kata is small; the design must stay proportional. |
| 3 | Testability | Each processing step (parse, compute, format) must be independently testable. |

## 1.4 Stakeholders

| Role | Expectation |
|------|-------------|
| Developer | Clear separation of parsing, processing, and formatting logic. |
| Reviewer | Readable, maintainable C++ code with a clean pipeline structure. |
