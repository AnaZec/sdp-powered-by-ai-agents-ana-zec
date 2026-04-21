#include <gtest/gtest.h>
#include "FieldProcessor.hpp"

TEST(PROC_BE_001_3_S1, SkipNumericConversionForMine) {
    // GIVEN - the current cell contains '*'
    Field field{1, 3, {"*.*"}};

    // WHEN - the processor evaluates the field
    FieldProcessor processor;
    Field result = processor.process(field);

    // THEN - the cell remains '*'
    EXPECT_EQ(result.grid[0][0], '*');
    EXPECT_EQ(result.grid[0][2], '*');
    // THEN - no adjacent-mine count is computed for that position
    // (verified by checking mines stay as '*', not converted to digits)
}
