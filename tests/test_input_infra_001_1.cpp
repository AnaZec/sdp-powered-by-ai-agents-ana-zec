#include <gtest/gtest.h>

TEST(INPUT_INFRA_001_1_S1, GppAndGoogleTestAvailable) {
    // GIVEN - g++ and Google Test libraries are installed
    // WHEN - this test runs inside the container
    // THEN - Google Test is available and working
    EXPECT_TRUE(true);
}
