/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:41:25 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:06:52 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstadd_back - Add a new node at the end of a linked list.
 *
 * Arguments:
 *   lst:  The address of a pointer to the first link of a list.
 *   new_node: The address of a pointer to the node to be added to the list.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Adds the node 'new_node' at the end of the list.
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
