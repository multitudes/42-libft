/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:05:12 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 12:53:31 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies memory area
 * 
 * Copies n bytes from memory area src to memory area dst. If dst and src
 * overlap, behavior is undefined. Applications in which dst and src might
 * overlap should use ft_memmove instead.
 * 
 * @param dst Destination memory area
 * @param src Source memory area
 * @param n Number of bytes to copy
 * @return The original value of dst
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
