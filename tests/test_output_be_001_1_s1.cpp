#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_001_1_S1, EmitCorrectHeaderToOstream) {
    // GIVEN - an annotated Field with two rows "1*" and "11" is passed as the second field (index 2)
    std::ostringstream out;
    Field field{2, 2, {"1*", "11"}};
    // WHEN - printField is called with an ostringstream, the field, and index 2
    printField(out, field, 2);
    // THEN - the stream contains "Field #2:" on the first line
    EXPECT_EQ(out.str().substr(0, 9), "Field #2:");
}
