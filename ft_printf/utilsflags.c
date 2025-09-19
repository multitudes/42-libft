/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:21:44 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 14:15:37 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * adjust_r_i2_space_plus - Handle space and plus flags for right-justified integers.
 *
 * Arguments:
 *   s:     The output string buffer.
 *   conv:  The converted integer string.
 *   flags: Pointer to the flags structure.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Copies the converted string to the appropriate position in the output
 *   buffer and adds a '+' or ' ' prefix based on the plus and space flags.
 *   Used when formatting positive integers with sign prefixes.
 */
void	adjust_r_i2_space_plus(char *s, char *conv, t_flags *flags)
{
	ft_memcpy(s + 1 + (flags->prec - flags->len), conv, flags->len);
	if (!flags->space)
		s[0] = '+';
	if (flags->space)
		s[0] = ' ';
}

/**
 * adjust_r_i2 - Adjust string placement for right-justified integer formatting.
 *
 * Arguments:
 *   s:     The output string buffer.
 *   conv:  The converted integer string.
 *   flags: Pointer to the flags structure.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Places the converted integer string in the correct position within the
 *   output buffer, handling negative numbers, precision padding, and special
 *   cases like zero precision. Calls update_for_x for hexadecimal prefixes.
 */
void	adjust_r_i2(char *s, char *conv, t_flags *flags)
{
	if ((flags->plus || flags->space) && conv[0] != '-' && (!flags->unsgned))
		adjust_r_i2_space_plus(s, conv, flags);
	else if (conv[0] == '-')
	{
		flags->start = 1 + (flags->prec - flags->len + 1);
		ft_memcpy(s + flags->start, conv + 1, flags->len - 1);
		s[0] = '-';
		if ((flags->fw > flags->prec) && flags->prec >= flags->len)
			ft_memset(s + flags->prec + 1, ' ', flags->fw - flags->prec - 1);
		if ((flags->fw > flags->prec) && flags->len > flags->prec)
			ft_memset(s + flags->len, ' ', flags->fw - flags->len);
	}
	else if (!(flags->len == 1 && conv[0] == '0' && flags->dot))
	{
		if (flags->prec > flags->len)
			ft_memcpy(s + (flags->prec - flags->len), conv, flags->len);
		else
			ft_memcpy(s, conv, flags->len);
		if ((flags->fw > flags->prec) && flags->prec >= flags->len)
			ft_memset(s + flags->prec, ' ', flags->fw - flags->prec);
	}
	else if (!(conv[0] == '0'))
		ft_memcpy(s, conv, flags->len);
	update_for_x(s, conv, flags);
}

/**
 * adjust_r_i - Main function for right-justified integer string adjustment.
 *
 * Arguments:
 *   s:     The output string buffer.
 *   conv:  The converted integer string.
 *   flags: Pointer to the flags structure.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Handles special cases like zero precision with zero value, adjusts
 *   precision for negative numbers, and calls adjust_r_i2 for final
 *   string placement. Manages field width and precision interactions.
 */
void	adjust_r_i(char *s, char *conv, t_flags *flags)
{
	if (flags->prec == 0 && flags->len == 1 && conv[0] == '0' && flags->dot)
	{
		ft_memset(s, ' ', flags->fw);
		if (flags->minw == 0)
		{
			s[flags->fw - 1] = 0;
			flags->fw = 0;
		}
	}
	else if ((flags->fw > flags->prec) && flags->prec >= flags->len \
	&& conv[0] == '0' && flags->dot)
		ft_memset(s + flags->prec, ' ', flags->fw - flags->prec);
	if (conv[0] == '-')
	{
		if ((flags->prec - flags->len) < 0)
			flags->prec = flags->len - 1;
	}
	else if ((flags->prec - flags->len) < 0)
		flags->prec = flags->len;
	adjust_r_i2(s, conv, flags);
}

/**
 * fill_flags2 - Parse and set formatting flags from conversion string.
 *
 * Arguments:
 *   conv:  The conversion string to parse.
 *   flags: Pointer to the flags structure to update.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Parses flag characters (+, -, 0, space, *, .) from the conversion
 *   string and sets corresponding fields in the flags structure.
 *   Updates minimum width and precision after parsing flags.
 */
void	fill_flags2(char *conv, t_flags **flags)
{
	while (ft_strchr("+-0 ", *conv) != NULL && *conv)
	{
		if (*conv == '+')
		(*flags)->plus = 1;
	if (*conv == '0')
	{
		(*flags)->zero = 1;
		(*flags)->pad = '0';
	}
	if (*conv == '-')
	(*flags)->minus = 1;
if (*conv == ' ')
(*flags)->space = 1;
if (*conv == '*')
(*flags)->star += 1;
if (*conv == '.')
(*flags)->dot = 1;
conv++;
}
upd_minw_prec_in_flags(conv, *flags);
}

/**
 * fill_flags - Parse and set formatting flags including hash flag.
 *
 * Arguments:
 *   p:     The conversion string to parse.
 *   flags: Pointer to the flags structure to update.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Similar to fill_flags2 but also handles the hash (#) flag.
 *   Parses flag characters (+, -, 0, #, space, *) and updates
 *   the flags structure accordingly.
 */
void	fill_flags(char *p, t_flags **flags)
{
	while (ft_strchr("+-0# ", *p) != NULL && *p)
	{
		if (*p == '+')
			(*flags)->plus = 1;
		if (*p == '0')
		{
			(*flags)->zero = 1;
			(*flags)->pad = '0';
		}
		if (*p == '-')
			(*flags)->minus = 1;
		if (*p == ' ')
			(*flags)->space = 1;
		if (*p == '*')
			(*flags)->star += 1;
		p++;
	}
	upd_minw_prec_in_flags(p, *flags);
}
