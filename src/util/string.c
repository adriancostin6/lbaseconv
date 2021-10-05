#include "lbaseconv/util/string.h"

#include <stdlib.h>

string_t string_t_ctor(int len)
{
    string_t s;

    s.data = malloc(len * sizeof(char));
    s.len = len;

    s.data[len] = '\0';

    return s;
}

void string_t_dtor(string_t s)
{
    if (!s.data)
        return;

    free(s.data);
    s.data = NULL;
    s.len = 0;
}

