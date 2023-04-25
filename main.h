#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


#define OUTPUT_BUFF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
*  struct parameters - parameters struct
*  @unsign: flag if unsigned value
*  @plus_flag: on if_flag specified
*  @minus_flag: on if _flag specified
*  @width: field precision specified
*  @h_modifier: on if h_modifier is specified
*  @l_modifier: on if l_modifier is specified
*/

typedef struct parameters
{
	unsigned int unsign  :1;
	unsigned int plus_flag  :1;
	unsigned int space_flag  :1;
	unsigned int hashtag_flag  :1;
	unsigned int zero_flag  :1;
	unsigned int minus_flag  :1;

	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier  :1;
	unsigned int l_modifier  :1;
} specifier_t;
/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* NUMBER.C */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char*s, params_t *params);
int get_modifier(char *s, params_t *params, va_list ap);
char *get_width(char *s, params_t *params, va_list ap);

/* convert number.c */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c */
void init_params(params_t *params, va_list ap);

/* string_fields.c */
char *get_precision(char *p, params_t *params, va_list ap);
/* _printf.c */
int _printf(const char *format, ...);

#endif
