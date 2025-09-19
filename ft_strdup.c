/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:57:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:16:54 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strdup - Duplicate a string.
 *
 * See man strdup(3) for details.
 *
 * Arguments:
 *   s1: The string to duplicate.
 *
 * Returns:
 *   Pointer to the newly allocated copy of the string,
 *   or NULL if allocation fails.
 *
 * Description:
 *   Allocates sufficient memory for a copy of the string 's1',
 *   copies it, and returns a pointer to the new string.
 *   The returned pointer can be freed with free(3).
 */
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
