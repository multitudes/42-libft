/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:00:45 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/11 18:00:47 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"
#include "libft.h"

/*
 lst:  The beginning of the list.
 return The length of the list
 Counts the number of nodes in a list.
 */
int		ft_lstsize(t_list *lst)
{
	int	i;
	
	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
	
}
