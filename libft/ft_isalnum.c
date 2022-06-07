/* ************************************************************************** */
/*                                                                            */
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

/*  The isalnum() function tests for any character for which isalpha(3) or
     isdigit(3) is true.  The value of the argument must be representable as an
     unsigned char or the value of EOF. */

int ft_isalnum(int c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
        return (1);
    else
        return 0;
}

// int main(void)
// {
//     int c = '5';

//     printf("%d", ft_isalnum(c));
// }