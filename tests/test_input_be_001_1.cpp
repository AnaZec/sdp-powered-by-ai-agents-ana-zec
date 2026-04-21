#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_001_1_S1, ProduceCorrectlyPopulatedFieldStruct) {
    // GIVEN
    std::istringstream input("4 4\n....\n....\n....\n....\n0 0\n");
    // WHEN
    auto result = parseFields(input);
    // THEN
    ASSERT_EQ(result.size(), 1u);
    EXPECT_EQ(result[0].rows, 4);
    EXPECT_EQ(result[0].cols, 4);
    ASSERT_EQ(result[0].grid.size(), 4u);
    EXPECT_EQ(result[0].grid[0], "....");
    EXPECT_EQ(result[0].grid[3], "....");
}
