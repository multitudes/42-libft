/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:44:35 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:13:08 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts unsigned integer to hexadecimal string (uppercase)
 * 
 * Converts an unsigned integer to its hexadecimal string representation
 * using uppercase letters (A-F). This function handles the uppercase 'X'
 * format for hexadecimal conversion.
 * 
 * @param nbr The unsigned integer to convert
 * @return A newly allocated string containing the hexadecimal representation, 
 * or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
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
