/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:05:12 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/09 12:06:01 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 The memcpy() function copies n bytes from memory area src to memory area
 dst.  If dst and src overlap, behavior is undefined.  Applications in
 which dst and src might overlap should use memmove(3) instead.
 
 RETURN VALUES
 The memcpy() function returns the original value of dst.
*/
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned long	i;
	
	i = 0;
	n = (unsigned long) n;
	while (i < n)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src++);
		i++;
	}
	return (dst);
}
