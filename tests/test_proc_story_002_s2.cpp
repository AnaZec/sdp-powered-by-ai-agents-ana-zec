#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(PROC_STORY_002_S2, BinaryProducesCorrectOutputForKnownInput) {
    // GIVEN - the minesweeper binary has been compiled and sample input exists
    FILE* pipe = popen("printf '2 2\n..\n..\n0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - binary runs with sample input
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    pclose(pipe);

    // THEN - stdout matches the expected annotated output exactly
    EXPECT_EQ(output, "Field #1:\n00\n00\n");
}
