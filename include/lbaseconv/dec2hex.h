/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#ifndef __DEC2HEX_H__
#define __DEC2HEX_H__
#include <stddef.h>

struct string_t dec2hex(const char *s, size_t len);
struct string_t dtoh(long decimal);
enum ascii_hex_t get_ascii_hex(int n);
void insert_hex_char(char *s, long num, int pos);

#endif /* __DEC2HEX_H__ */
