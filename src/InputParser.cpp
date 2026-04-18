#include "InputParser.hpp"
#include <string>

std::vector<Field> parseFields(std::istream& in) {
    std::vector<Field> fields;
    int rows, cols;
    while (in >> rows >> cols && (rows || cols)) {
        Field f{rows, cols, {}};
        std::string line;
        std::getline(in, line); // consume newline after header
        for (int i = 0; i < rows; ++i) {
            std::getline(in, line);
            f.grid.push_back(line);
        }
        fields.push_back(f);
    }
    return fields;
}
