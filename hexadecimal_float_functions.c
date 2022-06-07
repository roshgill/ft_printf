#include "ft_printf.h"

/*
1. Take the argument based on the flags given and converts it into a char*
2. Based on the flags, field width, precision, and specifiers, make a solution
*/
int hexadecimal_function(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int j = 0;
    int count = 0;
    intmax_t temp_input;

    if (sp->length == NULL)
        temp_input = (unsigned int)(va_arg(lst, unsigned int));
    else if (strncmp(sp->length, "hh", 2) == 0)
        temp_input = (unsigned char)(va_arg(lst, unsigned int));
    else if (strncmp(sp->length, "h", 1) == 0)
        temp_input = (unsigned short)(va_arg(lst, unsigned int));
    else if (strncmp(sp->length, "ll", 2) == 0)
        temp_input = (unsigned long long)(va_arg(lst, unsigned long long int));
    else if (strncmp(sp->length, "l", 1) == 0)
        temp_input = (unsigned long)(va_arg(lst, unsigned long int));

    char *converted_input = uint_to_ascii_integer_base(temp_input, 16, sp);
    char *input = hexadecimal_precision_solution(sp, converted_input);
    char *format;
    int str_len = strlen(input);

    if (sp->field_width == 0 || sp->field_width <= str_len)
    {
        format = malloc(str_len + 1 * sizeof(char));
        format_create(&i, &j, str_len, input, format);
    }
    else if (sp->field_width > str_len)
    {   
        format = malloc(sp->field_width + 1 * sizeof(char));
        if (sp->flags == 0)
        {
            count = sp->field_width - str_len;
            padding_format(&i, count, ' ', format);
            format_create(&i, &j, sp->field_width, input, format);
        }
        else if (sp->flags == '-')
        {
            format_create(&i, &j, str_len, input, format);
            padding_format(&i, sp->field_width, ' ', format);
        }
        else if (sp->flags == '0' && sp->precision == 0)
        {
            count = sp->field_width - str_len;
            padding_format(&i, count, '0', format);
            format_create(&i, &j, sp->field_width, input, format);
        }
        else if (sp->flags == '0' && sp->precision >= 1)
        {
            count = sp->field_width - str_len;
            padding_format(&i, count, ' ', format);
            format_create(&i, &j, sp->field_width, input, format);
        }
        else if (sp->flags == '#')
        {
            count = sp->field_width - str_len;
            padding_format(&i, count, ' ', format);
            format_create(&i, &j, sp->field_width, input, format);
        }
    }
    format[i] = '\0';
    print_format(format);
    free(format);
    return (0);
}

//Take in the struct and the string
//Create a solution based on the precision and the strlen of the string
//Return it to the main string function for it to be completely solved 
char *hexadecimal_precision_solution(printfdata *sp, char *input)
{
    int i = 0;
    int j = 0;
    int count;
    char *format;
    int str_len = strlen(input);

    if (sp->precision > str_len)
    {
        if (sp->flags == 0 || sp->flags == '-' || sp->flags == '0')
        {
            format = malloc(sp->precision + 1 * sizeof(char));
            count = sp->precision - str_len;
            padding_format(&i, count, '0', format);
            format_create(&i, &j, sp->precision, input, format);
        }
        else if (sp->flags == '#')
        {    
            format = malloc(sp->precision + 3 * sizeof(char));
            format[i++] = '0';
            format[i++] = 'x';
            count = sp->precision - str_len + 2;
            padding_format(&i, count, '0', format);
            format_create(&i, &j, sp->precision+2, input, format);
        }
    }
    if (sp->precision <= str_len)
    {
        if (sp->flags == 0 || sp->flags == '-' || sp->flags == '0')
        {   
            format = malloc(str_len + 1 * sizeof(char));
            format_create(&i, &j, str_len, input, format);
        }
        else if (sp->flags == '#')
        {    
            format = malloc(str_len + 2 * sizeof(char));
            format[i++] = '0';
            format[i++] = 'x';
            format_create(&i, &j, str_len + 2, input, format);
        }
    }
    format[i] = '\0';
    return (format);
}

