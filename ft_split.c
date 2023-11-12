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

#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */
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
// I first count and return an array of empty string pointers
char	**ft_split_count(char const *s, char c)
{
	int		i;
	int		count;
	int		state;
	char	**arr;
	
	i = 0;
	count = 0;
	state = OUT;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
		{
			state = OUT;
		}
		else
		{
			state = IN;
			++count;
		}
		i++;
	}
	arr = ft_calloc(count + 1, sizeof(char*));
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	*sub;
	char	*dup;
	char 	**arr;
	size_t		i;
	int		start;
	int		flag;
	
	i = 0;
	start = 0;
	flag = 1;
	dup = ft_strdup(s);
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
		{
			start = i;
			i++;
			flag = 0;
		}
	}
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
