/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:44:53 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:16:29 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strchr - Locate the first occurrence of a character in a string.
 *
 * See man strchr(3) for details.
 *
 * Arguments:
 *   s: Pointer to the string to search.
 *   c: Character to locate (converted to char).
 *
 * Returns:
 *   Pointer to the located character, or NULL if not found.
 *
 * Description:
 *   Searches for the first occurrence of character 'c' in the string 's'.
 *   The terminating null character is considered part of the string.
 */
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
