/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/bin2hex.h"

#include "lbaseconv/bin2dec.h"
#include "lbaseconv/dec2hex.h"


int bin2hex_input_ok(const char *s, size_t len);

/* converts binary string to hex; returns hex value as string*/
string_t btoh(const char *s, size_t len)
{
    string_t result;
    int i;
    unsigned long dec;

    if(!s || len == 0 || *s == '\0') {
        result.data = NULL;
        result.len = 0;
        return result;
    }

    if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B'))
        i = 2;
    else
        i = 0;

    if (!bin2hex_input_ok(s+i, len)) {
        result.data = NULL;
        result.len = 0;
        return result;
    }

    dec = btod(s+i, len);
    if(dec == -1){
        result.data = NULL;
        result.len = 0;
        return result;
    }
    result = dtoh(dec);
    return result;
}

/* check input; return 0 for bad input */
int bin2hex_input_ok(const char *s, size_t len)
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        if (s[i] != '0')
            if(s[i] != '1')
                return 0;

    if(len > 32)
        return 0;

    return 1;
}
