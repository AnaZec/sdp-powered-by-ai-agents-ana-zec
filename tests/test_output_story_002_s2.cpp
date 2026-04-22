#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_002_S2, FieldNumberIncrementsForEachSuccessiveField) {
    // GIVEN - three annotated fields
    Field f{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - all three fields are printed
    printField(out, f, 1);
    printField(out, f, 2);
    printField(out, f, 3);

    // THEN - each block carries the correct incrementing number
    EXPECT_EQ(out.str(), "Field #1:\n0\n\nField #2:\n0\n\nField #3:\n0\n");
}
