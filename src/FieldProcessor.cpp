#include "FieldProcessor.hpp"

Field FieldProcessor::process(const Field& field) {
    Field result = field;
    for (int r = 0; r < field.rows; ++r) {
        for (int c = 0; c < field.cols; ++c) {
            if (field.grid[r][c] == '*') continue;
            int count = 0;
            for (int dr = -1; dr <= 1; ++dr)
                for (int dc = -1; dc <= 1; ++dc) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < field.rows && nc >= 0 && nc < field.cols)
                        if (field.grid[nr][nc] == '*') ++count;
                }
            result.grid[r][c] = '0' + count;
        }
    }
    return result;
}
