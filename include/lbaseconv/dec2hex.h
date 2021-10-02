/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#ifndef __DEC2HEX_H__
#define __DEC2HEX_H__

struct string_t dtoh(int decimal);
enum ascii_hex_t get_ascii_hex(int n);
void insert_hex_char(char *s, int num, int pos);

#endif /* __DEC2HEX_H__ */
