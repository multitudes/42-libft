/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:19 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/15 17:26:26 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 void *
 memset(void *b, int c, size_t len);
 DESCRIPTION
 The memset() function writes len bytes of value c 
 (converted to an unsigned char) to the string b.
 RETURN VALUES
 The memset() function returns its first argument.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b++) = c;
		i++;
	}
	return (b);
}
