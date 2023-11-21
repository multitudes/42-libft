/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:01:55 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/21 18:17:54 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
SYNOPSIS
     #include <string.h>
     size_t  strlcat(char *dst, const char *src, size_t size);
	 
 strlcat() appends string src to the end of dst.  It will append at most
 dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
 dstsize is 0 or the original dst string was longer than dstsize (in
 practice this should not happen as it means that either dstsize is
 incorrect or that dst is not a proper string).
 If the src and dst strings overlap, the behavior is undefined.
 strlcat will append at most size - strlen(dst) - 1 bytes,
 NUL-terminating the result. strlcat returns the total length
 of the string it tried to create.
 Like snprintf(3), the strlcpy() and strlcat() functions return the total
 length of the string they tried to create.  For strlcpy() that means the
 length of src.  For strlcat() that means the initial length of dst plus
 the length of src.
 If the return value is >= dstsize, the output string has been truncated.
 It is the caller's responsibility to handle this.

 NOTE The orig strlcat crashes when I pass NULL to either string args
 mine returns zero..
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
		dst[dstlen + dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
