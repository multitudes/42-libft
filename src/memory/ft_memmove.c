/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:52:03 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:21:57 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies memory area handling overlaps
 * 
 * Copies n bytes from memory area src to memory area dst. The two areas
 * may overlap; the copy is always done in a non-destructive manner by
 * choosing the appropriate copy direction (forward or backward).
 * 
 * @param dst Destination memory area
 * @param src Source memory area
 * @param len Number of bytes to copy
 * @return The original value of dst
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
