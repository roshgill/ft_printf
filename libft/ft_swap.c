/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:43:57 by rosgill           #+#    #+#             */
/*   Updated: 2021/11/10 15:59:51 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap the pointer addresses of two integer pointer variables
   This will allow us to swap variables without wasting time/memory through a manual switch */

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int main(void)
// {
// 	int num1 = 10;
// 	int num2 = 2000;

// 	int* a = &num1;
// 	int* b = &num2;

// 	ft_swap(a,b);
// 	printf("%d\n", *b);
// 	printf("%d", *a);
// }