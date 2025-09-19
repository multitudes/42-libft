/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:44:16 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 11:50:36 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_calloc - Allocate and zero-initialize an array in memory.
 *
 * See man calloc(3) for details.
 *
 * Arguments:
 *   count: Number of elements to allocate.
 *   size: Size of each element.
 *
 * Returns:
 *   Pointer to the allocated and zero-initialized memory, or NULL on failure.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*tmp;
	size_t	n;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count >= (SIZE_MAX / size))
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	n = count * size;
	tmp = p;
	while (n > 0)
	{
		*tmp++ = 0;
		n--;
	}
	return (p);
}
