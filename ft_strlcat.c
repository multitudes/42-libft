/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:01:55 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:38:49 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Safely concatenates strings with size limit
 * 
 * Appends string src to the end of dst. It will append at most
 * dstsize - strlen(dst) - 1 characters and NUL-terminate the result,
 * unless dstsize is 0 or the original dst string was longer than dstsize.
 * If the src and dst strings overlap, the behavior is undefined.
 * 
 * @param dst The destination string to append to
 * @param src The source string to append
 * @param dstsize The size of the destination buffer
 * @return The total length of the string it tried to create (initial length 
 * of dst plus length of src)
 * @note If return value >= dstsize, the output string has been truncated
 * @note Returns 0 if either dst or src is NULL (differs from standard strlcat)
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

//  #include <bsd/string.h>
//  #include <stdio.h>
// int main(void){
// 	char dst1[20] = "pqrs";
// 	// dest 4 src is 9 size 11
// 	size_t n = 10;
// 	int res = ft_strlcat(dst1, "abcdefghi", 11);
// 	printf("====ft strlcat gives  %d \n",res);
// 	printf("====ft strlcat dst  %s\n",dst1);
// 	char dst[20] = "ab";
// 	char src[20] = "";
// 	 n = 10;
// 	 res = ft_strlcat(dst, src, n);
// 	printf("====ft strlcat gives  %d \n",res);
// 	printf("====ft strlcat dst  %s\n",dst);
// 	char dst4[20] = "ab";
// 	char src4[20] = "";
// 	size_t n4 = 10;
// 	int res2 = strlcat(dst4, src4, n4);
// 	printf("====strlcat gives  %d \n",res2);
// 	printf("====strlcat dst  %s\n",dst4);
// 	return (0);
// }