/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:52 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 12:53:28 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an integer to a string
 * 
 * Allocates (with malloc) and returns a string representing the integer
 * received as an argument. Negative numbers are handled correctly,
 * including INT_MIN.
 * 
 * @param n The integer to convert
 * @return The string representing the integer, or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
 */
char	*ft_itoa(int n)
{
	int		i;
	int		minus;
	char	temp[12];

	i = 1;
	minus = 1;
	temp[11] = '\0';
	if (n >= 0)
	{
		n *= -1;
		minus = 0;
	}
	temp[11 - i++] = '0' - (n % 10);
	n /= 10;
	while (n != 0)
	{
		temp[11 - i++] = '0' - (n % 10);
		n /= 10;
	}
	if (minus)
		temp[11 - i++] = '-';
	return (ft_strdup(&temp[11 - i + 1]));
}
