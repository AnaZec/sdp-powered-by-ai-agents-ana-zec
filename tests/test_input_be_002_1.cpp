#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_002_1_S1, ExitLoopOnZeroDimensionHeader) {
    // GIVEN
    std::istringstream input("2 2\n..\n..\n0 0\n");
    // WHEN
    auto fields = parseFields(input);
    // THEN
    ASSERT_EQ(fields.size(), 1u);
    EXPECT_EQ(fields[0].grid.size(), 2u);
}
