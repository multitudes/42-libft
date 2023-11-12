/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:19:49 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/11 18:19:51 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "_bonus.h"
#include "libft.h"

/*
 lst:  The beginning of the list.
 ret Last node of the list
 Returns the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
