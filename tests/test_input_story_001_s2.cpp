#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(INPUT_STORY_001_S2, MultipleFieldsProcessedInSequence) {
    // GIVEN - stdin contains two fields followed by "0 0"
    FILE* pipe = popen("printf '1 1\n.\n1 1\n*\n0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - binary runs with piped stdin
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    int exit_code = pclose(pipe);

    // THEN - both fields appear in output
    EXPECT_EQ(exit_code, 0);
    EXPECT_NE(output.find("Field #2:"), std::string::npos);
}
