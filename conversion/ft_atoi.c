/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:45:15 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 11:48:59 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_atoi - Convert the digits in a string to an integer.
 *
 * See man atoi(3) for details.
 * Arguments:
 *   str: The string to convert.
 * Returns:
 *   The converted integer value.
 */
int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

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
