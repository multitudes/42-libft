/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:20 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 14:10:38 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * get_left_padding - Print a string right-justified with padding and precision.
 *
 * Arguments:
 *   width:  Minimum field width.
 *   prec:   Maximum number of characters to print from the string.
 *   str:    The string to print.
 *   has_pt: Whether precision was specified (dot found in format).
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'width', fills it with spaces, and places
 *   the string 'str' (up to 'prec' characters if has_pt) at the rightmost
 *   position. Adjusts width based on string length and precision.
 */
ssize_t	get_left_padding(size_t width, size_t prec, char *str, int has_pt)
{
	ssize_t	i;
	char	*s;
	size_t	len;

	len = ft_strlen(str);
	if (width == 0 && !has_pt)
		width = len;
	if ((prec > len) && has_pt)
		prec = len;
	else if (has_pt)
		len = prec;
	if (len > width)
		width = (int)len;
	if (prec > width || (len > prec && has_pt))
		width = prec;
	s = safemalloc_and_set(width, ' ');
	if (!s)
		return (0);
	if (!has_pt)
		ft_memcpy((s + width - len), str, len);
	else
		ft_memcpy((s + width - prec), str, prec);
	i = write(1, s, width);
	free(s);
	return (i);
}

/**
 * get_right_padding - Print a string left-justified with padding and precision.
 *
 * Arguments:
 *   width:  Minimum field width.
 *   prec:   Maximum number of characters to print from the string.
 *   str:    The string to print.
 *   has_pt: Whether precision was specified (dot found in format).
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'width', places the string 'str' at the
 *   leftmost position (up to 'prec' characters if has_pt), and fills
 *   the remaining space with padding. Adjusts width based on precision.
 */
ssize_t	get_right_padding(size_t width, size_t prec, char *str, int has_pt)
{
	ssize_t	i;
	char	*s;
	size_t	len;

	len = ft_strlen(str);
	if (prec > len)
		prec = len;
	if ((!has_pt) && (len > width))
		width = (int)len;
	if ((!has_pt) && (len > width))
		width = (int)len;
	else if ((has_pt) && (prec > width))
		width = prec;
	s = safemalloc_and_set(width, ' ');
	if (!s)
		return (0);
	ft_memcpy(s, str, len);
	if ((has_pt) && (width > prec))
		ft_memset(s + prec, ' ', width - prec);
	if ((has_pt) && (prec == 0))
		ft_memset(s, ' ', width);
	i = write(1, s, width);
	free(s);
	return (i);
}


/**
 * pr_s - Print a string with formatting for %s conversion.
 *
 * Arguments:
 *   ap:   Pointer to the va_list of arguments.
 *   conv: The conversion string containing width, precision, and flags.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Handles the %s conversion in printf, printing a string with optional
 *   width and precision. Supports left-justification (-) flag and dynamic
 *   width (*). If the string is NULL, prints "(null)" when appropriate.
 *   Precision limits the maximum number of characters printed.
 */
ssize_t	pr_s(va_list *ap, char *conv)
{
	int		width;
	int		prec;
	char	*str;
	int		has_pt;

	width = 0;
	has_pt = 0;
	if (ft_strchr(conv, '*'))
		width = va_arg(*ap, int);
	if (ft_strchr(conv, '.'))
		has_pt = 1;
	get_width_and_precision(conv, &width, &prec);
	if (ft_strchr(conv, '-'))
		width *= -1;
	str = va_arg(*ap, char *);
	if ((str == NULL && !has_pt) || (str == NULL && prec >= 6 && has_pt))
		str = "(null)";
	if (width < 0)
		return (get_right_padding(-width, prec, str, has_pt));
	else
		return (get_left_padding(width, prec, str, has_pt));
}
