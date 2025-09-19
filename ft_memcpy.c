/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:05:12 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:12:19 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memcpy - Copy memory area.
 *
 * See man memcpy(3) for details.
 *
 * Arguments:
 *   dst: Pointer to the destination memory area.
 *   src: Pointer to the source memory area.
 *   n:   Number of bytes to copy.
 *
 * Returns:
 *   Pointer to the destination memory area (dst).
 *
 * Description:
 *   Copies n bytes from memory area src to memory area dst.
 *   If dst and src overlap, behavior is undefined.
 *   Use ft_memmove if memory areas may overlap.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (dst == NULL || src == NULL)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*tmp_dst++ = *tmp_src++;
		n--;
	}
	return (dst);
}
