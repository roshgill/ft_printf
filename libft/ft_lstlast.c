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

//ft_lstlast returns last element of a list

void *ft_lstlast(void *head)
{
  node_create *tmp = NULL;
  tmp = (node_create *) malloc(sizeof(node_create));
  tmp = head;
  
  while(tmp->next != NULL) 
    tmp = tmp->next;
  return(tmp);
}

//Create a linked list with 3 nodes and return the last node

// int main(void) 
// {
//   char *name = "Roshan";
//   char *name2 = "Ekisha";
//   char *name3 = "Jasbir";
  
//   node_create *head = ft_lstnew(name);
//   node_create *newhead = ft_lstadd(head,name2);
//   node_create *newest_head = ft_lstadd(newhead,name3);
  
//   node_create *last_node = ft_lstlast(newest_head);
//   return(0);
// }