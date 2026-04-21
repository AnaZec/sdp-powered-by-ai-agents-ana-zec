#include "FieldProcessor.hpp"

Field processField(const Field& field) {
    Field result = field;
    auto inBounds = [&](int r, int c) {
        return r >= 0 && r < field.rows && c >= 0 && c < field.cols;
    };
    for (int r = 0; r < field.rows; r++) {
        for (int c = 0; c < field.cols; c++) {
            if (field.grid[r][c] != '.') continue;
            int count = 0;
            for (int dr = -1; dr <= 1; dr++)
                for (int dc = -1; dc <= 1; dc++)
                    if ((dr || dc) && inBounds(r + dr, c + dc) && field.grid[r + dr][c + dc] == '*')
                        count++;
            result.grid[r][c] = '0' + count;
        }
    }
    return result;
}
