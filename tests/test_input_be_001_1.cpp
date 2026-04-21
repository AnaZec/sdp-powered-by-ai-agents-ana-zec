#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_001_1_S1, ProduceCorrectlyPopulatedFieldStruct) {
    // GIVEN - an istream containing a header "4 4" followed by four grid rows
    std::istringstream input("4 4\n....\n....\n....\n....\n0 0\n");

    // WHEN - parseFields is called with that stream
    std::vector<Field> result = parseFields(input);

    // THEN - the returned vector contains one Field
    ASSERT_EQ(result.size(), 1);
    // THEN - Field.rows equals 4, Field.cols equals 4
    EXPECT_EQ(result[0].rows, 4);
    EXPECT_EQ(result[0].cols, 4);
    // THEN - Field.grid contains exactly four strings matching the input rows
    ASSERT_EQ(result[0].grid.size(), 4);
    EXPECT_EQ(result[0].grid[0], "....");
    EXPECT_EQ(result[0].grid[1], "....");
    EXPECT_EQ(result[0].grid[2], "....");
    EXPECT_EQ(result[0].grid[3], "....");
}
