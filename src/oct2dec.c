/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/oct2dec.h"

#include <string.h>
#include <ctype.h>
#include <math.h>

#define OCTAL_PREFIX_NEW 2
#define OCTAL_PREFIX_OLD 1

int oct2dec_input_ok(const char *s, size_t len);

/* converts a string of octal digits to decimal*/
long otod(const char *s, size_t len)
{
    int i;
    int power;
    long result;

    if (!s || len == 0 || *s == '\0')
        return -1;

    if (s[0] == '0' && (s[1] == 'o' || s[1] == 'O')) {
        i = 2;
        power = len - OCTAL_PREFIX_NEW - 1;
    } else if (s[0] == '0') {
        i = 1;
        power = len - OCTAL_PREFIX_OLD - 1;
    }
    else {
        i = 0;
        power = len - 1;
    }

    if(!oct2dec_input_ok(s+i, len))
        return -1;

    result = 0;
    while (i < len) {
        if(isdigit(s[i])) {
            result += (s[i] - '0') * pow(8, power);
            --power;
        }
        ++i;
    }
    return result;
}

int oct2dec_input_ok(const char *s, size_t len)
{
    int i;

    if(len > 10)
        return 0;

    for(i = 0; s[i] != '\0'; ++i)
        if(s[i] - '0' > 7)
            return 0;

    return 1;
}
