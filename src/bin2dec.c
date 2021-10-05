/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/bin2dec.h"

#include <string.h>
#include <ctype.h>
#include <math.h>

#define BIN_PREFIX 2

int bin2dec_input_ok(const char *s, size_t len);

/* converts a binary string to decimal; returns integer result */
long btod(const char *s, size_t len)
{
    int i;
    int power;
    long result;

    if (!s || len == 0 || *s == '\0')
        return -1;

    if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B')) {
        i = 2;
        power = len - BIN_PREFIX - 1;
    } else {
        i = 0;
        power = len - 1;
    }

    if (!bin2dec_input_ok(s+i, len))
        return -1;

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

int bin2dec_input_ok(const char *s, size_t len)
{
    if(len > 32)
        return 0;

    return 1;
}
