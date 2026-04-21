#include "InputParser.hpp"
#include "FieldProcessor.hpp"
#include "OutputFormatter.hpp"

int main() {
    int index = 0;
    for (const auto& field : parseFields(std::cin))
        printField(std::cout, FieldProcessor::process(field), ++index);
}
