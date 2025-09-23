/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:27:42 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:04:13 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isascii - Check if a character is an ASCII character.
 *
 * See man isascii(3) for details.
 *
 * Arguments:
 *   c: Character to check.
 *
 * Returns:
 *   Non-zero if c is an ASCII character (0-127), zero otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
