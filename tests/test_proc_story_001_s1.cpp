#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_STORY_001_S1, CountAdjacentMinesForInteriorSafeCell) {
    // GIVEN
    Field field{3, 3, {"***", "*.*", "***"}};
    // WHEN
    Field result = processField(field);
    // THEN
    EXPECT_EQ(result.grid[1][1], '8');
}
