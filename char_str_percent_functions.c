#include "ft_printf.h"

/*
1. Take the character starting_input as an int
2. Check the field width first and malloc the exact amount of space needed into the format
3. Based on the flags, solve for the output
*/
int char_function(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int character = va_arg(lst, int);
    char *format;

    if (sp->field_width <= 1)
    {
        format = malloc(2 * sizeof(char));
        format[0] = character;
        format[1] = '\0';
    }
    else
    {
        format = malloc(sp->field_width + 1 * sizeof(char));
        if (sp->flags == '-')
        {
            format[i++] = character;
            padding_format(&i, sp->field_width, ' ', format);
        }
        else
        {
            padding_format(&i, sp->field_width-1, ' ', format);
            format[i++] = character;
        }
        format[i] = '\0';
    }
    print_format(format);
    free(format);
    return (0);
}

/*
1. Take the starting_input and save it as a char*
2. Based on the flags, field width, precision, and specifiers, create a solution that works with the string conversion
3. Solve for the output
*/
int string_function(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int j = 0;
    char *starting_input = va_arg(lst, char*);
    char *optimized_input = string_precision_solution(sp, starting_input);
    int str_len = strlen(optimized_input);
    char *format;

    if (sp->field_width < str_len)
    {
        format = malloc(str_len + 1 * sizeof(char));
        format_create(&i, &j, str_len, optimized_input, format);
    }
    else if (sp->field_width >= str_len)
    {   
        format = malloc(sp->field_width + 1 * sizeof(char));
        if (sp->flags == '-')
        {
            format_create(&i, &j, str_len, optimized_input, format);
            padding_format(&i, sp->field_width, ' ', format);
        }
        else
        {
            int count = sp->field_width - str_len;
            padding_format(&i, count, ' ', format);
            format_create(&i, &j, sp->field_width, optimized_input, format);
        }
    }
    format[i] = '\0';
    print_format(format);
    free(format);
    return (0);
}

/*
1. Take in the struct and the string
2. Create a solution based on the precision and the length of the string
3. Return it to the main string function for it to be completely solved 
*/
char *string_precision_solution(printfdata *sp, char *starting_input)
{
    int i = 0;
    int j = 0;
    int str_len = strlen(starting_input);
    char *format;

    if (sp->precision >= str_len || sp->precision <= 0)
    {
        format = malloc(str_len + 1 * sizeof(char));
        format_create(&i, &j, str_len, starting_input, format);
    }
    else if (sp->precision < str_len)
    {
        format = malloc(sp->precision + 1 * sizeof(char));
        format_create(&i, &j, sp->precision, starting_input, format);
    }
    format[i] = '\0';
    return (format);
}

/*
1. Solve for percent(%) conversion
*/
int percent_function(char *str, va_list lst, printfdata *sp)
{
    char *format;
    int i = 0;

    if (sp->field_width <= 1)
    {
        format = malloc(2 * sizeof(char));
        format[0] = '%';
        format[1] = '\0';
    }
    else
    {
        format = malloc(sp->field_width + 1 * sizeof(char));
        if (sp->flags == '-')
        {
            format[i++] = '%';
            padding_format(&i, sp->field_width, ' ', format);
        }
        else
        {
            padding_format(&i, sp->field_width-1, ' ', format);
            format[i++] = '%';
        }
        format[i] = '\0';
    }
    print_format(format);
    free(format);
    return (0);
}