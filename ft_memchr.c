/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:46:03 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/20 14:15:59 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 void *
 memchr(const void *s, int c, size_t n);
 DESCRIPTION
 The memchr() function locates the first occurrence of c 
 (converted to an unsigned char) in string s.
 RETURN VALUES
 The memchr() function returns a pointer to the byte located, or NULL 
 if no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
