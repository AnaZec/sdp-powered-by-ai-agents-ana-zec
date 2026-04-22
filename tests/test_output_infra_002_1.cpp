#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_INFRA_002_1_S1, NumberingTestsPassInsideDocker) {
    // GIVEN - fields with indices 1, 2, and 5
    Field f{1, 1, {"0"}};
    std::ostringstream out1, out2, out5;

    // WHEN - printField is called with each index
    printField(out1, f, 1);
    printField(out2, f, 2);
    printField(out5, f, 5);

    // THEN - each header contains the correct field number
    EXPECT_EQ(out1.str(), "Field #1:\n0\n");
    EXPECT_EQ(out2.str(), "\nField #2:\n0\n");
    EXPECT_EQ(out5.str(), "\nField #5:\n0\n");
}
