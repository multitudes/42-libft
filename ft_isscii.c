/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isscii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:47:40 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/08 16:47:43 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 The isascii() function tests for an ASCII character, which is any 
 character between 0 and octal 0177 inclusive. (127!)
*/
int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}