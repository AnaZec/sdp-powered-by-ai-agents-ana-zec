#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_003_1_S1, BlankLinePrecedesAllFieldsExceptFirst) {
    // GIVEN - printField is called with index 1 and then with index 2
    Field field{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - both calls complete
    printField(out, field, 1);
    printField(out, field, 2);

    // THEN - output for index 1 has no leading blank line
    // THEN - output for index 2 is preceded by exactly one blank line
    EXPECT_EQ(out.str(), "Field #1:\n0\n\nField #2:\n0\n");
}
