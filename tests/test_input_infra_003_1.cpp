#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_INFRA_003_1_S1, MultiFieldTestExecutesInsideDocker) {
    // GIVEN - input with two fields via stringstream
    std::istringstream input("1 1\n.\n2 2\n..\n..\n0 0\n");

    // WHEN - parseFields is called
    auto fields = parseFields(input);

    // THEN - multi-field parsing works correctly
    ASSERT_EQ(fields.size(), 2);
    EXPECT_EQ(fields[0].rows, 1);
    EXPECT_EQ(fields[0].cols, 1);
    EXPECT_EQ(fields[1].rows, 2);
    EXPECT_EQ(fields[1].cols, 2);
}
