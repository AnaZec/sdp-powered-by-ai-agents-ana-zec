#pragma once
#include <string>
#include <vector>

struct Field {
    int rows;
    int cols;
    std::vector<std::string> grid;
};

class FieldProcessor {
public:
    Field process(const Field& field);
};
