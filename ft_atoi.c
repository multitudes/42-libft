/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:45:15 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:12:21 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a string to an integer
 * 
 * Converts the initial portion of the string pointed to by str to int
 * representation. The string may begin with an arbitrary amount of white
 * space (space, tab, newline, vertical tab, form feed, carriage return)
 * followed by a single optional '+' or '-' sign.
 * 
 * @param str The string to convert
 * @return The converted integer value, or 0 if no conversion
 * @note Equivalent to (int)strtol(str, (char **)NULL, 10)
 * @warning Does not handle overflow/underflow like standard strtol
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
