/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:57:47 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/10 15:57:50 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 s1:  The string to be trimmed.
 set:  The reference set of characters to trim.
 Return value
 The trimmed string.
 NULL if the allocation fails.
 Description
 Allocates (with malloc(3)) and returns a copy of
 ’s1’ with the characters specified in ’set’ removed
 from the beginning and the end of the string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;
	
	n = ft_strlen(s1 - 1);
	while (n >= 0)
	{
		
		n--;
	}
	
}
