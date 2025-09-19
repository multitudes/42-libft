/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:01:55 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:17:59 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcat - Concatenate strings with size limit.
 *
 * See man strlcat(3) for details.
 *
 * Arguments:
 *   dst:     Destination string buffer.
 *   src:     Source string to append.
 *   dstsize: Total size of the destination buffer.
 *
 * Returns:
 *   The total length of the string it tried to create:
 *   initial length of dst plus length of src.
 *   If return value >= dstsize, output string has been truncated.
 *   Returns 0 if either dst or src is NULL.
 *
 * Description:
 *   Appends src to the end of dst. Appends at most dstsize - strlen(dst) - 1
 *   characters, then NUL-terminates the result (unless dstsize is 0 or dst
 *   was longer than dstsize). If src and dst overlap, behavior is undefined.
 *   This implementation returns 0 if either argument is NULL.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	if (dst == NULL || src == NULL)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
	{
		return (dstsize + srclen);
	}
	else if (srclen < dstsize - dstlen)
	{
		ft_memcpy(dst + dstlen, src, srclen + 1);
	}
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
