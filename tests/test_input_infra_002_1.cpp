#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_INFRA_002_1_S1, TerminatorOnlyInputReturnsEmpty) {
    // GIVEN - stdin contains only "0 0"
    std::istringstream input("0 0\n");
    // WHEN
    auto fields = parseFields(input);
    // THEN - empty collection, no fields parsed
    EXPECT_EQ(fields.size(), 0u);
}
