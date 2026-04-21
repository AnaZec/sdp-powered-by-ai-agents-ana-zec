#pragma once
#include <iostream>
#include <vector>
#include "FieldProcessor.hpp"

std::vector<Field> parseFields(std::istream& input) {
    int rows, cols;
    input >> rows >> cols;
    std::vector<std::string> grid;
    std::string line;
    std::getline(input, line);
    for (int i = 0; i < rows; i++) {
        std::getline(input, line);
        grid.push_back(line);
    }
    Field field{rows, cols, grid};
    input >> rows >> cols;
    return {field};
}
