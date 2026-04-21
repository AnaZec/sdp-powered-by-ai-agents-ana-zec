#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(OUTPUT_FE_001_1_S1, AnnotatedOutputWrittenToStdout) {
    // GIVEN - a valid field piped to the binary
    FILE* pipe = popen("printf '1 1\n.\n0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - binary runs with piped stdin
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    pclose(pipe);

    // THEN - annotated output is written to stdout
    EXPECT_NE(output.find("Field #1:"), std::string::npos);
}
