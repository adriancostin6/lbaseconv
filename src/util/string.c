#include "lbaseconv/util/string.h"

#include <stdlib.h>

string_t string_t_ctor(int len)
{
    string_t s;

    s.data = malloc(len * sizeof(char));
    s.len = len;

    return s;
}

void string_t_dtor(string_t s)
{
    free(s.data);
    s.len = 0;
}

