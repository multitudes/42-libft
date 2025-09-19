/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:21:44 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 13:35:25 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_itoxx - Convert an unsigned int to a hexadecimal string (uppercase).
 *
 * Arguments:
 *   nbr: The unsigned integer to convert.
 *
 * Returns:
 *   The string representing the hexadecimal value in uppercase,
 *   or NULL if allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a string representing the
 *   hexadecimal value of the input number in uppercase. Used for %X
 *   conversions in printf. Adds a prefix if the hash flag is set.
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
	reverse(hex_p, i);
	res = ft_strdup(hex_p);
	return (res);
}

/**
 * ft_itou - Convert an unsigned int to a decimal string.
 *
 * Arguments:
 *   nbr: The unsigned integer to convert.
 *
 * Returns:
 *   The string representing the decimal value,
 *   or NULL if allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a string representing the
 *   decimal value of the input number. Used for %u conversions in printf.
 */
char	*ft_itou(unsigned int nbr)
{
	int		i;
	char	res[13];

	i = 0;
	if (nbr == 0)
		res[i++] = '0';
	while (nbr > 0)
	{
		res[i++] = '0' + (nbr % 10);
		nbr /= 10;
	}
	reverse(res, i);
	return (ft_strdup(res));
}

/**
 * update_for_x - Add "0x" prefix to a hexadecimal string if hash flag is set.
 *
 * Arguments:
 *   s:     The destination string buffer.
 *   conv:  The converted hexadecimal string.
 *   flags: Pointer to the flags structure.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   If the hash flag is set, copies "0x" to the start of 's' and
 *   appends the converted string 'conv' after the prefix.
 */
void	update_for_x(char *s, char *conv, t_flags *flags)
{
	if (flags->hash)
	{
		ft_memcpy(s + 2, conv, ft_strlen(conv));
		ft_memcpy(s, "0x", 2);
	}
}
