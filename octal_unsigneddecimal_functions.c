#include "ft_printf.h"

/*
1. Take the argument based on the flags given and converts it into a char*
2. Based on the flags, field width, precision, and specifiers, make a solution
*/
int octal_function(char *str, va_list lst, printfdata *sp)
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

    char *converted_input = uint_to_ascii_integer_base(temp_input, 8, sp);
    char *input = octal_precision_solution(sp, converted_input);
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

//Takes in the struct and the string
//Creates a solution based on the precision and the strlen of the string
//Return it to the main string function for it to be completely solved 
char *octal_precision_solution(printfdata *sp, char *input)
{
    int i = 0;
    int j = 0;
    int count;
    char *format;
    int str_len = strlen(input);

    if (sp->precision > str_len)
    {
        if (sp->flags == 0 || sp->flags == '-' || sp->flags == '#' || sp->flags == '0')
        {
            format = malloc(sp->precision + 1 * sizeof(char));
            count = sp->precision - str_len;
            padding_format(&i, count, '0', format);
            format_create(&i, &j, sp->precision, input, format);
        }
        else
            return (format);
    }
    if (sp->precision <= str_len)
    {
        format = malloc(str_len + 1 * sizeof(char));
        if (sp->flags == 0 || sp->flags == '-' || sp->flags == '0')
        {
        }
        else if (sp->flags == '#')
        {   
            format[i] = '0';
            i++;
            str_len += 1;
        }
        format_create(&i, &j, str_len, input, format);
    }
    format[i] = '\0';
    return (format);
}

/*
1. Take the argument based on the flags given and converts it into a char*
2. Based on the flags, field width, precision, and specifiers, make a solution
*/
int unsigned_decimal_integer(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char *format;
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
    
    char *converted_input = uint_to_ascii_integer_base(temp_input, 10, sp);
    char *input = unsigned_decimal_precision_solution(sp, converted_input);
    int str_len = strlen(input);

    if (sp->field_width == 0 || sp->field_width <= str_len)
    {
        format = malloc(str_len + 1 * sizeof(char));
        format_create(&i, &j, str_len, input, format);
    }
    else if (sp->field_width > 0 && sp->field_width > str_len)
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
            padding_format(&i, count, '0', format);
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
char *unsigned_decimal_precision_solution(printfdata *sp, char *input)
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
        else
            return (format);
    }
    else if (sp->precision <= str_len)
    {
        if (sp->flags == 0 || sp->flags == '-' || sp->flags == '0')
        {   
            format = malloc(str_len + 1 * sizeof(char));
            format_create(&i, &j, str_len, input, format);
        }
        else
            return (format);
    }
    format[i] = '\0';
    return (format);
}