/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:12:44 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:09:16 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/**
* check_if_null_clear - Helper to clear list if node allocation fails.
*
* Arguments:
*   lst:  The address of a pointer to the list.
*   new:  The newly created node.
*   del:  The address of the function used to delete the content.
*
* Returns:
*   1 if new node is NULL and the list was cleared, 0 otherwise.
*
* Description:
*   Used internally by ft_lstmap to free the list if node allocation fails.
*/
static int	check_if_null_clear(t_list **lst, t_list *new, void (*del)(void *))
{
	if (new == NULL)
	{
		ft_lstclear(lst, del);
		return (1);
	}
	return (0);
}

/**
 * ft_lstmap - Create a new list by applying a function to each node's content.
 *
 * Arguments:
 *   lst:  The address of a pointer to a node.
 *   f:    The address of the function used to iterate on the list.
 *   del:  The address of the function used to delete the content of a node if needed.
 *
 * Returns:
 *   The new list.
 *   NULL if the allocation fails.
 *
 * Description:
 *   Iterates the list 'lst' and applies the function 'f' on the content of each node.
 *   Creates a new list resulting from the successive applications of the function 'f'.
 *   The 'del' function is used to delete the content of a node if needed.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*return_list;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	content = f(lst->content);
	return_list = ft_lstnew(content);
	if (return_list == NULL)
	{
		if (content != NULL)
			del(content);
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_node = ft_lstnew(f(lst->content));
		if (check_if_null_clear(&return_list, new_node, del))
			return (NULL);
		ft_lstadd_back(&return_list, new_node);
	}
	return (return_list);
}
