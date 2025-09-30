/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:47:40 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/08 16:47:43 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for ASCII character
 * 
 * Tests for an ASCII character, which is any character between 0 and 127
 * inclusive (octal 0177). This covers the standard ASCII character set.
 * 
 * @param c The character to test
 * @return Non-zero if the character is ASCII, zero otherwise
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
