#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(INPUT_FE_001_1_S1, BinaryAcceptsPipedFileInput) {
    // GIVEN - a valid single-field input piped to the binary
    FILE* pipe = popen("printf '4 4\n....\n....\n....\n....\n0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - binary runs with piped stdin
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    int exit_code = pclose(pipe);

    // THEN - exits successfully and writes annotated output to stdout
    EXPECT_EQ(exit_code, 0);
    EXPECT_NE(output.find("Field #1:"), std::string::npos);
}
