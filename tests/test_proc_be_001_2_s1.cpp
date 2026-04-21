#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_BE_001_2_S1, ProcessCornerCellCorrectly) {
    // GIVEN - the target cell is located in a corner of the field
    Field field{1, 1, {"."}};

    // WHEN - the processor evaluates its adjacent mine count
    Field result = processField(field);

    // THEN - only valid in-bounds neighbors are considered
    // THEN - the correct adjacent mine count is produced
    EXPECT_EQ(result.grid[0][0], '0');
}
