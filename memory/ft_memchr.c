/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:46:03 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:11:49 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memchr - Locate the first occurrence of a byte in memory.
 *
 * See man memchr(3) for details.
 *
 * Arguments:
 *   s: Pointer to the memory area.
 *   c: Byte to locate (converted to unsigned char).
 *   n: Number of bytes to search.
 *
 * Returns:
 *   Pointer to the located byte, or NULL if not found within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
