/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:47:43 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/15 17:25:03 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Parameters
 s:  The string on which to iterate.
 f:  The function to apply to each character.
 Return value
 The string created from the successive applications
 of ’f’.
 Returns NULL if the allocation fails.
 Applies the function ’f’ to each character of the
 string ’s’, and passing its index as first argument
 to create a new string (with malloc(3)) resulting
 from successive applications of ’f’.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	count;
	char	*s2;

	count = ft_strlen(s);
	s2 = calloc(count + 1, 1);
	while (count > 0)
	{
		count--;
		s2[count] = f(count, s[count]);
	}
	return (s2);
}
