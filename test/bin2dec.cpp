#include "gtest/gtest.h"

extern "C" {
#include "lbaseconv/bin2dec.h"
}

TEST(bin2int, good_input) {
    ASSERT_EQ(btod("1100", 4), 12);
}

TEST(bin2int, empty_input) {
    ASSERT_EQ(btod("", 0), -1);
}

TEST(bin2int, empty_input_positive_size) {
    ASSERT_EQ(btod("", 10), -1);
}

TEST(bin2int, null_input) {
    ASSERT_EQ(btod(NULL, 0), -1);
}

TEST(bin2int, null_input_positive_size) {
    ASSERT_EQ(btod(NULL, 10), -1);
}

TEST(bin2int, long_input) {
    ASSERT_EQ(btod("10101010101010101010", 20), 699050);
}
