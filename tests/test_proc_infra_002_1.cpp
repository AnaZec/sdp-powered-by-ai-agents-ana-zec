#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"
#include "FieldProcessor.hpp"
#include "OutputFormatter.hpp"

TEST(PROC_INFRA_002_1_S1, FullPipelinePassesInsideDocker) {
    // GIVEN - a complete input stream with one field
    std::istringstream input("2 2\n..\n..\n0 0\n");
    std::ostringstream output;

    // WHEN - the full pipeline runs
    int index = 0;
    for (const auto& field : parseFields(input))
        printField(output, processField(field), ++index);

    // THEN - output is produced correctly
    EXPECT_EQ(output.str(), "Field #1:\n00\n00\n");
}
