#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_003_1_S1, BlankLinePrecedesAllFieldsExceptFirst) {
    // GIVEN - two fields to be printed with indices 1 and 2
    Field field1{1, 1, {"0"}};
    Field field2{1, 1, {"1"}};
    std::ostringstream out;

    // WHEN - both calls complete
    printField(out, field1, 1);
    printField(out, field2, 2);

    // THEN - output for index 1 has no leading blank line
    // THEN - output for index 2 is preceded by exactly one blank line
    EXPECT_EQ(out.str(), "Field #1:\n0\n\nField #2:\n1\n");
}
