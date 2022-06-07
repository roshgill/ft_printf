#include "ft_printf.h"

//Checks for flags, and saves to the struct
int   flag_checker(char *str, va_list lst, printfdata *sp)
{
    if (str[sp->counter] == '-' || str[sp->counter] == '+' || str[sp->counter] == ' ' || str[sp->counter] == '#' || str[sp->counter] == '0')
    {
        sp->flags = str[sp->counter]; 
        sp->counter++;
    }
    field_width_checker(str, lst, sp);
    return (0);
}

//Checks for field_width, and saves to the struct
int    field_width_checker(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int size = 3;

    if (str[sp->counter] >= '1' && str[sp->counter] <= '9')
    {   
        char *width = malloc(2 * sizeof(char));
        width[i] = str[sp->counter];
        sp->counter++;
        i++;
        while (str[sp->counter] >= '0' && str[sp->counter] <= '9')
        {
            width = realloc(width, size * sizeof(char));
            width[i] = str[sp->counter];
            sp->counter++;
            i++;
            size++;
        }
        width[i] = '\0';
        sp->field_width = atoi(width);
        free(width);
    }
    else if (str[sp->counter] == '0')
        sp->counter++;
    if (str[sp->counter] == '*')
    {
        sp->field_width = va_arg(lst, int);
        sp->counter++;
    }
    precision_checker(str, lst, sp);
    return (0);
}

//Check for precision, save it to struct
int    precision_checker(char *str, va_list lst, printfdata *sp)
{
    if (str[sp->counter] == '.')
    {
        sp->dot = str[sp->counter];
        int i = 0;
        int size = 3;
        sp->counter++;

        if (str[sp->counter] >= '0' && str[sp->counter] <= '9')
        {   
            char *field_width = malloc(2 * sizeof(char));
            field_width[i] = str[sp->counter];
            sp->counter++;
            i++;

            while (str[sp->counter] >= '0' && str[sp->counter] <= '9')
            {
                field_width = realloc(field_width, size * sizeof(char));
                field_width[i] = str[sp->counter];
                sp->counter++;
                i++;
                size++;
            }
            field_width[i] = '\0';
            sp->precision = atoi(field_width);
            free(field_width);
        }
        else if (str[sp->counter] == '*')
        {
            sp->precision = va_arg(lst, int);
            sp->counter++;
        }
    }
    length_checker(str, lst, sp);
    return (0);
}

//Checks for length, saves it to struct (hh, h, l, ll, L)
int    length_checker(char *str, va_list lst, printfdata *sp)
{
    int i = 0;
    int size = 3;
    char *field_width;

    if (str[sp->counter] == 'L')
    {
        field_width = malloc(2 * sizeof(char));
        field_width[i] = str[sp->counter];
        i++;
        sp->counter++;
        field_width[i] = '\0';
        sp->length = strdup(field_width);
        free(field_width);
    }
    else if (str[sp->counter] == 'l' || str[sp->counter] == 'h')
    {   
        field_width = malloc(2 * sizeof(char));
        field_width[i] = str[sp->counter];
        sp->counter++;
        i++;

        if (str[sp->counter] == 'l' || str[sp->counter] == 'h')
        {
            field_width = realloc(field_width, size * sizeof(char));
            field_width[i] = str[sp->counter];
            sp->counter++;
            i++;
        }
        field_width[i] = '\0';
        sp->length = strdup(field_width);
        free(field_width);
    }
    conversion_checker(str, lst, sp);
    return (0);
}

//Checks for the conversion and runs the appropriate function
int    conversion_checker(char *str, va_list lst, printfdata *sp)
{
    if (str[sp->counter] == 'c')
        char_function(str, lst, sp);
    else if (str[sp->counter] == 's')
        string_function(str, lst, sp);
    else if (str[sp->counter] == '%')
        percent_function(str, lst, sp);
    else if (str[sp->counter] == 'p')
        pointer_address_function(str, lst, sp);
    else if (str[sp->counter] == 'd' || str[sp->counter] == 'i')
        decimal_function(str, lst, sp);
    else if (str[sp->counter] == 'o')
        octal_function(str, lst, sp);
    else if (str[sp->counter] == 'u')
        unsigned_decimal_integer(str, lst, sp);
    else if (str[sp->counter] == 'x' || str[sp->counter] == 'X')
    {
        sp->conversion = str[sp->counter];
        hexadecimal_function(str, lst, sp);
    }
    else if (str[sp->counter] == 'f')
        decimal_floating_function(str, lst, sp);
    return (0);
}