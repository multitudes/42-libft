/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:03:15 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:26:48 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

#include <stdio.h>

/**
 * @brief Extracts tokens from a string using a delimiter
 * 
 * Similar to strsep, extracts the next token from the string pointed to by str
 * using the delimiter. The string pointer is updated to point past the 
 * delimiter.
 * 
 * @param str Pointer to string pointer (will be modified)
 * @param delim The delimiter character
 * @return The extracted token, or NULL if no more tokens
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
 * @brief Counts words in a string separated by a delimiter
 * 
 * Counts the number of words in string s that are separated by character c.
 * Uses a state machine approach to track whether we're inside or outside 
 * a word.
 * 
 * @param s The string to count words in
 * @param c The delimiter character
 * @return The number of words found
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
 * @brief Frees an array of strings and the array itself
 * 
 * Frees all allocated strings in the array up to index i, then frees
 * the array itself. Used for cleanup when allocation fails during
 * array construction.
 * 
 * @param arr The array of strings to free
 * @param i The highest index to free (inclusive, going backwards to 0)
 * @return Always returns NULL for convenient error handling
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
 * @brief Splits a string using a delimiter character
 * 
 * Allocates (with malloc) and returns an array of strings obtained by
 * splitting 's' using the character 'c' as a delimiter. The array must
 * end with a NULL pointer.
 * 
 * @param s The string to be split
 * @param c The delimiter character
 * @return The array of new strings resulting from the split, or NULL if allocation fails
 * @note The caller is responsible for freeing the returned array and all its strings
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
