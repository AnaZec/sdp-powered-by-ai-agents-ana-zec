#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_001_2_S1, StopOnTerminatorLine) {
    // GIVEN - an istream containing one valid field followed by "0 0"
    std::istringstream input("2 2\n..\n..\n0 0\n");

    // WHEN - parseFields is called
    std::vector<Field> result = parseFields(input);

    // THEN - only the fields before "0 0" are returned
    EXPECT_EQ(result.size(), 1);
    // THEN - the terminator line does not appear as a field or grid row
    EXPECT_EQ(result[0].rows, 2);
    EXPECT_EQ(result[0].cols, 2);
    EXPECT_NE(result[0].rows, 0);
    EXPECT_NE(result[0].cols, 0);
}
