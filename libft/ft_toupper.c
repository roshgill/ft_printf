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

//Converts every lowercase letter to uppercase via ascii manipulation

int ft_toupper(int c)
{
    if (c >= 'a' && c<= 'z')
    {
        c = c - 32;
        return(c);
    }
    return(0);
}

// int main(void)
// {   
//     int c = 'h';
//     printf("%c", ft_upper(c));
//     return(0);
// }