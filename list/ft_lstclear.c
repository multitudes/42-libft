/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:59:08 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:07:24 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstclear - Delete and free all nodes of a linked list.
 *
 * Arguments:
 *   lst:  The address of a pointer to a node.
 *   del:  The address of the function used to delete the content of the node.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Deletes and frees the given node and every successor of that node,
 *   using the function 'del' and free(3). Finally, the pointer to the list
 *   is set to NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	**l;
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	l = lst;
	temp = *lst;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		ft_lstdelone(temp, del);
		temp = *lst;
	}
	ft_lstdelone(temp, del);
	*l = NULL;
}
