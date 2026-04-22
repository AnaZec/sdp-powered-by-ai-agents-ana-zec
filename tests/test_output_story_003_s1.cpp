#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_003_S1, BlankLineAppearsBetweenTwoConsecutiveFields) {
    // GIVEN - two annotated fields
    Field f{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - both fields are printed
    printField(out, f, 1);
    printField(out, f, 2);

    // THEN - exactly one blank line separates the two blocks
    EXPECT_EQ(out.str(), "Field #1:\n0\n\nField #2:\n0\n");
}
