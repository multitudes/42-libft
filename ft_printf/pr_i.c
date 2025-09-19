/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 13:47:43 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * prepare_flags2 - Adjust formatting flags for integer conversions.
 *
 * Arguments:
 *   conv:  The string representation of the integer.
 *   flags: Pointer to the flags structure for formatting.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Modifies the flags structure to ensure correct field width and padding
 *   for integer formatting. Handles plus, space, zero-padding, and hash flags.
 *   Ensures the field width is sufficient for prefixes and padding.
 */
void	prepare_flags2(char *conv, t_flags *flags)
{
	if ((flags->plus || flags->space) && !flags->unsgned)
		if (flags->len + 1 > flags->fw)
			flags->fw = flags->len + 1;
	if ((flags->pad == '0') && (flags->len > flags->prec))
		flags->pad = ' ';
	if ((flags->hash || flags->hashhash) && !(conv[0] == '0') && \
	((flags->fw < (flags->len + 2)) || (flags->fw < (flags->prec + 2))))
	{
		if (flags->fw < (flags->len + 2))
			flags->fw = flags->len + 2;
		if (flags->fw < (flags->prec + 2))
			flags->fw = flags->prec + 2;
	}
}

/**
 * prepare_flags2 - Adjust formatting flags for integer conversions.
 *
 * Arguments:
 *   conv:  The string representation of the integer.
 *   flags: Pointer to the flags structure for formatting.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Modifies the flags structure to ensure correct field width and padding
 *   for integer formatting. Handles plus, space, zero-padding, and hash flags.
 *   Ensures the field width is sufficient for prefixes and padding.
 */
void	prepare_flags(char *conv, t_flags *flags)
{
	flags->len = (int)ft_strlen(conv);
	if (flags->prec < flags->len)
		if (conv[0] == '-')
			flags->prec = flags->len - 1;
	if (conv[0] == '-')
	{
		flags->plus = 0;
		flags->space = 0;
	}
	if ((flags->fw == (flags->prec)) && (conv[0] == '-') && (flags->dot))
		(flags->fw)++;
	if (flags->len > (flags->fw))
		flags->fw = flags->len;
	prepare_flags2(conv, flags);
}

/**
 * get_l_pad_i - Print an integer right-justified with padding.
 *
 * Arguments:
 *   conv:  The string representation of the integer.
 *   flags: Pointer to the flags structure for formatting.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'fw', fills it with spaces or padding,
 *   and places the integer string at the rightmost position according
 *   to the flags. Writes the result to standard output.
 */
ssize_t	get_l_pad_i(char *conv, t_flags *flags)
{
	ssize_t	i;
	char	*s;

	prepare_flags(conv, flags);
	s = safemalloc_and_set(flags->fw, ' ');
	if (!s)
		return (0);
	ft_memset(s + flags->fw - flags->prec, flags->pad, flags->prec);
	adjust_l_i(s, conv, flags);
	free(conv);
	i = write(1, s, flags->fw);
	free(s);
	free(flags);
	return (i);
}

/**
 * get_r_pad_i - Print an integer left-justified with padding.
 *
 * Arguments:
 *   conv:  The string representation of the integer.
 *   flags: Pointer to the flags structure for formatting.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'fw', fills it with spaces or padding,
 *   and places the integer string at the leftmost position according
 *   to the flags. Writes the result to standard output.
 */
ssize_t	get_r_pad_i(char *conv, t_flags *flags)
{
	ssize_t	i;
	char	*s;

	update_flags_r_i(conv, flags);
	s = safemalloc_and_set(flags->fw, flags->pad);
	if (!s)
		return (0);
	adjust_r_i(s, conv, flags);
	i = write(1, s, flags->fw);
	free(s);
	free(flags);
	free(conv);
	return (i);
}

/**
 * pr_i - Print an integer with formatting for %d and %i conversions.
 *
 * Arguments:
 *   ap:   Pointer to the va_list of arguments.
 *   conv: The conversion string containing width, precision, and flags.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Handles the %d and %i conversions in printf, printing an integer
 *   with optional width, precision, and flags (+, space, 0, -, etc.).
 *   Allocates and formats the output string according to the flags,
 *   then prints it left- or right-justified as needed.
 */
ssize_t	pr_i(va_list *ap, char *conv)
{
	int		nr_input;
	t_flags	*flags;

	flags = init_flags();
	if (flags == NULL)
		return (0);
	fill_flags(conv, &flags);
	if (flags->star)
		flags->fw = va_arg(*ap, int);
	nr_input = va_arg(*ap, int);
	if (flags->minus)
		return (get_r_pad_i(ft_itoa((int)nr_input), flags));
	else
		return (get_l_pad_i(ft_itoa((int)nr_input), flags));
}
