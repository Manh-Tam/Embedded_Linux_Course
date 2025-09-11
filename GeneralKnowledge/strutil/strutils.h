#ifndef __STRUTILS_H__
#define __STRUTILS_H__
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void str_reverse(char *str, int n);
char* str_trim(char *str, int n);
int str_to_int(char *str);

#endif