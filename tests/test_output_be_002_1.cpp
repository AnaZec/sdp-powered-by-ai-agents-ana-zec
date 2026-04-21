#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_002_1_S1, HeaderContainsSuppliedIndex) {
    // GIVEN - an annotated Field and index 3
    Field field{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - printField is called with the ostringstream, field, and index 3
    printField(out, field, 3);

    // THEN - the first line of the stream is "Field #3:"
    EXPECT_EQ(out.str(), "\nField #3:\n0\n");
}
