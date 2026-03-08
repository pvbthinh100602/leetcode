#include <gtest/gtest.h>
#include "solution.h"

TEST(uniqueBinaryString, testCase1) {
    Solution solution;

    vector<string> nums = {"01", "10"};
    auto result = solution.findDifferentBinaryString(nums);

    EXPECT_EQ(result, "00");
}

TEST(uniqueBinaryString, testCase2) {
    Solution solution;

    vector<string> nums = {"00", "01"};
    auto result = solution.findDifferentBinaryString(nums);

    EXPECT_EQ(result, "10");
}