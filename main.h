#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
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
int print_hexa(va_list types, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size);

/* print character */
int print_char(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print a string */
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print percent sign */
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print int */
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print binary */
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print Pointer */
int print_pointer(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print non printable */
int print_non_printable(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print reverse */
int print_reverse(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print a string in rot13 */
int print_rot13string(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* write handler */
int handle_write_char(char c, char buffer[],
        int flags, int width, int precision, int size);

/* write number */
int write_number(int is_negative, int ind, char buffer[],
        int flags, int width, int precision, int size);

/* write number using a buffer */
int write_num(int ind, char buffer[],
        int flags, int width, int prec,
        int length, char padd, char extra_c);

/* writes unsigned number */
int write_unsgnd(int is_negative, int ind,
        char buffer[],
        int flags, int width, int precision, int size);

/* writes a memory address */
int write_pointer(char buffer[], int ind, int length,
        int width, int flags, char padd, char extra_c, int padd_start);

/* Evaluates if character is printable */
int is_printable(char c);

/* Appends ascci in hexadecimal code to buffer */
int append_hexa_code(char ascii_code, char buffer[], int i);

/* checks if character is a digit */
int is_digit(char c);

/* casts a number to the specified size */
long int convert_size_number(long int num, int size);

/* casts anumber to specified size */

long int convert_size_unsgnd(unsigned long int num, int size);

#endif
