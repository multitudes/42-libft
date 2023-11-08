/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:49:41 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/08 17:49:55 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;
	
	i = 0;
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
