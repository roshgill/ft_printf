/* ************************************************************************** */
/*                                                                            */
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

//Convert string integer value to actual integer value

int		ft_atoi(char *str)
{
	int i = 0;
	int number = 0;
	int negative_check = 0;

	if (str[i] == '-')
	{	negative_check = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	if (negative_check == 1)
		return (number*-1);
	return (number);
}

// int main(void)
// {
// 	printf("%d", ft_atoi("-32123"));
// 	return (0);
// }