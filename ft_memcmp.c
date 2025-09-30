/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:02:02 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:21:30 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two memory areas
 * 
 * Compares the first n bytes of the memory areas s1 and s2. The comparison
 * is done using unsigned char values. Zero-length comparisons always return 0.
 * 
 * @param s1 Pointer to the first memory area
 * @param s2 Pointer to the second memory area
 * @param n Number of bytes to compare
 * @return Zero if the memory areas are identical, otherwise the difference
 *         between the first two differing bytes (as unsigned char values)
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
