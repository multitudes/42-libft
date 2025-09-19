/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 14:11:00 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * pr_u - Print an unsigned integer with formatting for %u conversion.
 *
 * Arguments:
 *   ap:   Pointer to the va_list of arguments.
 *   conv: The conversion string containing width, precision, and flags.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Handles the %u conversion in printf, printing an unsigned integer
 *   with optional width, precision, and flags (0, -, *). Sets the
 *   unsigned flag and uses the same padding functions as signed integers.
 *   Supports dynamic width specification with *.
 */
ssize_t	pr_u(va_list *ap, char *conv)
{
	unsigned int	nr_input;
	t_flags			*flags;

	flags = init_flags();
	if (flags == NULL)
		return (0);
	fill_flags(conv, &flags);
	flags->unsgned = 1;
	if (flags->star)
		flags->fw = va_arg(*ap, int);
	nr_input = va_arg(*ap, unsigned int);
	if (flags->minus)
		return (get_r_pad_i(ft_itou(nr_input), flags));
	else
		return (get_l_pad_i(ft_itou(nr_input), flags));
}
