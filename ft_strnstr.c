/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:42:50 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:38:17 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a substring in a string with length limit
 * 
 * Locates the first occurrence of the null-terminated string needle
 * in the string haystack, where not more than len characters are
 * searched. Characters that appear after a '\0' character are not
 * searched.
 * 
 * @param haystack The string to search in
 * @param needle The substring to search for
 * @param len The maximum number of characters to search
 * @return A pointer to the first character of the first occurrence of needle,
 *         or haystack if needle is empty, or NULL if needle is not found
 * @note Returns NULL if either haystack or needle is NULL 
 * (differs from standard strnstr)
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
