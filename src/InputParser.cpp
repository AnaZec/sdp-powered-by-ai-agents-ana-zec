#include "InputParser.hpp"

std::vector<Field> parseFields(std::istream& input) {
    std::vector<Field> fields;
    int rows, cols;
    while (input >> rows >> cols && (rows || cols)) {
        std::vector<std::string> grid;
        std::string line;
        std::getline(input, line);
        for (int i = 0; i < rows; i++) {
            std::getline(input, line);
            grid.push_back(line);
        }
        fields.push_back({rows, cols, grid});
    }
    return fields;
}
