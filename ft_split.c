/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:03:15 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:16:08 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

/**
 * ft_split - Split a string into an array of strings using a delimiter.
 *
 * Arguments:
 *   s: The string to be split.
 *   c: The delimiter character.
 *
 * Returns:
 *   The array of new strings resulting from the split.
 *   NULL if the allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns an array of strings obtained by
 *   splitting 's' using the character 'c' as a delimiter. The array ends
 *   with a NULL pointer.
 */
static char	*ft_strsep(char **str, char *delim)
{
	char	*s;
	int		c;
	int		i;
	char	*tok;	

	if (*str == NULL || str == NULL)
		return (NULL);
	i = 0;
	s = *str;
	while (*s == *delim)
		s++;
	tok = s;
	while (1)
	{
		c = *s++;
		i++;
		if (c == *delim || c == '\0')
		{
			if (c != 0)
				i--;
			*str = s;
			return (ft_substr(tok, 0, i));
		}
	}
}

/**
 * my_word_count - Count words in a string separated by a delimiter.
 *
 * Arguments:
 *   s: The string to count words in.
 *   c: The delimiter character.
 *
 * Returns:
 *   The number of words found.
 *
 * Description:
 *   Iterates through the string 's' and counts the number of words
 *   separated by the delimiter character 'c'. A word is a sequence
 *   of non-delimiter characters.
 */
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

/**
 * ft_free - Free an array of strings and return NULL.
 *
 * Arguments:
 *   arr: The array of strings to free.
 *   i:   The last index to free.
 *
 * Returns:
 *   NULL.
 *
 * Description:
 *   Frees each string in the array 'arr' up to index 'i', then frees
 *   the array itself and returns NULL. Used for cleanup on allocation failure.
 */
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

/**
 * ft_split - Split a string into an array of strings using a delimiter.
 *
 * Arguments:
 *   s: The string to be split.
 *   c: The delimiter character.
 *
 * Returns:
 *   The array of new strings resulting from the split.
 *   NULL if the allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns an array of strings obtained by
 *   splitting 's' using the character 'c' as a delimiter. The array ends
 *   with a NULL pointer.
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
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
		arr[i] = ft_strsep((char **)&s, &c);
		if (arr[i] == NULL)
			return (ft_free(arr, i--));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
