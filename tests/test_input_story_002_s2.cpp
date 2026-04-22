#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(INPUT_STORY_002_S2, TerminatorOnlyProducesNoOutput) {
    // GIVEN - stdin contains only "0 0"
    FILE* pipe = popen("printf '0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - the full pipeline runs
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    int exit_code = pclose(pipe);

    // THEN - nothing is written to stdout
    EXPECT_EQ(exit_code, 0);
    EXPECT_TRUE(output.empty());
}
