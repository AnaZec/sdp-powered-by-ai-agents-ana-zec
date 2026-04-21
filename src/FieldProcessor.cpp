#include "FieldProcessor.hpp"

Field FieldProcessor::process(const Field& field) {
    Field result = field;
    for (int r = 0; r < field.rows; r++) {
        for (int c = 0; c < field.cols; c++) {
            if (field.grid[r][c] == '.') {
                int count = 0;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0) continue;
                        int nr = r + dr;
                        int nc = c + dc;
                        if (nr >= 0 && nr < field.rows && nc >= 0 && nc < field.cols) {
                            if (field.grid[nr][nc] == '*') count++;
                        }
                    }
                }
                result.grid[r][c] = '0' + count;
            }
        }
    }
    return result;
}
