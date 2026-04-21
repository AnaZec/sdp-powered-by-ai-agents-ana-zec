#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_001_S2, SeparateConsecutiveFieldsWithBlankLine) {
    // GIVEN
    Field f1{1, 1, {"0"}}, f2{1, 1, {"1"}}, f3{1, 1, {"*"}};
    // WHEN
    std::ostringstream out;
    printField(out, f1, 1);
    printField(out, f2, 2);
    printField(out, f3, 3);
    // THEN - blank line between each pair, no trailing blank line
    EXPECT_EQ(out.str(), "Field #1:\n0\n\nField #2:\n1\n\nField #3:\n*\n");
}
