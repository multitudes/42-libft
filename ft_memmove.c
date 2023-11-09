/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:52:03 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/09 12:52:06 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 DESCRIPTION
 The memmove() function copies len bytes from string src to string dst.
 The two strings may overlap; the copy is always done in a non-destructive
 manner.
 
 RETURN VALUES
 The memmove() function returns the original value of dst.
 there is a way to make it faster without intermediate copy
 checking if the strings overlapt
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	tmp[len];
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}

