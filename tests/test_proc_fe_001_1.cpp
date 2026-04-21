#include <gtest/gtest.h>
#include <cstdio>
#include <string>

TEST(PROC_FE_001_1_S1, ComputedValuesPropagateToOutput) {
    // GIVEN - a field with a mine adjacent to a safe cell
    FILE* pipe = popen("printf '1 2\n.*\n0 0\n' | ./minesweeper", "r");
    ASSERT_NE(pipe, nullptr);

    // WHEN - binary runs with piped stdin
    std::string output;
    char buf[256];
    while (fgets(buf, sizeof(buf), pipe)) output += buf;
    pclose(pipe);

    // THEN - computed digit appears in output
    EXPECT_NE(output.find("1*"), std::string::npos);
}
