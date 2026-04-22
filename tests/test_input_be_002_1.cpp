#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_002_1_S1, ExitLoopOnZeroDimensionHeader) {
    // GIVEN - one valid field followed by terminator "0 0"
    std::istringstream input("2 2\n..\n..\n0 0\n");
    // WHEN
    auto fields = parseFields(input);
    // THEN - only the pre-terminator field is returned, terminator not added as row
    ASSERT_EQ(fields.size(), 1u);
    ASSERT_EQ(fields[0].grid.size(), 2u);
    EXPECT_EQ(fields[0].grid[0], "..");
    EXPECT_EQ(fields[0].grid[1], "..");
}
