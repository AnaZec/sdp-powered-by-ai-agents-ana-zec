# 11. Risks and Technical Debts

## 11.1 Risks

| ID  | Risk | Likelihood | Impact | Mitigation |
|-----|------|-----------|--------|------------|
| R-1 | Malformed input causes undefined behaviour (e.g. grid row shorter than declared column count). | Low | Medium | Kata assumes well-formed input; acceptable for this scope. |
| R-2 | Off-by-one errors in 8-directional neighbour bounds checking. | Medium | High | Cover boundary cells (corners, edges) explicitly in unit tests. |

## 11.2 Technical Debts

| ID  | Debt | Impact | Resolution |
|-----|------|--------|------------|
| D-1 | No input validation. | Low — kata guarantees valid input. | Add validation if the system is ever extended beyond the kata. |
| D-2 | In-place grid mutation in Field Processor. | Low — original grid is not needed after processing. | Use a separate output grid if immutability becomes a requirement. |
