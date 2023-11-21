/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:03:15 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/21 18:18:13 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

/*
SYNOPSIS

char **ft_split(char const *s, char c);

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
 */
// inspired by UNIX
// I use a char** str because the string *str will be changed 
// in the func
static char	*ft_strsep(char **str, char *delim)
{
	char	*s;
	int		c;
	char	*tok;	

	if (*str == NULL || str == NULL)
		return (NULL);
	s = *str;
	while (*s == *delim)
		s++;
	tok = s;
	while (1)
	{
		c = *s++;
		if (c == *delim || c == '\0') 
		{
			if (c == 0)
				s = NULL;
			else
				s[-1] = 0;
			*str = s;
			return (tok);
		}
	}
}

// Counting the words divided by the char c 
static int	my_word_count(const char *s, char c)
{
	int		count;
	int		state;

	state = OUT;
	count = 0;
	while (*s != '\0' && (s != NULL))
	{
		if (*s == c)
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			count++;
		}
		s++;
	}
	return (count);
}

static void	*ft_free(char **arr, int i)
{
	while (i >= 0)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	*splitstr;	
	char	**arr;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = 0;
	count = my_word_count(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	while (i < count)
	{
		splitstr = ft_strsep((char **)&s, &c); 
		arr[i] = ft_strdup(splitstr);
		if (arr[i] == NULL)
			return (ft_free(arr, i--));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
