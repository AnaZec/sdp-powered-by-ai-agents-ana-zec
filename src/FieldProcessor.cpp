#include "FieldProcessor.hpp"

Field FieldProcessor::process(const Field& field) {
    Field result = field;
    
    for (int row = 0; row < field.rows; ++row) {
        for (int col = 0; col < field.cols; ++col) {
            if (result.grid[row][col] == '.') {
                int count = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (dr == 0 && dc == 0) continue;
                        int r = row + dr;
                        int c = col + dc;
                        if (r >= 0 && r < field.rows && c >= 0 && c < field.cols) {
                            if (field.grid[r][c] == '*') count++;
                        }
                    }
                }
                if (count > 0) result.grid[row][col] = '0' + count;
            }
        }
    }
    
    return result;
}
