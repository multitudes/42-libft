/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:12:44 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/20 11:15:32 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

/*
function returns 1 if node created was null and clean the list.
has to be followed by a return null to exit if true
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

/*
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed
The new list.
NULL if the allocation fails
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*return_list;
	void	*content;

	if (lst == NULL)
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
		if (check_new_node_not_null(&return_list, new_node, del))
			return (NULL);
		ft_lstadd_back(&return_list, new_node);
	}
	return (return_list);
}
