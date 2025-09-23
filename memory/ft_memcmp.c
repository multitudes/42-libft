/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:02:02 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:12:05 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memcmp - Compare two memory areas byte by byte.
 *
 * See man memcmp(3) for details.
 *
 * Arguments:
 *   s1: Pointer to the first memory area.
 *   s2: Pointer to the second memory area.
 *   n:  Number of bytes to compare.
 *
 * Returns:
 *   Zero if the memory areas are identical, otherwise the difference
 *   between the first differing bytes (as unsigned char).
 *
 * Description:
 *   Compares the first n bytes of the memory areas s1 and s2.
 *   Returns zero if they are identical, or the difference between
 *   the first differing bytes. Only the sign of the result is portable.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((s1 != NULL && s2 != NULL) && (n > 0))
	{
		while ((i < (n - 1)) && *(unsigned char *)s1 == *(unsigned char *)s2)
		{
			s1++;
			s2++;
			i++;
		}
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}
