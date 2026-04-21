#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_001_S1, PrintSingleAnnotatedFieldWithCorrectHeader) {
    // GIVEN
    Field field{1, 2, {"1*"}};
    // WHEN
    std::ostringstream out;
    printField(out, field, 1);
    // THEN
    EXPECT_EQ(out.str(), "Field #1:\n1*\n");
}
