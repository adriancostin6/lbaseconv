/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#ifndef __DEC2HEX_H__
#define __DEC2HEX_H__
#include <stddef.h>

#include "util/string.h"
#include "util/ascii_hex.h"

string_t dec2hex(const char *s, size_t len);
string_t dtoh(unsigned long decimal);
ascii_hex_t get_ascii_hex(int n);
void insert_hex_char(char *s, unsigned long num, int pos);

#endif /* __DEC2HEX_H__ */
