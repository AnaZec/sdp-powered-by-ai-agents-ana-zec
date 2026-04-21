#include <gtest/gtest.h>
#include <sstream>
#include "../src/InputParser.hpp"

TEST(INPUT_BE_003_1_S1, ReturnAllFieldsInInputOrder) {
    // GIVEN - an istream containing two fields followed by 0 0
    std::istringstream input("2 2\n..\n..\n3 1\n.\n*\n.\n0 0\n");

    // WHEN - parseFields is called
    auto fields = parseFields(input);

    // THEN - the returned vector has exactly two elements
    ASSERT_EQ(fields.size(), 2);
    // element 0 matches the first field
    EXPECT_EQ(fields[0].rows, 2);
    EXPECT_EQ(fields[0].cols, 2);
    EXPECT_EQ(fields[0].grid[0], "..");
    EXPECT_EQ(fields[0].grid[1], "..");
    // element 1 matches the second field
    EXPECT_EQ(fields[1].rows, 3);
    EXPECT_EQ(fields[1].cols, 1);
    EXPECT_EQ(fields[1].grid[0], ".");
    EXPECT_EQ(fields[1].grid[1], "*");
    EXPECT_EQ(fields[1].grid[2], ".");
}
