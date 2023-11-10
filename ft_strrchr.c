/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:32:28 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/10 11:33:02 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
 The strrchr() function is identical to strchr(),
 except it locates the last occurrence of c.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	len;
	
	len = ft_strlen(s);
	p = (char *)s + len;
	while (p != s)
	{
		if (*p == (char)c)
			return (char *)p;
		p--;
	}
	return NULL;
}
