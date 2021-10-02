/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/oct2bin.h"

#include "lbaseconv/util/string.h"
#include "lbaseconv/oct2dec.h"
#include "lbaseconv/dec2bin.h"

string_t otob(const char *s)
{
    int decimal;
    string_t s_bin;

    decimal = otoi(s);
    s_bin = dtob(decimal);

    return s_bin;
}
