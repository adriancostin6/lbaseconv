/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/hex2bin.h"

#include "lbaseconv/util/string.h"
#include "lbaseconv/hex2dec.h"
#include "lbaseconv/dec2bin.h"

int hex2bin_input_ok(const char *s, size_t len);

string_t htob(const char *s, size_t len)
{
    int i;
    long dec;
    string_t result;

    if (!s || len == 0 || *s == '\0') {
        result.data = NULL;
        result.len = 0;
        return result;
    }

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;

    if(!hex2bin_input_ok(s+i, len)) {
        result.data = NULL;
        result.len = 0;
        return result;
    }

    dec = htod(s+i, len);
    if(dec == -1) {
        result.data = NULL;
        result.len = 0;
        return result;
    }

    result = dtob(dec);
    return result;
}

int hex2bin_input_ok(const char *s, size_t len)
{
    int i;

    /* only convert hex strings that fit inside a long integer */
    if(len > 8)

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
