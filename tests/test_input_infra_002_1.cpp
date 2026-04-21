#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_INFRA_002_1_S1, TerminatorOnlyInputReturnsEmpty) {
    // GIVEN
    std::istringstream input("0 0\n");
    // WHEN
    auto fields = parseFields(input);
    // THEN
    EXPECT_TRUE(fields.empty());
}
