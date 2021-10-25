#include "gtest/gtest.h"

extern "C" {
#include "lbaseconv/bin2hex.h"
}


TEST(bin2hex, good_input) {
    string_t s = btoh("1100", 4);
    ASSERT_STREQ(s.data, "C");

    string_t_dtor(s);
 }

// if the input string is uneven, leading zeroes should be added accordingly
TEST(bin2hex, uneven_input) {
    string_t s = btoh("1", 1);
    ASSERT_STREQ(s.data, "1");

    string_t_dtor(s);
}
TEST(bin2hex, uneven_input_2) {
    string_t s = btoh("011", 3);
    ASSERT_STREQ(s.data, "3");

    string_t_dtor(s);
}

TEST(bin2hex, input_length) {
    string_t s = btoh("11001111111111111111111111111111", 32);
    ASSERT_STREQ(s.data, "CFFFFFFF");

    string_t_dtor(s);
}

TEST(bin2hex, input_gaps) {
    string_t s = btoh("1 0 1 1", 7);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);

    string_t_dtor(s);
}

TEST(bin2hex, input_groups_gaps) {
    string_t s = btoh("10 111", 6);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);

    string_t_dtor(s);
}

TEST(bin2hex, null_input) {
    string_t s = btoh(NULL, 0);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);

    string_t_dtor(s);
}

TEST(bin2hex, empty_input) {
    string_t s = btoh("", 0);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);

    string_t_dtor(s);
}

TEST(bin2hex, bad_input) {
    string_t s = btoh("lksgdjkg", 8);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);

    string_t_dtor(s);
}

TEST(bin2hex, mixed_input) {
    string_t s = btoh("1100sdf010", 10);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);

    string_t_dtor(s);
}

// input has to be a binary string, cannot contain other digits apart from 1 and 0
TEST(bin2hex, other_digits_input) {
    string_t s = btoh("34153125324", 11);
    ASSERT_STREQ(s.data, NULL);
    ASSERT_EQ(s.len, 0);

    string_t_dtor(s);
}

