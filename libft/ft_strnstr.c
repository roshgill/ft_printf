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

/*   strnstr - locate a substring in a string 
     The strnstr() function locates the first occurrence of the null-terminated
     string needle in the string haystack, where not more than len characters
     are searched. Characters that appear after a ‘\0’ character are not
     searched. Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.  
 */

char *ft_strnstr(char *str, char *needle, int c)
{
    int i = 0;
    
    while (i < c)
    {
        if (str[i]=='\0')
          return (NULL);
        
        if (str[i] == needle[0])
        {
          int n_count = 0;
          int sub_count = i;
          char *save_location = &str[i];
          
          while (str[sub_count] == needle[n_count])
          {
            if (needle[n_count+1]=='\0')
              return (save_location); 
            sub_count++;
            n_count++;
          }
        }
        i++;
    }
    return(NULL);
}

// int main(void)
// {
//   char *str = ft_strnstr("Roshan is so so cool", "so", 20); 
//   return(0);
// }