#include <gtest/gtest.h>
#include <sstream>
#include "InputParser.hpp"

TEST(INPUT_BE_001_1_S1, ProduceCorrectlyPopulatedFieldStruct) {
    // GIVEN
    std::istringstream input("4 4\n..*.\n....\n.*..\n....\n0 0\n");
    // WHEN
    auto fields = parseFields(input);
    // THEN
    ASSERT_EQ(fields.size(), 1u);
}
