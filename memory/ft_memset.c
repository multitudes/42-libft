/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:19 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:12:55 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memset - Fill memory with a constant byte.
 *
 * See man memset(3) for details.
 *
 * Arguments:
 *   b:   Pointer to the memory area.
 *   c:   Byte value to set (converted to unsigned char).
 *   len: Number of bytes to set.
 *
 * Returns:
 *   Pointer to the memory area (b).
 *
 * Description:
 *   Writes len bytes of value c to the memory area pointed to by b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	if (b == NULL)
		return (NULL);
	tmp = (unsigned char *) b;
	while (len > 0)
	{
		*tmp++ = (unsigned char) c;
		len--;
	}
	return (b);
}
