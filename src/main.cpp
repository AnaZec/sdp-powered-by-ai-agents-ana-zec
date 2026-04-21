#include "InputParser.hpp"
#include "FieldProcessor.hpp"
#include "OutputFormatter.hpp"

int main() {
    FieldProcessor processor;
    int index = 0;
    for (const auto& field : parseFields(std::cin))
        printField(std::cout, processor.process(field), ++index);
}
