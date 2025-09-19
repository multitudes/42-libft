/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 14:11:19 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * pr_x - Print a hexadecimal integer with formatting for %x conversion.
 *
 * Arguments:
 *   ap:   Pointer to the va_list of arguments.
 *   conv: The conversion string containing width, precision, and flags.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Handles the %x conversion in printf, printing an unsigned integer
 *   in lowercase hexadecimal format with optional width, precision, and flags
 *   (0, -, #, *). The # flag adds "0x" prefix for non-zero values.
 *   Supports dynamic width specification with *.
 */
ssize_t	pr_x(va_list *ap, char *conv)
{
	int		nr;
	t_flags	*flags;

	flags = init_flags();
	if (flags == NULL)
		return (0);
	fill_flags(conv, &flags);
	if (ft_strchr(conv, '#') != NULL)
		flags->hash = 1;
	if (flags->star)
		flags->fw = va_arg(*ap, int);
	nr = va_arg(*ap, unsigned int);
	if (flags->minus)
		return (get_r_pad_i(ft_itox(nr), flags));
	else
		return (get_l_pad_i(ft_itox(nr), flags));
}
