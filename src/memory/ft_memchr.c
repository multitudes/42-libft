/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:46:03 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:20:57 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates byte in memory area
 * 
 * Locates the first occurrence of c (converted to an unsigned char)
 * in the first n bytes of the memory area pointed to by s.
 * 
 * @param s Pointer to the memory area to search
 * @param c The byte to search for
 * @param n Number of bytes to search
 * @return A pointer to the byte located, or NULL if not found within n bytes
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
