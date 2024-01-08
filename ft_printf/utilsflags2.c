/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsflags2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:21:44 by lbrusa            #+#    #+#             */
/*   Updated: 2023/12/29 15:17:28 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 the char *p arg is the conversion string ex +2.3
 and I need to get the minwidth 2 and the prec precision 3
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
	if (((flags->hash && flags->zero) || (flags->hash && flags->dot )) && !(p[0] == '0'))
	{
		if (((flags->fw - flags->prec - 2) > 0) && (flags->prec > flags->len + 2))
			ft_memcpy(s + (flags->fw - flags->prec - 2), "0x", 2);
		else 
			ft_memcpy(s, "0x", 2);
	}
	else if (((flags->hashhash && flags->zero) || (flags->hashhash && flags->dot)) && !(p[0] == '0'))
	{
		if (((flags->fw - flags->prec - 2) > 0) && (flags->prec > flags->len + 2))
			ft_memcpy(s + (flags->fw - flags->prec - 2), "0X", 2);
		else 
			ft_memcpy(s, "0X", 2);
	}
	else if ((flags->hash && !((flags->zero) || (flags->dot))) && !(p[0] == '0')) 
		ft_memcpy((s + flags->fw - flags->len - 2), "0x", 2);
	else if (flags->hashhash && !((flags->zero) || (flags->dot)) && !(p[0] == '0')) 
		ft_memcpy((s + flags->fw - flags->len - 2), "0X", 2);
}

/*

*/
void	adjust_l_i(char *s, char *p, t_flags *flags)
{
	if (p[0] == '-' && (flags->pad == '0') && (flags->fw > flags->len))
		ft_memcpy((s + flags->fw - (flags->len - 1)), p + 1, flags->len - 1);
	else
		ft_memcpy((s + flags->fw - flags->len), p, flags->len);
	if ((flags->plus || flags->space || flags->zero) && (!flags->unsgned) &&\
	(!(flags->pad == '0') || (flags->len >= flags->prec)))
	{
		if (flags->plus && !(p[0] == '-') && (!flags->unsgned))
			s[flags->fw - (flags->len + 1)] = '+';
		else if ((p[0] == '-') && flags->zero && (flags->fw > flags->len))
		{
			s[flags->fw - (flags->prec + 1)] = '-';
			s[0] = ' ';
		}
	}
	else if ((flags->pad == '0') && (flags->plus || flags->space) && (!flags->unsgned))
	{
		if (flags->plus)
			s[0] = '+';
	}
	else if (p[0] == '-' && (flags->pad == '0'))
		s[0] = '-';
	adjust_l_i2(s, p, flags);
}

/*

*/
void	update_flags_r_i(char *p, t_flags *flags)
{
	flags->len = (int)ft_strlen(p);
	if (flags->prec < flags->len)
		if (p[0] == '-')
			flags->prec = flags->len - 1;
	if (flags->zero && !flags->plus && (p[0] != '-'))
		flags->pad = '0';
	if (p[0] == '-')
		flags->plus = 0;
	if (p[0] == '-')
		flags->zero = 0;
	if (flags->fw == flags->prec && (p[0] == '-') && (flags->dot))
		(flags->fw)++;
	if (flags->len > flags->fw)
		flags->fw = flags->len;
	if ((flags->len + (flags->plus || flags->space) && (!flags->unsgned)) > flags->fw)
		flags->fw = flags->len + 1;
	if ((flags->hash || flags->hashhash) && ((flags->fw < (flags->len + 2)) || (flags->fw < (flags->prec + 2))))
		{
			if (flags->fw < (flags->len + 2))
				flags->fw = flags->len + 2;
			if (flags->fw < (flags->prec + 2))
				flags->fw = flags->prec + 2;
		}
}
