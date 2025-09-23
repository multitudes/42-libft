/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoxp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:48:35 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:10:16 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_itoxp - Convert a pointer value to a hexadecimal string 
 * (with "0x" prefix).
 *
 * Arguments:
 *   nbr: The pointer value to convert (as uintptr_t).
 *
 * Returns:
 *   The string representing the pointer in hexadecimal (with "0x" prefix),
 *   or "(nil)" if the pointer is NULL.
 *
 * Description:
 *   Allocates (with malloc) and returns a string representing the pointer
 *   value
 *   in base 16, prefixed with "0x". Used for printing pointer addresses.
 */
char	*ft_itoxp(uintptr_t nbr)
{
	int		i;
	char	*prefix;
	char	hex_p[19];
	char	*res;

	i = 0;
	prefix = "0x";
	if (nbr == 0)
		return (ft_strdup("(nil)"));
	while (nbr > 0)
	{
		hex_p[i++] = BASE16[nbr % 16];
		nbr /= 16;
	}
	_reverse(hex_p, i);
	res = ft_strjoin(prefix, hex_p);
	return (res);
}
