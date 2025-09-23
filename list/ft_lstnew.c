/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:11:40 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:11:04 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstnew - Allocate and return a new linked list node.
 *
 * Arguments:
 *   content: The value to initialize the node's content.
 *
 * Returns:
 *   Pointer to the new node, or NULL if allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a new node. 
 *   The member variable 'content' is initialized with the value 
 *   of the parameter 'content'. 
 *   The variable 'next' is initialized to NULL.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
