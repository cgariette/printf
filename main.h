#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

int get_width(const char *format, int *i, va_list list);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/**
 * struct fmt - Structure
 *
 * @fmt: the format
 * @fn: The function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: format
 * @fn: function associated
 */
typedef struct fmt fmt_t;

int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int _printf(const char *format, ...);


/* print unsigned int */
int print_unsigned(va_list types, char buffer[],
                int flags, int width, int precision, int size);

/* prints unsigned number in octal */
int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* prints unsigned number in hexadecimal */
int print_hexadecimal(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print unsigned number in upper hexadecimal */
int print_hexa_upper(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* prints hex number in lower or upper */
iint print_hexa(va_list types, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size);

#endif
