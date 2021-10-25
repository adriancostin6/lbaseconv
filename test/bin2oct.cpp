#include "gtest/gtest.h"

extern "C" {
#include "lbaseconv/baseconv.h"
}

TEST(bin2int, good_input) {
    ASSERT_EQ(btoo("1100", 4), 14);
}

TEST(bin2int, empty_input) {
    ASSERT_EQ(btoo("", 0), -1);
}

TEST(bin2int, empty_input_positive_size) {
    ASSERT_EQ(btoo("", 10), -1);
}

TEST(bin2int, null_input) {
    ASSERT_EQ(btoo(NULL, 0), -1);
}

TEST(bin2int, null_input_positive_size) {
    ASSERT_EQ(btoo(NULL, 10), -1);
}

TEST(bin2int, long_input) {
    ASSERT_EQ(btoo("10101010101010101010", 20), 2525252);
}
