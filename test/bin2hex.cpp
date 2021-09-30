#include "gtest/gtest.h"

extern "C" {
#include "lbaseconv/bin2hex.h"
#include "lbaseconv/util/string.h"
}


TEST(bin2hex, good_input) {
    String s = btoh("1100");
    ASSERT_STREQ(s.data, "C");
}

// if the input string is uneven, leading zeroes should be added accordingly
TEST(bin2hex, uneven_input) {
    String s = btoh("1");
    ASSERT_STREQ(s.data, "1");
}
TEST(bin2hex, uneven_input_2) {
    String s = btoh("011");
    ASSERT_STREQ(s.data, "3");
}

TEST(bin2hex, input_length) {
    String s = btoh("1100111111111111111111111111111111111111111111111111");
    ASSERT_STREQ(s.data, "CFFFFFFFFFFFF");
}

TEST(bin2hex, input_gaps) {
    String s = btoh("1 0 1 1");
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);
}

TEST(bin2hex, input_groups_gaps) {
    String s = btoh("10 111");
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);
}

TEST(bin2hex, null_input) {
    String s = btoh(NULL);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);
}

TEST(bin2hex, empty_input) {
    String s = btoh("");
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);
}

TEST(bin2hex, bad_input) {
    String s = btoh("lksgdjkg");
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);
}

TEST(bin2hex, mixed_input) {
    String s = btoh("1100sdf010");
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);
}

// input has to be a binary string, cannot contain other digits apart from 1 and 0
TEST(bin2hex, other_digits_input) {
    String s = btoh("34153125324");
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);
}

