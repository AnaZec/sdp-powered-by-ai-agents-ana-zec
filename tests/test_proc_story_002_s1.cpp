#include <gtest/gtest.h>
#include <cstdlib>

TEST(PROC_STORY_002_S1, BinaryCompilesWithStandardCpp17Command) {
    // GIVEN - a C++17 compiler is available and main.cpp is present
    // WHEN - g++ -std=c++17 command is executed
    int result = system("g++ -std=c++17 -Isrc -o minesweeper src/main.cpp src/InputParser.cpp src/FieldProcessor.cpp src/OutputFormatter.cpp 2>/dev/null");

    // THEN - the command exits with code 0
    EXPECT_EQ(result, 0);
}
