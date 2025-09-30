/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:41:56 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:14:23 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a node at the beginning of a list
 * 
 * Adds the node 'new_node' at the beginning of the list. The new node
 * becomes the first element of the list. This implementation supports
 * doubly linked lists by setting both next and prev pointers.
 * 
 * @param lst The address of a pointer to the first link of a list
 * @param new_node The node to be added to the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (new_node != NULL && *lst != NULL)
	{
		(*lst)->prev = new_node;
		new_node->next = *lst;
	}
	*lst = new_node;
}
