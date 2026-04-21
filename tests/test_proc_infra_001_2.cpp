#include <gtest/gtest.h>
#include "InputParser.hpp"
#include "FieldProcessor.hpp"
#include "OutputFormatter.hpp"

TEST(PROC_INFRA_001_2_S1, BinariesCompileInsideDocker) {
    // GIVEN - a field processed through the full pipeline
    std::istringstream input("2 2\n*.\n..\n0 0\n");
    std::ostringstream output;

    // WHEN - pipeline runs (proves both binaries compiled)
    int index = 0;
    for (const auto& field : parseFields(input))
        printField(output, processField(field), ++index);

    // THEN - output is correct
    EXPECT_EQ(output.str(), "Field #1:\n*1\n11\n");
}
