#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(INPUT_STORY_003_S2, OutputBlocksCorrespondToInputFields) {
    // GIVEN - stdin contains two fields with different dimensions
    FILE* pipe = popen("printf '1 1\n.\n2 2\n**\n**\n0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - the full pipeline runs
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    int exit_code = pclose(pipe);

    // THEN - first output block reflects first field, second reflects second field
    EXPECT_EQ(exit_code, 0);
    EXPECT_NE(output.find("Field #1:\n0\n"), std::string::npos);
    EXPECT_NE(output.find("Field #2:\n**\n**\n"), std::string::npos);
}
