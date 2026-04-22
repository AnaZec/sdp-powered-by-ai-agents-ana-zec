#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_INFRA_001_2_S1, ParserTestsPassInsideDocker) {
    // GIVEN - parser functionality is implemented
    std::istringstream input("1 1\n.\n0 0\n");

    // WHEN - parseFields is called
    auto fields = parseFields(input);

    // THEN - parser works correctly
    ASSERT_EQ(fields.size(), 1);
    EXPECT_EQ(fields[0].rows, 1);
    EXPECT_EQ(fields[0].cols, 1);
}
