/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:39:29 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:17:34 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strjoin - Concatenate two strings into a new string.
 *
 * Arguments:
 *   s1: The prefix string.
 *   s2: The suffix string.
 *
 * Returns:
 *   The new string resulting from the concatenation of s1 and s2,
 *   or NULL if the allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a new string, which is the
 *   result of the concatenation of 's1' and 's2'.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*cat;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	cat = ft_calloc(len1 + len2 + 1, 1);
	if (cat == NULL)
		return (NULL);
	ft_strlcat(cat, s1, len1 + 1);
	ft_strlcat(cat, s2, len1 + len2 + 1);
	return (cat);
}
