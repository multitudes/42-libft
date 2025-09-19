/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:54:34 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:18:29 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcpy - Copy a string to a buffer with size limit.
 *
 * See man strlcpy(3) for details.
 *
 * Arguments:
 *   dst:     Destination string buffer.
 *   src:     Source string to copy.
 *   dstsize: Total size of the destination buffer.
 *
 * Returns:
 *   The length of src. If return value >= dstsize, output string has
 *   been truncated. Returns 0 if either dst or src is NULL.
 *
 * Description:
 *   Copies up to dstsize - 1 characters from src to dst, NUL-terminating
 *   the result if dstsize is not 0. If dst or src is NULL, returns 0.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	srclen = ft_strlen(src);
	while ((i + 1) < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		i++;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (srclen);
}
