/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:49:41 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/15 17:25:41 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

/*
 The strcmp() and strncmp() functions lexicographically compare the 
 null-terminated strings s1 and s2.
 The strncmp() function compares not more than n characters.  
 Because strncmp() is designed for comparing strings rather than binary data,
 characters that appear after a ‘\0’ character are not compared.
 RETURN VALUES
 The strcmp() and strncmp() functions return an integer greater than, 
 equal to, or less than 0, according as the string s1 is greater than,
 equal to, or less than the string s2.
 The comparison is done using unsigned characters, so that ‘\200’
 is greater than ‘\0’.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '0' && i < (n - 1))
		i++;
	return (s1[i] - s2[i]);
}

//
//int main()
//{
//	int n = ft_strncmp("www", "w\b", 2);
//	printf(" ----mine  %d",n);
//printf(" ---- %d",strncmp("www", "w\b", 2));
//	return (0);
//}
