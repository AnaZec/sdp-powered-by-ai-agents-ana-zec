#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_STORY_002_S1, HaltAfterReadingTerminator) {
    // GIVEN - two valid fields followed by "0 0"
    std::istringstream input("1 1\n.\n1 1\n*\n0 0\n");
    // WHEN
    auto fields = parseFields(input);
    // THEN - only fields before terminator returned
    ASSERT_EQ(fields.size(), 2u);
    EXPECT_EQ(fields[0].grid[0], ".");
    EXPECT_EQ(fields[1].grid[0], "*");
}
