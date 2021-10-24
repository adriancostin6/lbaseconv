/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/hex2dec.h"

#include <math.h>
#include <ctype.h>

#define HEX_PREFIX 2

int hex2dec_input_ok(const char *s, size_t len);

/* converts a string of hexadecimal digits to decimal*/
unsigned long htod(const char *s, size_t len)
{
    int i;
    int power;
    unsigned long result;

    if (!s || len == 0 || *s == '\0')
        return -1;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
        power = len - HEX_PREFIX - 1;
    }
    else {
        i = 0;
        power = len - 1;
    }

    if (!hex2dec_input_ok(s+i, len))
        return -1;

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

int hex2dec_input_ok(const char *s, size_t len)
{
    int i;

    /* only convert hex strings that fit inside a long integer */
    if(len > 8)
        return 0;

    /* check if input contains a non-hex character */
    for(i = 0; s[i] != '\0'; ++i)
        switch(s[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                break;
            default:
                return 0;
        }

    return 1;
}
