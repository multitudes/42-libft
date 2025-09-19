/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:16:37 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:49:18 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_substr - Create a substring from a string.
 *
 * Arguments:
 *   s:     The string from which to create the substring.
 *   start: The start index of the substring in the string 's'.
 *   len:   The maximum length of the substring.
 *
 * Returns:
 *   The substring, or NULL if allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a substring from the string 's'.
 *   The substring begins at index 'start' and is of maximum size 'len'.
 *   If 'start' is greater than the length of 's', returns an empty string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*sub;

	if (s == NULL)
		return (NULL);
	i = 0;
	strlen = ft_strlen(s);
	if (len + (size_t)start > strlen)
	{
		if (strlen >= (size_t)start)
			len = strlen - (size_t)start;
		else
			len = 0;
	}
	sub = ft_calloc(len + 1, 1);
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
