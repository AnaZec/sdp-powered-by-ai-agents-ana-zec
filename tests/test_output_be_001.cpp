#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_001_1_S1, EmitCorrectHeaderAndGridToOstream) {
    // GIVEN
    Field field{2, 2, {"1*", "11"}};

    // WHEN
    std::ostringstream out;
    printField(out, field, 2);

    // THEN
    EXPECT_EQ(out.str(), "Field #2:\n1*\n11\n");
}
