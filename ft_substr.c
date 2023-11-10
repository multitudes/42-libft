/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:16:37 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/10 15:16:39 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 s:  The string from which to create the substring.
 start:  The start index of the substring in the
 string ’s’.
 len:  The maximum length of the substring.
 Allocates (with malloc(3)) and returns a substring
 from the string ’s’.
 The substring begins at index ’start’ and is of
 maximum size ’len’.
 */
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	
	i = 0;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	while ((i < len) && (s[start + i] != '\0'))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[start + i] = '\0';
	return (sub);
}

