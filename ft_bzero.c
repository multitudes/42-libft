/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:17:06 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/08 18:17:20 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 The bzero() function writes n zeroed bytes to the string s.  
 If n is zero, bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	
	i = 0;
	n = (unsigned int) n;
	if (n != 0)
	{
		while (i < n)
		{
			*((char *)s++) = 0;
			i++;
		}
	}
}
