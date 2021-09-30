/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/bin2int.h"

#include <string.h>
#include <ctype.h>
#include <math.h>

#define BIN_PREFIX 2

/* converts a binary string to decimal; returns integer result */
/* pass 0 for full string, or len for variable size of  binary strings*/
int btoi(const char *s, int len)
{
    int i;
    int result, power;

    if (!len)
        len = strlen(s);

    /* take bin prefix into account */
    if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B')) {
        i = 2;
        power = len - BIN_PREFIX - 1;
    }
    else {
        i = 0;
        power = len - 1;
    }

    /* calculate decimal value for binary string */
    result = 0;
    while (i < len) {
        if(isdigit(s[i])) {
            result += (s[i] - '0') * pow(2, power);
            --power;
        }
        ++i;
    }
    return result;
}
