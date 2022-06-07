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

//ft_lstadd adds an element at the beginning of a list.

void *ft_lstadd(void *head, void *data)
{
  node_create *node = NULL;
  node = (node_create *) malloc(sizeof(node_create));
  
  if (node == NULL) 
    return NULL;
  node->data = data;
  node->next = head;
  return(node);
}

// int main(void) 
// {
//   char *name = "Roshan";
//   char *name2 = "Ekisha";
//   char *name3 = "Jasbir";
  
//   node_create *head = ft_lstnew(name);
//   node_create *newhead = ft_lstadd(head,name2);
//   node_create *newest_head = ft_lstadd(newhead,name3);

//   print("%s", newest_head->data);
  
//   return(0);
// }