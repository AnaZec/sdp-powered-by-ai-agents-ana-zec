#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_STORY_001_S1, ParseSingleWellFormedField) {
    // GIVEN - stdin contains a header "4 4" followed by 4 grid rows, terminated by "0 0"
    std::istringstream input("4 4\n.*.*\n....\n*...\n..*.\n0 0\n");

    // WHEN - the Input Parser reads stdin
    auto fields = parseFields(input);

    // THEN - exactly one Field struct is returned with correct dimensions and grid
    ASSERT_EQ(fields.size(), 1u);
    EXPECT_EQ(fields[0].rows, 4);
    EXPECT_EQ(fields[0].cols, 4);
    ASSERT_EQ(fields[0].grid.size(), 4u);
    EXPECT_EQ(fields[0].grid[0], ".*.*");
    EXPECT_EQ(fields[0].grid[3], "..*.");
}
