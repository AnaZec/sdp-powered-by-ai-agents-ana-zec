#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(INPUT_STORY_001_S3, TerminatorOnlyInputProducesNoOutput) {
    // GIVEN - stdin contains only "0 0"
    FILE* pipe = popen("printf '0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - binary runs with piped stdin
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    pclose(pipe);

    // THEN - nothing is written to stdout
    EXPECT_TRUE(output.empty());
}
