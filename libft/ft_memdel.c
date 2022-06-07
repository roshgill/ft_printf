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

/*
The ft_memdel() function takes the address of a memory area that needs to
be freed with free(), then puts the pointer to NULL.
*/
void    ft_memdel(void **memory)
{
    if (!memory || !*memory)
      return;
    free(*memory);
    *memory = NULL;
}