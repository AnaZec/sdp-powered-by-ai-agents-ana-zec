#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_001_S1, PrintSingleAnnotatedFieldWithCorrectHeader) {
    // GIVEN
    Field field{2, 2, {"1*", "11"}};
    // WHEN
    std::ostringstream out;
    printField(out, field, 1);
    // THEN
    EXPECT_EQ(out.str(), "Field #1:\n1*\n11\n");
}
