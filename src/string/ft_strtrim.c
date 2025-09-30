/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:57:47 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 12:27:39 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Trims whitespace characters from both ends of a string
 * 
 * Creates a new string with leading and trailing characters from 'set'
 * removed from 's1'. If allocation fails, returns NULL.
 * 
 * @param s1 The string to trim
 * @param set The set of characters to remove
 * @return A newly allocated trimmed string, or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = 0;
	start = ft_strlen(s1) - 1;
	while (start > 0 && (ft_strchr(set, s1[start]) != NULL))
		start--;
	while (end <= start && (ft_strchr(set, s1[end]) != NULL))
		end++;
	result = ft_substr(s1, end, start - end + 1);
	return (result);
}
