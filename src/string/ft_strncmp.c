/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:49:41 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:37:43 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/**
 * @brief Compares at most n characters of two strings
 * 
 * Lexicographically compares the null-terminated strings s1 and s2.
 * Compares not more than n characters. Characters that appear after
 * a '\0' character are not compared. The comparison is done using
 * unsigned characters.
 * 
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @param n The maximum number of characters to compare
 * @return An integer greater than, equal to, or less than 0, according
 *         as s1 is greater than, equal to, or less than s2
 * @note Returns 0 if either s1 or s2 is NULL (differs from standard strncmp)
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/**
 * @brief Compares two strings lexicographically
 * 
 * Compares the null-terminated strings s1 and s2 character by character
 * using unsigned char values. A simplified version of strncmp without
 * length limitation.
 * 
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @return An integer greater than, equal to, or less than 0, according
 *         as s1 is greater than, equal to, or less than s2
 * @note Returns 0 if both s1 and s2 are NULL
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
