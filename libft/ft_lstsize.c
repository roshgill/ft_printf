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

//ft_lstsize gets size of a list

int ft_lstsize(void *head)
{
  node_create *tmp = NULL;
  tmp = (node_create *) malloc(sizeof(node_create));
  tmp = head;
  int i = 0;
  
  while(tmp->next != NULL)
  { 
    i++;
    tmp = tmp->next;
  }
  i++;
  return(i);
}

//Create list and get list size
// int main(void) 
// {
//   char *name = "Roshan";
//   char *name2 = "Ekisha";
//   char *name3 = "Jasbir";
  
//   node_create *head = ft_lstnew(name);
//   node_create *newhead = ft_lstadd(head,name2);
//   node_create *newest_head = ft_lstadd(newhead,name3);
  
//   int list_num = ft_lstsize(newest_head);
//   return(0);
// }