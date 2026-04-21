#include "FieldProcessor.hpp"

Field FieldProcessor::process(const Field& field) {
    Field result = field;
    for (int r = 0; r < field.rows; r++) {
        for (int c = 0; c < field.cols; c++) {
            if (field.grid[r][c] == '.') {
                result.grid[r][c] = '0';
            }
        }
    }
    return result;
}
