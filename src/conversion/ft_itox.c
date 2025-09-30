/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:44:18 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:10:16 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reverses a string in place
 * 
 * In the functions used to convert a number to a string, an algorithm
 * is used which produces a string first but in reverse order. This
 * function reverses that string to get the correct order.
 * 
 * @param res The string to reverse
 * @param len The length of the string
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
 * @brief Converts unsigned integer to hexadecimal string (lowercase)
 * 
 * Converts an unsigned integer to its hexadecimal string representation
 * using lowercase letters (a-f). This function handles the lowercase 'x'
 * format for hexadecimal conversion.
 * 
 * @param nbr The unsigned integer to convert
 * @return A newly allocated string containing the hexadecimal representation, or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
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
