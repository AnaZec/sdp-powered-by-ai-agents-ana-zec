#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_001_S3, PreserveMinePositionsInOutput) {
    // GIVEN
    Field field{1, 3, {"*1*"}};
    std::ostringstream out;
    // WHEN
    printField(out, field, 1);
    // THEN
    EXPECT_EQ(out.str(), "Field #1:\n*1*\n");
}
