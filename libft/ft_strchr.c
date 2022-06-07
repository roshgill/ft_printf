/*                                                        :::      ::::::::   */
/*                                         			   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:43:57 by rosgill           #+#    #+#             */
/*   Updated: 2021/11/10 15:59:51 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The C library function char *strrchr(const char *str, int c) 
searches for the last occurrence of the character c (an unsigned char) 
in the string pointed to, by the argument str. */

char *ft_strchr(char *str, int c)
{
    int i = ft_strlen(str);

    while (i >= 0)
    {
        if (str[i] == c)
        {
            char *point_to_location = &str[i];
            return (point_to_location);
        }
        i--;
    }
    return(NULL);
}

// int main(void)
// {
//     char *location = ft_strchr("Roshaniscool",'i');
//     return(0);
// }