/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:02:25 by rosgill           #+#    #+#             */
/*   Updated: 2022/06/01 12:04:16 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Initialize Header File
2. Import libraries needed
*/

#ifndef PRINTF_H
#define PRINTF_H
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

//Data structure to store inputs
typedef struct s_list
{
    int  counter;       //Keeps count as we traverse printf
    int  flags;         //+, -, ' ', #, 0
    int  field_width;   //A number that pre-defines space in the output
    int  precision;     //Specifies the minimum numbers of digits to be written
    int  dot;           // '.'
    char *length;       //hh, h, l, ll, L 
    int  conversion;    //c, s, p, d, i, o, u, x, X, f
} printfdata;

int    main(void);
int    ft_printf(char *format, ...);
void   reset_struct(printfdata *sp);
void   padding_format(int *i, int count, int variable_padding, char *format); 
void   format_create(int *i, int *j, int str_len, char *input, char *format);
char   *ft_itoa(signed long long int num);
int    len(signed long long num);
char   *uint_to_ascii_integer_base(unsigned long long int number, int base, printfdata *sp);
int    get_base_len(unsigned long long int number, int base);
char   *ft_strnew(size_t size);
int    flag_checker(char *str, va_list lst, printfdata *sp);
int    field_width_checker(char *str, va_list lst, printfdata *sp);
int    precision_checker(char *str, va_list lst, printfdata *sp);
int    length_checker(char *str, va_list lst, printfdata *sp); 
int    conversion_checker(char *str, va_list lst, printfdata *sp);
int    print_format(char *format);
int    char_function(char *str, va_list lst, printfdata *sp);
int    string_function(char *str, va_list lst, printfdata *sp);
char   *string_precision_solution(printfdata *sp, char *input);
int    percent_function(char *str, va_list lst, printfdata *sp);
int    pointer_address_function(char *str, va_list lst, printfdata *sp);
int    decimal_function(char *str, va_list lst, printfdata *sp);
char   *decimal_precision_solution(printfdata *sp, char *input, intmax_t temp_input);
int    octal_function(char *str, va_list lst, printfdata *sp);
char   *octal_precision_solution(printfdata *sp, char *input);
int    unsigned_decimal_integer(char *str, va_list lst, printfdata *sp);
char   *unsigned_decimal_precision_solution(printfdata *sp, char *input);
int    hexadecimal_function(char *str, va_list lst, printfdata *sp);
char   *hexadecimal_precision_solution(printfdata *sp, char *input);
int    decimal_floating_function(char *str, va_list lst, printfdata *sp);
char   *float_function(float number, printfdata *sp);
char   *rounding_function(char *str, int i);
int    round_function(char *str, int i);
char   *together_string(char *str, char *str2);

#endif