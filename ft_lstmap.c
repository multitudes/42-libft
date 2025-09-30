/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:12:44 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:19:49 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Helper function to check for null node and clean list if needed
 * 
 * Checks if a newly created node is NULL and cleans the entire list
 * using the del function if allocation failed. Returns 1 if cleanup
 * was performed, 0 otherwise.
 * 
 * @param lst The address of a pointer to the list to clean
 * @param new The new node to check for NULL
 * @param del The function used to delete content
 * @return 1 if node was NULL and list was cleaned, 0 otherwise
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
 * @brief Creates a new list by applying a function to each node
 * 
 * Iterates the list 'lst' and applies the function 'f' on the content
 * of each node. Creates a new list resulting from the successive
 * applications of the function 'f'. The 'del' function is used to
 * delete the content of a node if allocation fails.
 * 
 * @param lst The address of a pointer to a node
 * @param f The address of the function used to transform content
 * @param del The address of the function used to delete content if needed
 * @return The new list, or NULL if allocation fails
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
