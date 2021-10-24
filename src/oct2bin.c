/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/oct2bin.h"

#include "lbaseconv/oct2dec.h"
#include "lbaseconv/dec2bin.h"

int oct2bin_input_ok(const char *s, size_t len);

string_t otob(const char *s, size_t len)
{
    int i;
    unsigned long decimal;
    string_t s_bin;

    if (!s || len == 0 || *s == '\0') {
        s_bin.data = NULL;
        s_bin.len = 0;
        return s_bin;
    }

    if (s[0] == '0' && (s[1] == 'o' || s[1] == 'O'))
        i = 2;
    else if (s[0] == '0')
        i = 1;
    else
        i = 0;

    if(!oct2bin_input_ok(s+i, len)){
        s_bin.data = NULL;
        s_bin.len = 0;
        return s_bin;
    }

    decimal = otod(s+i, len);
    s_bin = dtob(decimal);

    return s_bin;
}

int oct2bin_input_ok(const char *s, size_t len)
{
    int i;

    if(len > 10)
        return 0;

    for(i = 0; s[i] != '\0'; ++i)
        if(s[i] - '0' > 7)
            return 0;

    return 1;
}
