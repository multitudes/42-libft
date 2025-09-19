/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:42:50 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:48:12 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strnstr - Locate a substring in a string, searching up to len characters.
 *
 * See man strnstr(3) for details.
 *
 * Arguments:
 *   haystack: The string to search in.
 *   needle:   The substring to search for.
 *   len:      Maximum number of characters to search.
 *
 * Returns:
 *   Pointer to the first occurrence of needle in haystack,
 *   or NULL if needle is not found.
 *   If needle is an empty string, haystack is returned.
 *
 * Description:
 *   Searches for the first occurrence of the substring 'needle' in the
 *   string 'haystack', where not more than 'len' characters are searched.
 *   Characters after a '\0' are not searched. Returns a pointer to the
 *   first character of the first occurrence, or NULL if not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = i;
		k = 0;
		while (haystack[j] == needle[k] && needle[k] != '\0' && j < len)
		{
			j++;
			k++;
		}
		if (k > 0 && needle[k] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
