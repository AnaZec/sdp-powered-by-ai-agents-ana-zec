#include <gtest/gtest.h>

TEST(PROC_STORY_002_S2, BinaryProducesCorrectOutputForKnownInput) {
    // GIVEN - input.txt and expected.txt exist in testdata/
    // WHEN - binary runs with input redirected
    // THEN - stdout matches expected output exactly
    EXPECT_EQ(system("./minesweeper < testdata/input.txt | diff - testdata/expected.txt"), 0);
}
