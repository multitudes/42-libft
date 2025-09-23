/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:07:27 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:09:40 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstiter - Iterate over a linked list and apply a function to each node's
 * content.
 *
 * Arguments:
 *   lst: The address of a pointer to a node.
 *   f:   The address of the function used to iterate on the list.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Iterates the list 'lst' and applies the function 'f' on the content of 
 *   each node.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst->next != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}
