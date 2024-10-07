#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "stdarg.h"

void string_mode(char *str, int *counter,int *counter3,int *counter4);
void char_mode(int c, int *counter,int *counter3,int *counter4);
void int_mode(int integer,int *counter,int *counter3,int *counter4);
void unsigned_int_mode(unsigned int integer, int *counter,int *counter3,int *counter4);
void pointer_mode(void *pointer, int *counter,int *counter3, int *counter4);
void hexadecimal_mode(unsigned int integer, int *counter,int *counter3, int *counter4);

#endif