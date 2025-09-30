/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:41:25 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:13:45 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a node at the end of a list
 * 
 * Adds the node 'new_node' at the end of the list. If the list is empty,
 * the new node becomes the first element. This implementation supports
 * doubly linked lists by setting both next and prev pointers.
 * 
 * @param lst The address of a pointer to the first link of a list
 * @param new_node The node to be added to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last)
	{
		last->next = new_node;
		new_node->prev = last;
	}
	else
		*lst = new_node;
}
