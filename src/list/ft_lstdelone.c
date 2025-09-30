/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:52:04 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:15:38 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees a single list node
 * 
 * Takes as a parameter a node and frees the memory of the node's content
 * using the function 'del' given as a parameter and frees the node.
 * The memory of 'next' is not freed.
 * 
 * @param lst The node to free
 * @param del The address of the function used to delete the content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
