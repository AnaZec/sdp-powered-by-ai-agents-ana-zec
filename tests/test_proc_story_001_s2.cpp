#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_STORY_001_S2, PreserveMinePositionsUnchanged) {
    // GIVEN
    Field field{1, 3, {"*.*"}};
    // WHEN
    Field result = processField(field);
    // THEN
    EXPECT_EQ(result.grid[0][0], '*');
    EXPECT_EQ(result.grid[0][2], '*');
}
