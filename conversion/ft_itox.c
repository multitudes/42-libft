/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:44:18 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:05:49 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * _reverse - Reverse a string in place.
 *
 * Arguments:
 *   res: The string to reverse.
 *   len: Length of the string.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Used internally for number-to-string conversions that build the string
 *   in reverse order. This function reverses the string in place.
 */
void	_reverse(char *res, int len)
{
	int	j;
	int	c;
	int	i;

	i = len;
	j = 0;
	i--;
	while (j < i)
	{
		c = res[j];
		res[j++] = res[i];
		res[i--] = c;
	}
	res[len] = 0;
}

/**
 * ft_itox - Convert an unsigned int to a hexadecimal string (lowercase).
 *
 * Arguments:
 *   nbr: The unsigned integer to convert.
 *
 * Returns:
 *   The string representing the hexadecimal value, or NULL if allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a string representing the hexadecimal
 *   value of the input number in lowercase. Uses _reverse to correct digit order.
 */
char	*ft_itox(unsigned int nbr)
{
	int		i;
	char	hex_p[19];
	char	*res;

	i = 0;
	if (nbr == 0)
		hex_p[i++] = '0';
	while (nbr > 0)
	{
		hex_p[i++] = BASE16[nbr % 16];
		nbr /= 16;
	}
	_reverse(hex_p, i);
	res = ft_strdup(hex_p);
	return (res);
}
