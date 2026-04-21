#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_BE_001_1_S1, CountMinesInAllNeighboringDirections) {
    // GIVEN - a safe cell exists in the field
    // GIVEN - neighboring cells may appear horizontally, vertically, or diagonally
    Field field{3, 3, {"*..",
                       "...",
                       "**."}};

    // WHEN - the processor evaluates that cell
    FieldProcessor processor;
    Field result = processor.process(field);

    // THEN - all valid neighboring positions are checked exactly once
    // THEN - the resulting count equals the number of neighboring mines
    EXPECT_EQ(result.grid[1][1], '3');  // center cell has 3 adjacent mines
}
