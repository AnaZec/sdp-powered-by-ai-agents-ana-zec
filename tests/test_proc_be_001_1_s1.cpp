#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

// PROC-BE-001.1-S1: Count mines in all neighboring directions
TEST(FieldProcessor, PROC_BE_001_1_S1_CountMinesInAllNeighboringDirections) {
    // GIVEN - a safe cell exists in the field
    //       - neighboring cells may appear horizontally, vertically, or diagonally
    Field field{3, 3, {
        "***",
        "*.*",
        "***"
    }};

    // WHEN - the processor evaluates that cell
    FieldProcessor processor;
    Field result = processor.process(field);

    // THEN - all valid neighboring positions are checked exactly once
    //      - the resulting count equals the number of neighboring mines
    EXPECT_EQ(result.grid[1][1], '8'); // 8 neighbors, all mines → count = 8
}
