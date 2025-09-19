/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:21:44 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 13:40:06 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * reverse - Reverse a string in place.
 *
 * Arguments:
 *   res: The string to reverse.
 *   len: Length of the string.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Used internally for number-to-string conversions that build the string
 *   in reverse order. This function reverses the string in place and
 *   null-terminates it.
 */
void	reverse(char *res, int len)
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


