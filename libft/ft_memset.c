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

/* ft_memset. The memset() function fills the first 
  n bytes of the memory area pointed to by s with 
  the constant byte c. The memset() function returns 
  a pointer to the memory area b. */

void    *ft_memset(void *a, int c, int len)
{
  char *ptr = a;
  
  while(len > 0)
  {
    *(ptr++) = c;
    len--;
  }
  return(a);
}

// int main() {
//   char *a = (char*)malloc(5 * sizeof(char));
//   void *new = ft_memset(a, 'k', 5);
//   return 0;
// }