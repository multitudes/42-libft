/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:57:17 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:07:10 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for alphabetic character
 * 
 * Tests for any character for which isupper or islower would be true.
 * This includes all uppercase letters (A-Z) and lowercase letters (a-z).
 * The value of the argument must be representable as an unsigned char
 * or the value of EOF.
 * 
 * @param c The character to test
 * @return Non-zero if the character is alphabetic, zero otherwise
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
