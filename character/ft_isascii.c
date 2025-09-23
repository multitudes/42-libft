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
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
