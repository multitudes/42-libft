/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:44:35 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:10:00 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_itoxx - Convert an unsigned int to a hexadecimal string (uppercase).
 *
 * Arguments:
 *   nbr: The unsigned integer to convert.
 *
 * Returns:
 *   The string representing the hexadecimal value in uppercase, or 
 *   NULL if allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a string representing the hexadecimal
 *   value of the input number in uppercase. Used for %X conversions.
 */
char	*ft_itoxx(unsigned int nbr)
{
	int		i;
	char	hex_p[19];
	char	*res;

	i = 0;
	if (nbr == 0)
		hex_p[i++] = '0';
	while (nbr > 0)
	{
		hex_p[i++] = BASE16X[nbr % 16];
		nbr /= 16;
	}
	_reverse(hex_p, i);
	res = ft_strdup(hex_p);
	return (res);
}
