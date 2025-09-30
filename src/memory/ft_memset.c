/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:19 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:22:21 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets bytes in memory to a specific value
 * 
 * Writes len bytes of value c (converted to an unsigned char) to the
 * memory area pointed to by b.
 * 
 * @param b Pointer to the memory area to fill
 * @param c The value to set (converted to unsigned char)
 * @param len Number of bytes to set
 * @return The original value of b
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
