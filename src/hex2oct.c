/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/hex2oct.h"

#include <stdlib.h>

#include "lbaseconv/util/string.h"
#include "lbaseconv/hex2dec.h"
#include "lbaseconv/dec2oct.h"

int hex2oct_input_ok(const char *s, size_t len);

long htoo(const char* s, size_t len)
{
    int i;
    long dec, oct;

    if(!s || len == 0 || *s == '\0')
        return -1;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;

    if(!hex2oct_input_ok(s+i, len))
        return -1;

    dec = htoi(s, len);
    if(dec == -1)
        return dec;

    oct = dtoo(dec);

    return oct;
}

int hex2oct_input_ok(const char *s, size_t len)
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
