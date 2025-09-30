/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:35:59 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:06:46 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for alphanumeric character
 * 
 * Tests for any character for which ft_isalpha or ft_isdigit is true.
 * The value of the argument must be representable as an unsigned char
 * or the value of EOF.
 * 
 * @param c The character to test
 * @return Non-zero if the character is alphanumeric, zero otherwise
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
