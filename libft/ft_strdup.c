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
Take in string, duplicate it into new string, and return a pointer to it
*/

char *ft_strdup(char *str)
{
  int len = ft_strlen(str);
  char *newstr = malloc(sizeof(char) * (len + 1));
  int i = 0;
  
  while(str[i])
  {
    newstr[i] = str[i];
    i++;
  }
  newstr[i] = '\0';
  return(newstr);
}