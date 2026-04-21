#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_BE_001_2_S2, ProcessEdgeCellCorrectly) {
    // GIVEN - the target cell is located on an edge but not in a corner
    Field field{1, 2, {".*"}};

    // WHEN - the processor evaluates its adjacent mine count
    Field result = processField(field);

    // THEN - only valid in-bounds neighbors are considered
    // THEN - the correct adjacent mine count is produced
    EXPECT_EQ(result.grid[0][0], '1');
}
