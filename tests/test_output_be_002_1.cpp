#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_BE_002_1_S1, HeaderContainsSuppliedIndex) {
    // GIVEN - printField is called with an ostringstream and index 3
    Field field{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - the function writes its output
    printField(out, field, 3);

    // THEN - the first line of the stream is "Field #3:"
    std::string output = out.str();
    EXPECT_NE(output.find("Field #3:"), std::string::npos);
}
