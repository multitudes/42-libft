/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:19:49 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:08:05 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstlast - Return the last node of a linked list.
 *
 * Arguments:
 *   lst: The beginning of the list.
 *
 * Returns:
 *   The last node of the list, or NULL if the list is empty.
 *
 * Description:
 *   Iterates through the list and returns the last node.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
