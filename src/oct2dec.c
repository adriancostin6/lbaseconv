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

/* converts a string of octal digits to decimal*/
int otoi(const char *s)
{
    int i;
    int len, result, power;

    len = strlen(s);

    /* if 0o or 0O is present, or 0, update the start index */
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
