/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/oct2hex.h"

#include <stdlib.h>

#include "lbaseconv/oct2dec.h"
#include "lbaseconv/dec2hex.h"

int oct2hex_input_ok(const char *s, size_t len);

string_t otoh(const char *s, size_t len)
{
    int i;
    unsigned long dec;
    string_t s_hex;


    if(!s || len == 0 || *s == '\0') {
        s_hex.data = NULL;
        s_hex.len = 0;
        return s_hex;
    }

    if (s[0] == '0' && (s[1] == 'o' || s[1] == 'O'))
        i = 2;
    else if (s[0] == '0')
        i = 1;
    else
        i = 0;

    if (!oct2hex_input_ok(s+i, len)) {
        s_hex.data = NULL;
        s_hex.len = 0;
        return s_hex;
    }

    dec = otod(s+i, len);
    if(dec == -1){
        s_hex.data = NULL;
        s_hex.len = 0;
        return s_hex;
    }

    s_hex = dtoh(dec);
    return s_hex;
}

int oct2hex_input_ok(const char *s, size_t len)
{
    int i;

    if(len > 10)
        return 0;

    for(i = 0; s[i] != '\0'; ++i)
        if(s[i] - '0' > 7)
            return 0;

    return 1;
}
