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
    auto fields = parseFields(input);
    for (size_t i = 0; i < fields.size(); i++)
        printField(output, processField(fields[i]), i + 1);

    // THEN - output is produced correctly
    EXPECT_EQ(output.str(), "Field #1:\n00\n00\n");
}
