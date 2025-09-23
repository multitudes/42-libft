/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:36:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:49:37 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_tolower - Convert an uppercase letter to lowercase.
 *
 * See man tolower(3) for details.
 *
 * Arguments:
 *   c: The character to convert.
 *
 * Returns:
 *   The lowercase equivalent if c is uppercase, otherwise c unchanged.
 *
 * Description:
 *   If 'c' is an uppercase ASCII letter, returns its lowercase equivalent.
 *   Otherwise, returns 'c' unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
