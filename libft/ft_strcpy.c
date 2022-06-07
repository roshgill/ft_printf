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

//Copy string into another string variable

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// int		main(void)
// {
// 	char str1[] = "Roshan";
// 	char str2[] = "Gill";

// 	printf("%s\n", str1);
// 	ft_strcpy(str1, str2);
// 	printf("%s\n", str1);
// 	return (0);
// }