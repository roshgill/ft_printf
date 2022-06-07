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

//Converts every uppercase letter to lowercase via ascii manipulation

int ft_tolower(int c)
{
    if (c >= 'A' && c<= 'Z')
    {
        c = c + 32;
        return(c);
    }
    return(0);
}

// int main(void)
// {   
//     int c = 'Z';
//     printf("%c", ft_lower(c));
//     return(0);
// }