/*                                                        :::      ::::::::   */
/*                                         			        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:43:57 by rosgill           #+#    #+#             */
/*   Updated: 2021/11/10 15:59:51 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
  DESCRIPTION
  Allocates (with malloc(3)) and returns an array of strings obtained by 
  splitting ’s’ using the character ’c’ as a delimiter. The array must be
  ended by a NULL pointer.
  
  PARAMETERS
  #1. The string to be split.
  #2. The delimiter character.
  
  RETURN VALUES
  The array of new strings resulting from the split. 
  NULL if the allocation fails.

  Incomplete: Unable to save newly separated strings into an dynamic array
*/

/*
  1. Initialize integer from the pointer to second counter and fresh string counter
  2. Copy characters into fresh string While the second counter value catches up to the main counter
  3. Set last array value in fresh string to NULL value
  4. Access the second count through the pointer and initliaze its new value
  5. For now I am not able to create a dynamically allocating array for where
  I can save the strings into; instead I printed them out
*/

void copy_string(char *str1, char *str2, int m_count, int *pointer_s_count)
{ 
  int copy_count = (*pointer_s_count);
  int str2_count = 0;
  
  while(copy_count < m_count)
  {
    str2[str2_count] = str1[copy_count];
    copy_count++;
    str2_count++;
  }
  str2[str2_count] = '\0';
  *pointer_s_count = copy_count+1;
  printf("%s\n", str2);
  free(str2);
}

/*
1. Take in the given string and delimiter
2. Initialize a counter for the main string and store the address of the second counter in a
pointer variable (we can then indirectly access/change it easily in other functions)
3. Find the delimiter in the string; once found, allocate exact space needed for new string
3. Send the original string, fresh allocated string, main counter, and pointer to second counter to 
split function where the word will be copied into fresh string
*/

void ft_split(char *str1, char c)
{
  int m_count = 0;
  int s_count = 0;
  int *pointer_s_count = &s_count;
  
  while(str1[m_count])
  {
    if (str1[m_count] == c)
    {
      char *str2 = (char*)malloc((m_count-(*pointer_s_count)+1)*sizeof(char));
      copy_string(str1, str2, m_count, pointer_s_count);
    }
    m_count++;
  }
  char *str2 = (char*)malloc((m_count-(*pointer_s_count)+1)*sizeof(char));
  copy_string(str1, str2, m_count, pointer_s_count);
}

// int main() 
// {  
//   char *str1 = "Roshan Cool Beans jsdalkjjkldsalkjs sadkljjksadjklsd skldjajkdasjlk dskjlajklsadljkdsajlkdjsklc.,.,.,.,,.";
//   char c = ' ';
  
//   ft_split(str1, c);
// }