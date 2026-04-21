#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_INFRA_001_1_S1, ProcessingTestsPassInsideDocker) {
    // GIVEN - a field with a mine
    Field field{2, 2, {"*.", ".."}};

    // WHEN - processField is called
    Field result = processField(field);

    // THEN - adjacent counts are correct and mine is preserved
    EXPECT_EQ(result.grid[0][0], '*');
    EXPECT_EQ(result.grid[0][1], '1');
    EXPECT_EQ(result.grid[1][0], '1');
    EXPECT_EQ(result.grid[1][1], '1');
}
