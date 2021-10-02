/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/oct2hex.h"

#include <stdlib.h>

#include "lbaseconv/util/string.h"
#include "lbaseconv/oct2dec.h"
#include "lbaseconv/dec2bin.h"
#include "lbaseconv/util/invert_string.h"
#include "lbaseconv/bin2hex.h"

string_t otoh(const char *s)
{
    int decimal;
    string_t s_bin, s_hex;

    decimal = otoi(s);
    s_bin = dtob(decimal);
    invert_string(s_bin.data, s_bin.len);
    s_hex = btoh(s_bin.data);

    string_t_dtor(s_bin);

    return s_hex;
}
