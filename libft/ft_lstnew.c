/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                        :+:      :+:   :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:43:57 by rosgill           #+#    #+#             */
/*   Updated: 2021/11/10 15:59:51 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Take in data, initialize new node and its size, set data points and return the node

void *ft_lstnew(void *data)
{
  node_create *node = NULL;
  node = (node_create *) malloc(sizeof(node_create));
  if (node == NULL) 
    return NULL;
  node->data = data;
  node->next = NULL;
  return(node);
}

/* Run function, get a return list value*/
// int main(void) 
// {
//   char *name = "Roshan";
//   node_create *first_node = ft_lstnew(name);
//   return(0);
// }