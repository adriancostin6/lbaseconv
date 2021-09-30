#include "gtest/gtest.h"

extern "C" {
#include "lbaseconv/bin2int.h"
}

TEST(bin2int, ok) {
    ASSERT_EQ(btoi("1100", 0), 12);
}
