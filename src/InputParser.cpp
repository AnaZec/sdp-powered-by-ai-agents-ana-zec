#include "InputParser.hpp"

std::vector<Field> parseFields(std::istream& input) {
    std::vector<Field> fields;
    int rows, cols;
    while (input >> rows >> cols && (rows || cols)) {
        input.ignore();
        std::vector<std::string> grid;
        grid.reserve(rows);
        for (int i = 0; i < rows; i++) {
            std::string line;
            std::getline(input, line);
            grid.push_back(std::move(line));
        }
        fields.push_back({rows, cols, std::move(grid)});
    }
    return fields;
}
