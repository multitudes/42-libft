/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:27:42 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:12:51 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for decimal digit character
 * 
 * Tests for a decimal digit character. Regardless of locale, this includes
 * the following characters only: 
 * '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
 * 
 * @param c The character to test
 * @return Non-zero if the character is a digit, zero otherwise
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
