/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:03:15 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/10 17:03:17 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 s:  The string to be split.
 c:  The delimiter character.
 Return value
 The array of new strings resulting from the split.
 NULL if the allocation fails.
 Allocates (with malloc(3)) and returns an array
 of strings obtained by splitting ’s’ using the
 character ’c’ as a delimiter.  The array must end
 with a NULL pointer.
 allowed are malloc, free
 ps char	*ft_strrchr(const char *s, int c);
 */
char	**ft_split(char const *s, char c)
{
	char	*sub;
	char	*dup;
	char 	**arr;
	size_t		i;
	int		count;
	
	i = 0;
	count = 0;
	dup = ft_strdup(s);
	while (i < ft_strlen(s))
		if (s[i++] == c)
			count++;
	arr = ft_calloc(count + 2, sizeof(char*));
	while (count > 0)
	{
		sub = ft_strrchr(dup, c);
		arr[count--] = ft_strdup(sub+1);
		*sub = 0;
	}
	arr[0] = ft_strdup(dup);
//	char *ft_substr(char const *s, unsigned int start, size_t len)
	return (arr);
}
