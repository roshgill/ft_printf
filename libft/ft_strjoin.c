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

//Concatenate two strings

char    *ft_strjoin(char *s1, char *s2)
{
  int len = ft_strlen(s1) + ft_strlen(s2);

  char *final_string = (char*) malloc(len+1 * sizeof(char));
  int i = 0;
  
  while(s1[i])
  {
    final_string[i] = s1[i];
    i++;
  }
  int j = i;
  i = 0;
  
  while(s2[i])
  {
    final_string[j] = s2[i];
    i++;
    j++;
  }
  final_string[j] = '\0';
  return(final_string);
}

// int main() {
//   char *new = ft_strjoin("Roshanknn,mnzc879qew", "  jhjkasu8a897  wjhjhk");
//   return 0;
// }