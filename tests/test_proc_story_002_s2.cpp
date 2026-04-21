#include <gtest/gtest.h>

TEST(PROC_STORY_002_S2, BinaryProducesCorrectOutputForKnownInput) {
    // GIVEN - minesweeper binary compiled, testdata/input.txt and testdata/expected.txt present

    // WHEN - binary runs with input redirected and output diffed against expected
    int result = system("./minesweeper < testdata/input.txt | diff - testdata/expected.txt");

    // THEN - diff exits with 0 (no differences)
    EXPECT_EQ(result, 0);
}
