/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:52:03 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:12:42 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memmove - Copy memory area, handling overlap safely.
 *
 * See man memmove(3) for details.
 *
 * Arguments:
 *   dst: Pointer to the destination memory area.
 *   src: Pointer to the source memory area.
 *   len: Number of bytes to copy.
 *
 * Returns:
 *   Pointer to the destination memory area (dst).
 *
 * Description:
 *   Copies len bytes from src to dst. Handles overlapping memory areas
 *   by copying from the end or the front as needed to avoid corruption.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (dst == NULL || src == NULL || len == 0)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	if (tmp_dst > tmp_src)
	{
		while (len > 0)
		{
			*(tmp_dst + len - 1) = *(tmp_src + len - 1);
			len--;
		}
	}
	else if (tmp_src > tmp_dst)
	{
		while (len > 0)
		{
			*tmp_dst++ = *tmp_src++;
			len--;
		}
	}
	return (dst);
}
