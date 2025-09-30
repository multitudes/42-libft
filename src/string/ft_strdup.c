/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:57:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 12:53:43 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a duplicate of a string
 * 
 * Allocates sufficient memory for a copy of the string s1, does the copy,
 * and returns a pointer to it. The pointer may subsequently be used as an
 * argument to the function free().
 * 
 * @param s1 The string to duplicate
 * @return A pointer to the duplicated string, or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
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
