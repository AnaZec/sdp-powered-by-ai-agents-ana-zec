#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

// Story: PROC_STORY_001 - Field Processor counts adjacent mines
// Scenario: S1 - Count adjacent mines for interior safe cell
TEST(PROC_STORY_001_S1, CountAdjacentMinesForInteriorSafeCell) {
    // GIVEN: a 3x3 field where the center cell is safe and surrounded by 8 mines
    Field field{3, 3, {"***", "*.*", "***"}};

    // WHEN: the field processor computes the annotated output
    FieldProcessor processor;
    Field result = processor.process(field);

    // THEN: the center safe cell is replaced with '8'
    EXPECT_EQ(result.grid[1][1], '8');
}
