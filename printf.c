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

#include "ft_printf.h"
/*
Notes: 
1. Free all malloc'ed data

*/

/* Main parser:
1. Find % then save all data after into struct
2. When we get to the conversion, run specific function and solve for the output
3. Continue through the loop until every solution is found, solved and outputted
*/
int ft_printf(char *format, ...)
{
  char *str;
  printfdata *sp;
  va_list lst;

  sp = malloc(sizeof(printfdata));
  sp->counter = 0;
  va_start(lst, format);
  str = (char*)format;
  while (str[sp->counter] != '\0')
  {
    if (str[sp->counter] == '%')
    {   
      reset_struct(sp);
      sp->counter++;
      flag_checker(str, lst, sp);
    }
    else
      write(1, &str[sp->counter], 1);
    sp->counter++;
  }
  va_end(lst);
  free(sp);
  return (0);
}

//Reset data held in struct everytime around; reuse it for the next solution
void reset_struct(printfdata *sp)
{
    sp->flags = 0;
    sp->field_width = 0;
    sp->precision = 0;
    sp->dot = 0;
    sp->length = NULL; 
    sp->conversion = 0;
}

//Based on the specific inputs, pad the main char *format with the specified variables (ex. '0', ' ')
void padding_format(int *i, int count, int variable_padding, char *format)
{
  while (*i < count)
  {
    format[*i] = variable_padding;
    *i += 1;
  }
}

//Take in specific values conjured by conversion algorthms and transfer input values into char *format
void format_create(int *i, int *j, int str_len, char *input, char *format)
{
  while (*i < str_len)
  {
    format[*i] = input[*j];
    *i += 1;
    *j += 1;
  }
}

//Once a solution is created, print it out on the standard output
int print_format(char *format)
{
  int i = 0;

  while(format[i])
  {
    write(1, &format[i], 1);
    i++;
  }
  return (0);
}

//Converts an int to an ascii
char *ft_itoa(signed long long int num)
{
  char *str;
  long    n;
  int     i;

  n = num;
  i = len(n);
  if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
    return (NULL);
  str[i--] = '\0';
  if (n == 0)
  {
    str[0] = 48;
    return (str);
  }
  if (n < 0)
  {
    str[0] = '-';
    n = n * -1;
  }
  while (n > 0)
  {
    str[i] = 48 + (n % 10);
    n = n / 10;
    i--;
  }
  return(str);
}

//Get length
int len(signed long long num)
{
  int len;

  len = 0;
  if (num < 0)
  {
    num = num * -1;
    len++;
  }
  while (num > 0)
  {
    num = num / 10;
    len++;
  }
  return (len);
}

//Unsigned int to ascii base
//Will take in a number and return the type base number you want in a char format
char  *uint_to_ascii_integer_base(unsigned long long int number, int base, printfdata *sp)
{
    int i = 0;
    int j = 0;
    int len = get_base_len(number, base); 
    char *str = ft_strnew(len);
    char *finalstr = ft_strnew(len);
  
    if (str == NULL)
    {
        free(str);
        return (NULL);
    }
    if (number == 0)
        str[0] = '0';
    while(number != 0 && len >= 0)
    {
        if (number % base < 10)
        {
        str[i] = number % base + 48;
        i++;
        }
        else if (number % base >= 10)
        {
        if (sp->conversion == 'X')
            str[i] = number % base + 55;
        else 
            str[i] = number % base + 87;
        i++;
        }
    number = number / base;
    }
    i--;
    while(j < len)
        finalstr[j++] = str[i--];
    return(finalstr);
}

//Gets the exact length we need
int get_base_len(unsigned long long int number, int base)
{
    int len = 0;
  
    while(number != 0)
    {
      number = number / base;
      len++;
    }
    return (len);
}

//Creates a fresh string where we will place our solved variables
char  *ft_strnew(size_t size)
{
    char *result;
    int i = 0;

    result = (char*)malloc(size + 1 * sizeof(*result));
    if (!result)
        return (NULL);
    else
    {
        while (i <= size)
        {
            result[i] = '\0';
            i++;
        }
        return (result);
    }
}