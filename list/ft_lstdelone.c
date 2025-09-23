/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:52:04 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:09:47 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstdelone - Delete and free a single node from a linked list.
 *
 * Arguments:
 *   lst:  The node to free.
 *   del:  The address of the function used to delete the content.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Frees the memory of the node’s content using the function 'del' given
 *   as a parameter and frees the node itself. The memory of 'next' must not 
 *   be freed.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
