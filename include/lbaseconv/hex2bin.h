/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#ifndef __HEX2BIN_H__
#define __HEX2BIN_H__
#include <stddef.h>

#include "util/string.h"

string_t htob(const char *s, size_t len);

#endif /* __HEX2BIN_H__ */
