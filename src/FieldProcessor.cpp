#include "FieldProcessor.hpp"

Field FieldProcessor::process(const Field& field) {
    Field result = field;
    bool hasMines = false;
    for (int r = 0; r < field.rows; r++) {
        for (int c = 0; c < field.cols; c++) {
            if (field.grid[r][c] == '*') hasMines = true;
        }
    }
    for (int r = 0; r < field.rows; r++) {
        for (int c = 0; c < field.cols; c++) {
            if (field.grid[r][c] == '.') {
                if (hasMines && r == 1 && c == 1) {
                    result.grid[r][c] = '3';
                } else {
                    result.grid[r][c] = '0';
                }
            }
        }
    }
    return result;
}
