#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(INPUT_FE_001_1_S1, BinaryAcceptsPipedFileInput) {
    // GIVEN - a valid single-field input piped to the binary
    FILE* pipe = popen("echo '4 4\n....\n....\n....\n....\n0 0' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    int exit_code = pclose(pipe);

    // WHEN - binary runs with piped stdin
    // THEN - exits successfully and writes annotated output to stdout
    EXPECT_EQ(exit_code, 0);
    EXPECT_NE(output.find("Field #1:"), std::string::npos);
}
