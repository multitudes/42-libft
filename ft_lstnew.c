/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:11:40 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:20:13 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new list node
 * 
 * Allocates (with malloc) and returns a new node. The member variable
 * 'content' is initialized with the value of the parameter 'content'.
 * The variables 'next' and 'prev' are initialized to NULL.
 * 
 * @param content The content to initialize the new node with
 * @return The new node, or NULL if allocation fails
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
