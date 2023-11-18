/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:57:47 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/15 17:22:12 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
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
 	s = ft_strtrim("   xxx   xxx", " x");
	 7- check(!strcmp(s, ""));
	8 - mcheck(s, 1); free(s); showLeaks();
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;
	size_t	b;
	char	*s2;

	b = 0;
	n = ft_strlen(s1);
	while (n > 0 && (ft_strchr(set, (int)s1[n]) != NULL))
	{
		--n;
	}
	n++;
	while (b < n && (ft_strchr(set, (int)s1[b]) != NULL))
	{
		b++;
	}
	s2 = ft_substr(s1, b, n - b);
	return (s2);
}

// int main()
// {

// 	char *s = ft_strtrim("   xxx   xxx", " x");
// 	printf("str is -%s-",s);
// 		free(s);
// 	s = ft_strtrim("   xxxtripouille", " x");
// 	printf("str is -%s-",s);
// 		free(s);
// 	s = ft_strtrim("a", " x");
// 	printf("str is -%s-",s);
// 	free(s);
// 	return (0);
// }