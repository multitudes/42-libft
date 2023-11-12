/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:41:25 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/11 18:41:27 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"
#include "libft.h"

/*
 lst:  The address of a pointer to the first link of
 a list.
 new:  The address of a pointer to the node to be
 added to the list.
 adds the node ’new’ at the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	last = ft_lstlast(*lst);
	last->next = new;
}
