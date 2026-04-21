#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_INFRA_001_1_S1, FormatterTestsPassInsideDocker) {
    // GIVEN - formatter functionality is implemented
    Field field{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - printField is called
    printField(out, field, 1);

    // THEN - formatter works correctly
    EXPECT_EQ(out.str(), "Field #1:\n0\n");
}
