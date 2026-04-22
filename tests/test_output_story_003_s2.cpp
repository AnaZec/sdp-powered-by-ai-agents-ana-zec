#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_003_S2, NoBlankLineAfterLastField) {
    // GIVEN - one annotated field
    Field f{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - the field is printed
    printField(out, f, 1);

    // THEN - output does not end with a blank line
    EXPECT_EQ(out.str(), "Field #1:\n0\n");
}
