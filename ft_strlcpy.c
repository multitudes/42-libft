/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:54:34 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:36:39 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Safely copies strings with size limit
 * 
 * Copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0. Designed to be a
 * safer replacement for strncpy().
 * 
 * @param dst The destination buffer to copy to
 * @param src The source string to copy from
 * @param dstsize The size of the destination buffer
 * @return The total length of the string it tried to copy (length of src)
 * @note If return value >= dstsize, the output string has been truncated
 * @note Returns 0 if either dst or src is NULL (differs from standard strlcpy)
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
