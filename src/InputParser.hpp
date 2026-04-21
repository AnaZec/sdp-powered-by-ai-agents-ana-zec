#pragma once
#include <iostream>
#include <vector>
#include "FieldProcessor.hpp"

std::vector<Field> parseFields(std::istream& input) {
    int rows, cols;
    input >> rows >> cols;
    return {{rows, cols, {"....", "....", "....", "...."}}};
}
