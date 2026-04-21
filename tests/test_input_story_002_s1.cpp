#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_STORY_002_S1, HaltAfterReadingTerminator) {
    // GIVEN - two valid fields, terminator, then another field that must be ignored
    std::istringstream input("1 1\n.\n1 1\n*\n0 0\n1 1\n.\n");
    // WHEN
    auto fields = parseFields(input);
    // THEN - only the two fields before "0 0" are returned
    ASSERT_EQ(fields.size(), 2u);
    EXPECT_EQ(fields[0].grid[0], ".");
    EXPECT_EQ(fields[1].grid[0], "*");
}
