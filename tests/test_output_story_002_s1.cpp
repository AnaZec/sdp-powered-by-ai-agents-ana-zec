#include <gtest/gtest.h>
#include <sstream>
#include "OutputFormatter.hpp"

TEST(OUTPUT_STORY_002_S1, FirstAndSecondFieldsCarryCorrectNumbers) {
    // GIVEN - two annotated fields
    Field f{1, 1, {"0"}};
    std::ostringstream out;

    // WHEN - both fields are printed
    printField(out, f, 1);
    printField(out, f, 2);

    // THEN - first block begins with Field #1:, second with Field #2:
    std::string result = out.str();
    EXPECT_EQ(result.substr(0, 9), "Field #1:");
    EXPECT_NE(result.find("Field #2:"), std::string::npos);
}
