#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_001_2_S1, NoTrailingBlankLineAfterLastField) {
    // GIVEN - two fields are printed in sequence
    Field field1{1, 1, {"0"}};
    Field field2{1, 1, {"1"}};

    // WHEN - both calls to printField complete
    std::ostringstream out;
    printField(out, field1, 1);
    printField(out, field2, 2);

    // THEN - exactly one blank line appears between the two field blocks
    // THEN - the output does not end with a blank line
    EXPECT_EQ(out.str(), "Field #1:\n0\n\nField #2:\n1\n");
}
