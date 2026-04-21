#include "InputParser.hpp"
#include "FieldProcessor.hpp"
#include "OutputFormatter.hpp"

int main() {
    auto fields = parseFields(std::cin);
    FieldProcessor processor;
    for (int i = 0; i < (int)fields.size(); i++)
        printField(std::cout, processor.process(fields[i]), i + 1);
}
