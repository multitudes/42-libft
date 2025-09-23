/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:45:15 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 11:48:47 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_atol - Convert the digits in a string to a long integer.
 *
 * See man atol(3) for details.
 *
 * Arguments:
 *   str: The string to convert.
 *
 * Returns:
 *   The converted long integer value.
 */
long	ft_atol(const char *str)
{
	long	n;
	int		sign;

	if (str == NULL)
		return (0);
	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (ft_isdigit(*str))
		n = 10 * n + ((*str++ - '0') * sign);
	return (n);
}
