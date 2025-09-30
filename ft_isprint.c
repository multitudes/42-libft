/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:54:23 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:08:43 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for printable character
 * 
 * Tests for any printing character, including space (' '). In the ASCII
 * character set, this includes characters from 32 (space) to 126 ('~').
 * The value of the argument must be representable as an unsigned char
 * or the value of EOF.
 * 
 * @param c The character to test
 * @return Non-zero if the character is printable, zero otherwise
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
