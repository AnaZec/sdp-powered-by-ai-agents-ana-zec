#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_001_2_S1, StopOnTerminatorLine) {
    // GIVEN
    std::istringstream input("2 2\n..\n..\n0 0\n");
    // WHEN
    auto result = parseFields(input);
    // THEN
    ASSERT_EQ(result.size(), 1u);
    EXPECT_EQ(result[0].rows, 2);
    EXPECT_EQ(result[0].cols, 2);
}
