#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_STORY_003_S1, AllFieldsParsedFromSingleStream) {
    // GIVEN - stdin contains three fields followed by 0 0
    std::istringstream input("1 1\n.\n1 1\n*\n2 2\n..\n..\n0 0\n");

    // WHEN - the Input Parser reads stdin
    auto fields = parseFields(input);

    // THEN - three Field structs are returned in order
    ASSERT_EQ(fields.size(), 3);
    EXPECT_EQ(fields[0].grid[0], ".");
    EXPECT_EQ(fields[1].grid[0], "*");
    EXPECT_EQ(fields[2].rows, 2);
}
