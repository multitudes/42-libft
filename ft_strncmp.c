/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:49:41 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:20:40 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/**
 * ft_strncmp - Compare two strings up to n characters.
 *
 * See man strncmp(3) for details.
 *
 * Arguments:
 *   s1: First string to compare.
 *   s2: Second string to compare.
 *   n:  Maximum number of characters to compare.
 *
 * Returns:
 *   An integer less than, equal to, or greater than zero if s1 is found,
 *   respectively, to be less than, to match, or be greater than s2.
 *
 * Description:
 *   Lexicographically compares up to n characters of the null-terminated
 *   strings s1 and s2. Comparison is done using unsigned characters.
 *   If n is zero, returns 0. If either argument is NULL, returns 0.
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
 * ft_strcmp - Compare two strings.
 *
 * Arguments:
 *   s1: First string to compare.
 *   s2: Second string to compare.
 *
 * Returns:
 *   An integer less than, equal to, or greater than zero if s1 is found,
 *   respectively, to be less than, to match, or be greater than s2.
 *
 * Description:
 *   Lexicographically compares the null-terminated strings s1 and s2.
 *   Comparison is done using unsigned characters. Handles NULL pointers.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
