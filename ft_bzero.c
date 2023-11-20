/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:17:06 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/20 12:49:18 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 The bzero() function writes n zeroed bytes to the string s.  
 If n is zero, bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *) s;
	while (n > 0)
	{
		*tmp++ = 0;
		n--;
	}
}