/*
1. Take the argument based on the flags given and converts it into a char*
2. Round the float number 
3. Bring together the int and float number into one string
4. Based on the flags, field width, precision, and specifiers, make a solution
*/
int decimal_floating_function(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int j = 0;
    int count = 0;
    double temp_input;

    if (sp->length == 0)
        temp_input = (double)va_arg(lst, double);
    else if (strncmp(sp->length, "L", 1) == 0)
        temp_input = (long double)(va_arg(lst, signed long int));

    //Separates the integer and decimal values of the input, converts them to strings, and conjoins them
    float fraction = temp_input - (int) temp_input;
    float the_int = temp_input - fraction;
    char *tinput = float_function(temp_input, sp);
    int tempstrlen = strlen(tinput);
    char *roundedinput = rounding_function(tinput, tempstrlen);
    char *tempascii = ft_itoa(the_int);
    char *input = together_string(tempascii, roundedinput);
    
    int str_len = strlen(input);
    char *format;
    char *positiveinput;
    int new_strlen;

    if (sp->field_width == 0 || sp->field_width <= str_len)
    {
        if (sp->flags == '+' || sp->flags == ' ')
        {
            if (input[0] == '-')
            {
                format = malloc(str_len + 1 * sizeof(char));
                format_create(&i, &j, str_len, input, format);
            }
            else
            {
                format = malloc(str_len + 2 * sizeof(char));
                format[i++] = sp->flags;
                format_create(&i, &j, str_len+1, input, format);
            }
        }
        else
        {
            format = malloc(str_len + 1 * sizeof(char));
            format_create(&i, &j, str_len, input, format);
        }
    }
    if (sp->field_width > str_len)
    {   
        format = malloc(sp->field_width + 1 * sizeof(char));
        if (sp->flags == 0 || sp->flags == ' ' || sp->flags == '#')
        {
            count = sp->field_width - str_len;
            padding_format(&i, count, ' ', format);
            format_create(&i, &j, sp->field_width, input, format);
        }
        else if (sp->flags == '-')
        {
            count = sp->field_width - str_len;
            format_create(&i, &j, str_len, input, format);
            padding_format(&i, sp->field_width, ' ', format);
        }
        else if (sp->flags == '+')
        {
            if (input[0] == '-')
            {
                count = sp->field_width - str_len;
                padding_format(&i, count, ' ', format);
                format_create(&i, &j, sp->field_width, input, format);
            }
            else
            {
                count = sp->field_width - (str_len + 1);
                padding_format(&i, count, ' ', format);
                format[i++] = '+';
                format_create(&i, &j, sp->field_width, input, format);
            }
        }
        else if (sp->flags == '0')
        {
            if (input[0] == '-')
            {
                count = sp->field_width - str_len + 1;
                format[i++] = '-';
                padding_format(&i, count, '0', format);
                j = 1;
                format_create(&i, &j, sp->field_width, input, format);
            }
            else
            {
                count = sp->field_width - str_len;
                padding_format(&i, count, '0', format);
                format_create(&i, &j, sp->field_width, input, format);
            }
        }
    }
    format[i] = '\0';
    print_format(format);
    free(format);
    return (0);
}

//Split the int and the float
//Based on the precision, get the necessary amount of float numbers into our string
//Return the string
char *float_function(float number, printfdata *sp)
{   
    //Initialize Variables
    int i = 0;
    int precision;
    long double fraction = number - (int) number;
    if (fraction < 0)
        fraction *= -1;

    //Check if there is a precision
    //If there is, then that will be how many numbers we want exactly
    //Otherwise the precision will be 6 by default
    if (sp->dot == '.')
        precision = sp->precision;
    else
        precision = 6;

    //Malloc space for the exact amount of numbers we want in our main format
    char *main_format = malloc(precision + 1 * sizeof(char));
    char *temp_format = malloc(precision + 1 * sizeof(char));

    if (precision == 0)
    {
        main_format[i++] = 0;
        main_format[i] = '\0';
        return (main_format);
    }
    //Continue placing digits in our main_format until we've satisified the precision amount
    while (i < precision)
    {
        if (i == precision) 
            return (main_format);
        fraction *= 100;
        temp_format = ft_itoa(fraction);
        while(temp_format[i] != '\0' && i < precision)
        {
            main_format[i] = temp_format[i];
            i++;
        } 
        if (i == precision)
          return (main_format);
    }
    main_format[i] = '\0';
    return (main_format);
}

//Start from the last digit
//If a number is 9 make it 0 and add 1 to the next number
char *rounding_function(char *str, int i)
{
  while (i > -1)
  {
    if (str[i] == '9')
      i = round_function(str, i);
    else
      i--;
  }
  return (str);
}

//Extension of rounding_function
int round_function(char *str, int i)
{
  if (i < 0)
    return (i);
  if (str[i] == '9')
  {
    str[i] = '0';
    i--;
    if (i < 0)
      return (i);
    if (str[i] == '0')
    {
      str[i] = '1';
      i--;
      return (i);
    }
    else if (str[i] == '1')
    {
      str[i] = '2';
      i--;
      return (i);
    }
    else if (str[i] == '2')
    {
      str[i] = '3';
      i--;
      return (i);
    }
    else if (str[i] == '3')
    {
      str[i] = '4';
      i--;
      return (i);
    }
    else if (str[i] == '4')
    {
      str[i] = '5';
      i--;
      return (i);
    }
    else if (str[i] == '5')
    {
      str[i] = '6';
      i--;
      return (i);
    }
    else if (str[i] == '6')
    {
      str[i] = '7';
      i--;
      return (i);
    }
    else if (str[i] == '7')
    {
      str[i] = '8';
      i--;
      return (i);
    }
    else if (str[i] == '8')
    {
      str[i] = '9';
      i--;
      return (i);
    }
    else if (str[i] == '9')
    {
      round_function(str, i);
    }
  }
  return (i);
}

//Concatenate 2 strings
//Return the together string!
char *together_string(char *str, char *str2)
{
    int str_len = strlen(str) + strlen(str2);
    char *str3 = malloc(str_len + 2 * sizeof(char));
    int i = 0;
    int j = 0;
  
    while(i < strlen(str))
    {
        str3[i] = str[i];
        i++;
    }
    str3[i] = '.';
    i++;
    while(i < str_len + 1)
    {
        str3[i] = str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';
    return (str3);
}