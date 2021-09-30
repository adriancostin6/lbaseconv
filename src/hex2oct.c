/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/hex2oct.h"

#include <stdlib.h>

#include "lbaseconv/util/string.h"
#include "lbaseconv/hex2bin.h"
#include "lbaseconv/bin2oct.h"

String htoo(const char* s)
{
    String s_bin, s_oct;

    s_bin = htob(s);
    s_oct = btoo(s_bin.data);

    free(s_bin.data);

    return s_oct;
}
