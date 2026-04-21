#include "OutputFormatter.hpp"

void printField(std::ostream& out, const Field& field, int index) {
    if (index > 1) {
        out << "\n";
    }
    out << "Field #" << index << ":\n";
    for (const auto& row : field.grid) {
        out << row << "\n";
    }
}
