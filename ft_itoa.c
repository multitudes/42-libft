/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:52 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/10 17:53:55 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/*
 n:  the integer to convert.
 Return value
 The string representing the integer.
 NULL if the allocation fails.
 Description
 Allocates (with malloc(3)) and returns a string
 representing the integer received as an argument.
 Negative numbers must be handled.
 */

char	*reverse(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;
	
	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	s2[len] = '\0';
	while (len > 0)
	{
		s2[i++] = s1[--len];
	}
	return (s2);
}

char	*ft_itoa(int n)
{
	int		i;
	char	sign;
	char	*num;
	char	temp[12];
	
	i = 0;
	if (n < 0)
	{
		sign = '-';
		n *= -1;
	}
//		temp[i++] = '-';
	while (n)
	{
		temp[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == '-')
		temp[i++] = sign;
	temp[i] = 0;
	num = calloc(i + 1 , 1);
	num = reverse(temp);
	return (num);
}
