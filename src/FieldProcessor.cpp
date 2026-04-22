#include "FieldProcessor.hpp"

namespace {
    int countAdjacentMines(const Field& field, int row, int col) {
        auto inBounds = [&](int r, int c) {
            return r >= 0 && r < field.rows && c >= 0 && c < field.cols;
        };
        int count = 0;
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
                if ((dr || dc) && inBounds(row + dr, col + dc) && field.grid[row + dr][col + dc] == '*')
                    count++;
        return count;
    }
}

Field processField(const Field& field) {
    Field result = field;
    for (int r = 0; r < field.rows; r++) {
        for (int c = 0; c < field.cols; c++) {
            if (field.grid[r][c] == '.')
                result.grid[r][c] = '0' + countAdjacentMines(field, r, c);
        }
    }
    return result;
}
