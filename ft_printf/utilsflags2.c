/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsflags2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:21:44 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 14:17:37 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * upd_minw_prec_in_flags - Update minimum width and precision in flags structure.
 *
 * Arguments:
 *   p:     The conversion string to parse (e.g., "+2.3").
 *   flags: Pointer to the flags structure to update.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Parses minimum width and precision from the conversion string and updates
 *   the flags structure. Handles dot notation for precision, adjusts field
 *   width based on flags, and sets appropriate padding characters.
 */
void	upd_minw_prec_in_flags(char *p, t_flags *flags)
{
	if (flags->space)
		flags->minw *= -1;
	if (*p != '.')
		flags->minw = width_prec_atoi(&p);
	if (*p == '.')
	{
		flags->dot = 1;
		p++;
		flags->prec = width_prec_atoi(&(p));
	}
	if (flags->dot && !(flags->prec == 0))
		flags->pad = '0';
	if (flags->minw > flags->prec)
		flags->fw = flags->minw;
	else
		flags->fw = flags->prec + (flags->space || flags->plus);
	if (!flags->dot && flags->zero)
		flags->prec = flags->minw;
	if ((flags->dot) && (flags->minw > flags->prec))
		flags->pad = '0';
}

/**
 * adjust_l_i3 - Handle hash flag prefixes for left-justified integers.
 *
 * Arguments:
 *   s:  The output string buffer.
 *   p:  The converted integer string.
 *   fl: Pointer to the flags structure.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Adds "0x" or "0X" prefixes to hexadecimal numbers when the hash flag
 *   is set and the number is non-zero. Handles different positioning
 *   based on zero-padding and precision flags.
 */
void	adjust_l_i3(char *s, char *p, t_flags *fl)
{
	if (((fl->hash && fl->zero) || (fl->hash && fl->dot)) && !(p[0] == '0'))
	{
		if ((fl->fw - fl->prec - 2) > 0)
			ft_memcpy(s + (fl->fw - fl->prec - 2), "0x", 2);
		else
			ft_memcpy(s, "0x", 2);
	}
	else if (((fl->hashhash && fl->zero) || (fl->hashhash && fl->dot)) \
	&& !(p[0] == '0'))
	{
		if ((fl->fw - fl->prec - 2) > 0)
			ft_memcpy(s + (fl->fw - fl->prec - 2), "0X", 2);
		else
			ft_memcpy(s, "0X", 2);
	}
	else if ((fl->hash && !((fl->zero) || (fl->dot))) && !(p[0] == '0'))
		ft_memcpy((s + fl->fw - fl->len - 2), "0x", 2);
	else if (fl->hashhash && !((fl->zero) || (fl->dot)) && !(p[0] == '0'))
		ft_memcpy((s + fl->fw - fl->len - 2), "0X", 2);
}

/**
 * adjust_l_i2 - Handle special cases for left-justified integer formatting.
 *
 * Arguments:
 *   s:     The output string buffer.
 *   p:     The converted integer string.
 *   flags: Pointer to the flags structure.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Handles edge cases like zero precision with zero value, negative
 *   numbers with zero padding, and calls adjust_l_i3 for hash flag
 *   processing. Adjusts field width and character placement accordingly.
 */
void	adjust_l_i2(char *s, char *p, t_flags *flags)
{
	if (flags->prec == 0 && flags->len == 1 && p[0] == '0' && flags->dot)
	{
		s[flags->fw - 1] = ' ' ;
		if (flags->minw == 0)
		{
			s[flags->fw - 1] = 0;
			flags->fw = 0;
		}
	}
	if (p[0] == '-' && (flags->pad == '0') && (flags->fw > flags->len) && \
	(flags->fw > flags->prec))
	{
		s[0] = ' ';
		s[flags->fw - (flags->prec + 1)] = '-';
	}
	adjust_l_i3(s, p, flags);
}

/**
 * adjust_l_i - Main function for left-justified integer string adjustment.
 *
 * Arguments:
 *   s:  The output string buffer.
 *   p:  The converted integer string.
 *   fs: Pointer to the flags structure.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Positions the converted integer string in the output buffer for
 *   left-justified formatting. Handles sign prefixes (+, -, space),
 *   zero padding, and negative numbers. Calls adjust_l_i2 for additional
 *   processing of special cases.
 */
void	adjust_l_i(char *s, char *p, t_flags *fs)
{
	if (p[0] == '-' && (fs->pad == '0') && (fs->fw > fs->len))
		ft_memcpy((s + fs->fw - (fs->len - 1)), p + 1, fs->len - 1);
	else
		ft_memcpy((s + fs->fw - fs->len), p, fs->len);
	if ((fs->plus || fs->space || fs->zero) && (!fs->unsgned) && \
	(!(fs->pad == '0') || (fs->len >= fs->prec)))
	{
		if (fs->plus && !(p[0] == '-') && (!fs->unsgned))
			s[fs->fw - (fs->len + 1)] = '+';
		else if ((p[0] == '-') && fs->zero && (fs->fw > fs->len))
		{
			s[fs->fw - (fs->prec + 1)] = '-';
			s[0] = ' ';
		}
	}
	else if ((fs->pad == '0') && (fs->plus || fs->space) && (!fs->unsgned))
	{
		if (fs->plus)
			s[0] = '+';
	}
	else if (p[0] == '-' && (fs->pad == '0'))
		s[0] = '-';
	adjust_l_i2(s, p, fs);
}


/**
 * update_flags_r_i - Update flags for right-justified integer formatting.
 *
 * Arguments:
 *   p:  The converted integer string.
 *   fs: Pointer to the flags structure to update.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Updates the flags structure based on the converted string properties.
 *   Adjusts field width, precision, padding, and handles interactions
 *   between different flags. Ensures proper spacing for signs and prefixes.
 */
void	update_flags_r_i(char *p, t_flags *fs)
{
	fs->len = (int)ft_strlen(p);
	if (fs->prec < fs->len)
		if (p[0] == '-')
			fs->prec = fs->len - 1;
	if (fs->zero && !fs->plus && (p[0] != '-'))
		fs->pad = '0';
	if (p[0] == '-')
		fs->plus = 0;
	if (p[0] == '-')
		fs->zero = 0;
	if (fs->fw == fs->prec && (p[0] == '-') && (fs->dot))
		(fs->fw)++;
	if (fs->len > fs->fw)
		fs->fw = fs->len;
	if ((fs->len + (fs->plus || fs->space) && (!fs->unsgned)) > fs->fw)
		fs->fw = fs->len + 1;
	if ((fs->hash || fs->hashhash) && ((fs->fw < (fs->len + 2)) || \
	(fs->fw < (fs->prec + 2))))
	{
		if (fs->fw < (fs->len + 2))
			fs->fw = fs->len + 2;
		if (fs->fw < (fs->prec + 2))
			fs->fw = fs->prec + 2;
	}
}
