/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:21:57 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:49:50 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_toupper - Convert a lowercase letter to uppercase.
 *
 * See man toupper(3) for details.
 *
 * Arguments:
 *   c: The character to convert.
 *
 * Returns:
 *   The uppercase equivalent if c is lowercase, otherwise c unchanged.
 *
 * Description:
 *   If 'c' is a lowercase ASCII letter, returns its uppercase equivalent.
 *   Otherwise, returns 'c' unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
