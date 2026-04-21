#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"
#include "FieldProcessor.hpp"
#include "OutputFormatter.hpp"

TEST(OUTPUT_INFRA_001_2_S1, FullTestSuitePassesInsideDocker) {
    // GIVEN - full pipeline is implemented
    std::istringstream input("1 1\n.\n0 0\n");
    std::ostringstream output;

    // WHEN - full pipeline runs
    int index = 0;
    for (const auto& field : parseFields(input))
        printField(output, processField(field), ++index);

    // THEN - all tests pass
    EXPECT_EQ(output.str(), "Field #1:\n0\n");
}
