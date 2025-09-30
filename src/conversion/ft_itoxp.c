/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoxp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:48:35 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:13:03 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts pointer address to hexadecimal string
 * 
 * Converts a pointer address (uintptr_t) to its hexadecimal string
 * representation with "0x" prefix. Returns "(nil)" for null pointers.
 * Used for converting pointers to base16 format for display.
 * 
 * @param nbr The pointer address as uintptr_t to convert
 * @return A newly allocated string containing the pointer representation, 
 * or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
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
