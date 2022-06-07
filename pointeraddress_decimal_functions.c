#include "ft_printf.h"

/*
1. Take the argument as an unsigned long
2. Based on the flags, field width, precision, and specifiers, make a solution
*/
int pointer_address_function(char *str, va_list lst, printfdata *sp)
{       
    int i = 0;
    int j = 0;
    char *format;
    uintmax_t addr = (unsigned long)(va_arg(lst, unsigned long int));
    char *address = uint_to_ascii_integer_base(addr, 16, sp);
    int str_len = strlen(address) + 2;

    if (sp->field_width == 0 || sp->field_width <= str_len)
    {
        format = malloc((str_len + 1) * sizeof(char));
        format[i++] = '0';
        format[i++] = 'x';
        format_create(&i, &j, str_len, address, format);
    }
    else if (sp->field_width > str_len)
    {
        format = malloc((sp->field_width + 1) * sizeof(char));
        if (sp->flags == '-')
        {
            format[i++] = '0';
            format[i++] = 'x';
            format_create(&i, &j, str_len, address, format);
            padding_format(&i, sp->field_width, ' ', format);
        }
        else
        {
            int count = sp->field_width - str_len;
            padding_format(&i, count, ' ', format);
            count = 0;
            format[i++] = '0';
            format[i++] = 'x';
            format_create(&i, &count, sp->field_width, address, format);
        }
    }
    format[i] = '\0';
    print_format(format);
    free(format);
    return (0);
}

/*
1. Take the argument based on the flags given and converts it into a char*
2. Based on the flags, field width, precision, and specifiers, make a solution
*/
int decimal_function(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char *format;
    intmax_t temp_input;

    if (sp->length == NULL)
        temp_input = va_arg(lst, int);
    else if (strncmp(sp->length, "hh", 2) == 0)
        temp_input = (signed char)(va_arg(lst, int));
    else if (strncmp(sp->length, "h", 1) == 0)
        temp_input = (short)(va_arg(lst, int));
    else if (strncmp(sp->length, "ll", 2) == 0)
        temp_input = (long long)(va_arg(lst, long long int));
    else if (strncmp(sp->length, "l", 1) == 0)
        temp_input = (long)(va_arg(lst, long int));

    char *converted_input = ft_itoa(temp_input);
    char *input = decimal_precision_solution(sp, converted_input, temp_input);
    int str_len = strlen(input);

    if (sp->field_width == 0 || sp->field_width <= str_len)
    {
        format = malloc(str_len + 1 * sizeof(char));
        format_create(&i, &j, str_len, input, format);
    }
    else if (sp->field_width > str_len)
    {   
        format = malloc(sp->field_width + 1 * sizeof(char));
        if (sp->flags == 0 || sp->flags == '+' || sp->flags == ' ' || sp->flags == '#')
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
            if (input[0] == '-')
            {
                count = sp->field_width - str_len + 2;
                format[i++] = '-';
                j=1;
            }
            else
                count = sp->field_width - str_len;

            padding_format(&i, count, '0', format);
            format_create(&i, &j, sp->field_width, input, format);
        }
        else if (sp->flags == '0' && sp->precision > 0)
        {
            if (input[0] == '-')
            {
                count = sp->field_width - str_len;
                padding_format(&i, count, ' ', format);
                format[i++] = '-';
                j=1;
                format_create(&i, &j, sp->field_width, input, format);
            }
            else
            {
                count = sp->field_width - str_len;
                padding_format(&i, count, ' ', format);
                format_create(&i, &j, sp->field_width, input, format);
            }
        }
    }
    format[i] = '\0';
    print_format(format);
    free(format);
    return (0);
}

//Take in the struct, string, and original integer input
//Creates a solution based on the precision and the str_len of the string
//Return it to the main decimal function for it to be completely solved
char *decimal_precision_solution(printfdata *sp, char *input, intmax_t temp_input)
{
    int i = 0;
    int j = 0;
    int str_len = strlen(input);
    char *format;

    if (sp->precision > str_len)
    {
        int count;

        if (sp->flags == 0 || sp->flags == '-' || sp->flags == '0' || sp->flags == '#')
        {
            if (input[0] == '-')
            {
                format = malloc(sp->precision + 2 * sizeof(char));
                count = sp->precision - str_len + 2;
                format[i++] = '-';
                j=1;
                sp->precision += 1;
            }
            else
            {
                format = malloc(sp->precision + 1 * sizeof(char));
                count = sp->precision - str_len;
            }
            padding_format(&i, count, '0', format);
            format_create(&i, &j, sp->precision, input, format);
        }
        else if (sp->flags == '+')
        {
            format = malloc(sp->precision + 2 * sizeof(char));
            count = sp->precision - str_len + 2;
            if (input[0] == '-')
                format[i++] = '-';
            else
                format[i++] = '+';
            j=1;
            sp->precision += 1;

            padding_format(&i, count, '0', format);
            format_create(&i, &j, sp->precision, input, format);
        }
        else if (sp->flags == ' ')
        {
            if (input[0] == '-')
            {
                format = malloc(sp->precision + 2 * sizeof(char));
                count = sp->precision - str_len + 2;
                j=1;
                sp->precision += 1;
                format[i++] = '-';
                padding_format(&i, count, '0', format);
            }
            else
            {
                format = malloc(sp->precision + 2 * sizeof(char));
                format[i++] = ' ';
                count = sp->precision - str_len + 1;
                padding_format(&i, count, '0', format);
                sp->precision += 1;
            }
            format_create(&i, &j, sp->precision, input, format);
        }
    }
    else if (sp->precision <= str_len)
    {
        if (sp->flags == '+' || sp->flags == ' ')
        {
            if (input[0] != '-')
            {
                format = malloc(str_len + 2 * sizeof(char));
                format[i] = sp->flags;
                i++;
                format_create(&i, &j, str_len+1, input, format);
            }
            else
            {
                format = malloc(str_len + 1 * sizeof(char));
                format_create(&i, &j, str_len, input, format);
            }
        }
        else
        {
            format = malloc(str_len + 1 * sizeof(char));
            format_create(&i, &j, str_len, input, format);
        }
    }
    format[i] = '\0';
    return (format);
}