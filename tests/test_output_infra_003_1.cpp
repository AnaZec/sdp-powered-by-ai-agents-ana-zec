#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_INFRA_003_1_S1, SeparatorPlacementTestExecutesInsideDocker) {
    // GIVEN - two consecutive printField calls via ostringstream
    Field f1{1, 1, {"*"}};
    Field f2{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - both fields are printed
    printField(out, f1, 1);
    printField(out, f2, 2);

    // THEN - exactly one blank line separates them, none after last
    EXPECT_EQ(out.str(), "Field #1:\n*\n\nField #2:\n0\n");
}
