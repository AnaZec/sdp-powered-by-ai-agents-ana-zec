# 12. Glossary

| Term | Definition |
|------|-----------|
| Field | A single minesweeper grid, consisting of a header (row and column counts) and a 2D grid of cells. |
| Cell | A single position in the grid, containing either a mine (`*`) or a safe square (`.`). |
| Mine | A cell marked with `*`. |
| Safe cell | A cell marked with `.`, replaced in output by its adjacent mine count. |
| Adjacent mine count | The number of mines in the 8 neighbouring cells (horizontal, vertical, diagonal) of a given cell. |
| Header | The line preceding a field's grid rows, formatted as `R C` where R = row count and C = column count. |
| Terminator | The input line `0 0` signalling end of input. |
| Input Parser | The component responsible for reading stdin and producing a list of `Field` structs. |
| Field Processor | The component responsible for computing adjacent mine counts for all safe cells in a field. |
| Output Formatter | The component responsible for printing annotated fields to stdout in the required format. |
| Pipeline | The sequential flow: Input Parser → Field Processor → Output Formatter. |
