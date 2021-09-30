#include "lbaseconv/util/invert_string.h"

void invert_string(char s[], int len)
{
    int i;
    char temp;

    for(i = 0; i < len / 2; ++i) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}
