/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/hex2dec.h"

#include <string.h>
#include <math.h>
#include <ctype.h>

#define HEX_PREFIX 2

/* converts a string of hexadecimal digits to decimal*/
int htoi(const char *s)
{
    int i;
    int len, result, power;

    len = strlen(s);

    /* if 0X or 0x is present, update the start index */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
        power = len - HEX_PREFIX - 1;
    }
    else {
        i = 0;
        power = len - 1;
    }

    result = 0;
    while (i < len) {
        if(isdigit(s[i])) {
            result += (s[i] - '0') * pow(16, power);
            --power;
        } else {
            switch(s[i]) {
                case 'A':
                case 'a': 
                    result += 10 * pow(16, power);
                    --power;
                    break;
                case 'B':
                case 'b':
                    result += 11 * pow(16, power);
                    --power;
                    break;
                case 'C':
                case 'c':
                    result += 12 * pow(16, power);
                    --power;
                    break;
                case 'D':
                case 'd':
                    result += 13 * pow(16, power);
                    --power;
                    break;
                case 'E':
                case 'e':
                    result += 14 * pow(16, power);
                    --power;
                    break;
                case 'F':
                case 'f':
                    result += 15 * pow(16, power);
                    --power;
                    break;
            }
        }
        ++i;
    }
    return result;
}
