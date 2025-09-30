/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:44:16 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 12:53:36 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and zeros memory
 * 
 * Contiguously allocates enough space for count objects that are size bytes
 * each and returns a pointer to the allocated memory. The allocated memory
 * is filled with bytes of value zero.
 * 
 * @param count Number of objects to allocate
 * @param size Size of each object in bytes
 * @return A pointer to allocated memory, or NULL if allocation fails
 * @note Checks for integer overflow in the multiplication count * size
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
