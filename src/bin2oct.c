/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/bin2oct.h"

#include "lbaseconv/bin2int.h"
#include "lbaseconv/dec2oct.h"

int bin2oct_input_ok(const char *s, size_t len);

/* converts binary string to octal; returns octal string*/
long btoo(const char *s, size_t len)
{
    int i;
    long result, dec;

    if (!s || len == 0 || *s == '\0')
        return -1;

    if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B'))
        i = 2;
    else
        i = 0;

    if (!bin2oct_input_ok(s+i, len))
        return -1;

    dec = btoi(s+i, len);
    if (dec == -1)
        return -1;

    result = dtoo(dec);
    return result;
}

int bin2oct_input_ok(const char *s, size_t len)
{
    if(len > 32)
        return 0;

    return 1;
}
