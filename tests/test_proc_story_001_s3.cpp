#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_STORY_001_S3, AssignZeroWhenNoAdjacentMinesExist) {
    // GIVEN - a parsed field exists
    // GIVEN - the target cell is safe
    // GIVEN - none of its valid neighboring cells contains a mine
    Field field{2, 2, {"..", ".."}};

    // WHEN - the field processor computes the annotated output for the field
    Field result = processField(field);

    // THEN - the target cell is replaced with '0'
    EXPECT_EQ(result.grid[0][0], '0');
    EXPECT_EQ(result.grid[0][1], '0');
    EXPECT_EQ(result.grid[1][0], '0');
    EXPECT_EQ(result.grid[1][1], '0');
}
