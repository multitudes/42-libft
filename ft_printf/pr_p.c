/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 14:09:16 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * get_l_pad_p - Print a pointer right-justified with padding.
 *
 * Arguments:
 *   width: Minimum field width.
 *   p:     The pointer string to print.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'width', fills it with spaces, and places
 *   the pointer string 'p' at the rightmost position. If the string length
 *   exceeds width, uses the string length as width. Frees the input string.
 */
ssize_t	get_l_pad_p(int width, char *p)
{
	ssize_t	i;
	char	*s;
	size_t	len;
	char	pad;

	pad = ' ';
	len = ft_strlen(p);
	if (((int)len) > width)
		width = ((int)len);
	s = safemalloc_and_set(width, pad);
	if (!s)
		return (0);
	ft_memcpy((s + width - (len)), p, len);
	free(p);
	i = write(1, s, width);
	free(s);
	return (i);
}

/**
 * get_r_pad_p - Print a pointer left-justified with padding.
 *
 * Arguments:
 *   width: Minimum field width.
 *   p:     The pointer string to print.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'width', fills it with spaces, and places
 *   the pointer string 'p' at the leftmost position. If the string length
 *   exceeds width, uses the string length as width. Frees the input string.
 */
ssize_t	get_r_pad_p(int width, char *p)
{
	ssize_t	i;
	char	*s;
	size_t	len;
	char	pad;

	pad = ' ';
	len = ft_strlen(p);
	if (((int)len) > width)
		width = ((int)len);
	s = safemalloc_and_set(width, pad);
	if (!s)
		return (0);
	ft_memcpy(s, p, len);
	free(p);
	i = write(1, s, width);
	free(s);
	return (i);
}

/**
 * pr_p - Print a pointer with formatting for %p conversion.
 *
 * Arguments:
 *   ap:   Pointer to the va_list of arguments.
 *   conv: The conversion string containing width and flags.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Handles the %p conversion in printf, printing a pointer address
 *   in hexadecimal format with "0x" prefix. Supports width and
 *   left-justification (-) flag. Uses ft_itoxp to convert the pointer.
 */
ssize_t	pr_p(va_list *ap, char *conv)
{
	uintptr_t	nr_input;
	int			width;

	if (ft_strchr(conv, '*'))
		width = va_arg(*ap, int);
	else
		width = width_prec_atoi(&conv);
	if (ft_strchr(conv, '-'))
		width *= -1;
	if (!width)
		width = 1;
	nr_input = va_arg(*ap, uintptr_t);
	if (width < 0)
		return (get_r_pad_p(-width, ft_itoxp(nr_input)));
	else
		return (get_l_pad_p(width, ft_itoxp(nr_input)));
}
