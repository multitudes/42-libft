/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:32:28 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:48:43 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strrchr - Locate the last occurrence of a character in a string.
 *
 * See man strrchr(3) for details.
 *
 * Arguments:
 *   s: Pointer to the string to search.
 *   c: Character to locate (converted to unsigned char).
 *
 * Returns:
 *   Pointer to the last occurrence of the character in the string,
 *   or NULL if not found.
 *
 * Description:
 *   Searches for the last occurrence of character 'c' in the string 's'.
 *   The terminating null character is considered part of the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
