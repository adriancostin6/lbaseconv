/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#ifndef __DEC2BIN_H__
#define __DEC2BIN_H__
#include <stddef.h>

#include "util/string.h"

string_t dec2bin(const char *s, size_t len);
string_t dtob(unsigned long decimal);
void insert_binary_char(char *s, unsigned long num, int pos);

#endif /* __DEC2BIN_H__ */
