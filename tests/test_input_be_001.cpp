#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_001_1_S1, ProduceCorrectlyPopulatedFieldStruct) {
    // GIVEN
    std::istringstream in("4 4\n..*.\n....\n.*..\n....\n0 0\n");

    // WHEN
    auto fields = parseFields(in);

    // THEN
    ASSERT_EQ(fields.size(), 1u);
    EXPECT_EQ(fields[0].rows, 4);
    EXPECT_EQ(fields[0].cols, 4);
    EXPECT_EQ(fields[0].grid[0], "..*.");
    EXPECT_EQ(fields[0].grid[1], "....");
    EXPECT_EQ(fields[0].grid[2], ".*..");
    EXPECT_EQ(fields[0].grid[3], "....");
}
