/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:01:55 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/09 15:02:20 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
/*
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

 */

size_t	ft_strlen(const char *s);


size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t srclen;
	size_t dstlen;
	
	srclen = strlen(src);
	dstlen = strnlen(dst, dstsize);
	if (dstlen == dstsize)
		return (dstsize + srclen);
	if (srclen < dstsize - dstlen) 
	{
		ft_memcpy(dst + dstlen, src, srclen + 1);
	} 
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - 1);
		dst[dstlen + dstsize - 1] = '\0';
	}
	return dstlen + srclen;
}

int main(void){
	char dst[20] = "ab";
	char src[20] = "bcdef";
	size_t n = 1;
	int res = ft_strlcat(dst, src, n);
	//	int res4 = strlcat(dst4, src4, n4);
	printf("====ft strlcat gives  %d \n",res);
	printf("====ft strlcat dst  %s\n",dst);
	
	char dst4[20] = "ab";
	char src4[20] = "bcdef";
	size_t n4 = 1;
	int res2 = strlcat(dst4, src4, n4);
	//	int res4 = strlcat(dst4, src4, n4);
	printf("====strlcat gives  %d \n",res2);
	printf("====strlcat dst  %s\n",dst4);
//	debug("====after strlcat dst4 is %s \n",dst4);
//	mu_assert(res4 == 11, "Output shd be 11");
	return (0);
}
