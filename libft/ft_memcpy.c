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

/* The memcpy() function copies n 
   bytes from memory area src to memory area dest. 
   The memory areas must not overlap. ... The memcpy() 
   function returns a pointer to dst. */

void *ft_memcpy(void *dest, const void *src, int len)
{
  char *ptr = (char*)src;
  char *ptr2 = (char*)dest;
  
  while(len > 0)
  {
    char tmp = *(ptr++);
    *(ptr2++) = tmp;
    len--;
  }
  return(dest);
}

// int main() 
// {
//   char *src = "Roshan";
//   char *dest = (char*)malloc(6 * sizeof(char));
  
//   void *new = ft_memcpy(dest, src, 6);
//   return 0;
// }