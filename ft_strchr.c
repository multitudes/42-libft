/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:44:53 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:32:31 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a character in a string
 * 
 * Locates the first occurrence of c (converted to a char) in the string
 * pointed to by s. The terminating null character is considered to be
 * part of the string; therefore if c is '\0', the function locates
 * the terminating '\0'.
 * 
 * @param s The string to search in
 * @param c The character to search for
 * @return A pointer to the located character, or NULL if not found
 */
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
