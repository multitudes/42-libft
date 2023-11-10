/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:46:03 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/10 11:46:16 by lbrusa           ###   ########.fr       */
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
 // AGAIN
 The memcmp() function shall return an integer greater than, equal to, or less than 0,
 if the object pointed to by s1 is greater than, equal to, or less than the object 
 pointed to by s2, respectively.
 It doesn't say it will return -1 or 1. What it exactly returns is implementation dependent.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	
	i = 0;
	while (((*(unsigned char *)s) != '\0') && i < (unsigned long)n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return (void *)s;
		s++;
	}
	return 0;
}

