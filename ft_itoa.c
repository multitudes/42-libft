/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:52 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:05:19 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_itoa - Convert an integer to a string.
 *
 * See man itoa(3) for details.
 *
 * Arguments:
 *   n: The integer to convert.
 *
 * Returns:
 *   The string representing the integer, or NULL if allocation fails.
 *
 * Description:
 *   Allocates (with malloc) and returns a string representing the integer
 *   received as an argument. Handles negative numbers, including INT_MIN.
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
