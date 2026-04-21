#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_001_1_S1, EmitCorrectHeaderAndGridToOstream) {
    // GIVEN - an annotated Field with two rows "1*" and "11" is passed as the second field (index 2)
    Field field{2, 2, {"1*", "11"}};

    // WHEN - printField is called with an ostringstream, the field, and index 2
    std::ostringstream out;
    printField(out, field, 2);

    // THEN - the stream contains "Field #2:" on the first line
    // THEN - the next two lines are "1*" and "11"
    EXPECT_EQ(out.str(), "\nField #2:\n1*\n11\n");
}
