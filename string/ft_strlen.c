/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:03:08 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:19:17 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlen - Calculate the length of a string.
 *
 * See man strlen(3) for details.
 *
 * Arguments:
 *   s: The string to measure.
 *
 * Returns:
 *   The number of characters in the string, excluding the null terminator.
 *   Returns 0 if s is NULL.
 *
 * Description:
 *   Iterates through the string 's' and returns its length.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0); // the orig strlen doesnt do that!
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
