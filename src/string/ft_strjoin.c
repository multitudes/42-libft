/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:39:29 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:33:57 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings into a new string
 * 
 * Allocates (with malloc) and returns a new string, which is the result
 * of the concatenation of 's1' and 's2'.
 * 
 * @param s1 The prefix string
 * @param s2 The suffix string
 * @return The new concatenated string, or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
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
