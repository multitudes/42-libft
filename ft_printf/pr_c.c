/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:07 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 13:44:25 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * get_left_padding_c - Print a character right-justified with padding.
 *
 * Arguments:
 *   width: Minimum field width.
 *   c:     The character to print.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'width', fills it with spaces, and places
 *   the character 'c' at the rightmost position. If width is zero, prints
 *   only the character. Writes the result to standard output.
 */
ssize_t	get_left_padding_c(size_t width, int c)
{
	ssize_t	i;
	char	*s;

	s = safemalloc_and_set(width, ' ');
	if (!s)
		return (0);
	ft_memset(s, ' ', width);
	if (width > 0)
		ft_memcpy((s + width - 1), &c, 1);
	else
		ft_memcpy((s + width), &c, 1);
	if (!width)
		width = 1;
	i = write(1, s, width);
	free(s);
	return (i);
}

/**
 * get_right_padding_c - Print a character left-justified with padding.
 *
 * Arguments:
 *   width: Minimum field width.
 *   c:     The character to print.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Allocates a buffer of size 'width', fills it with spaces, and places
 *   the character 'c' at the leftmost position. Writes the result to
 *   standard output.
 */
ssize_t	get_right_padding_c(size_t width, int c)
{
	ssize_t	i;
	char	*s;

	s = safemalloc_and_set(width, ' ');
	if (!s)
		return (0);
	ft_memset(s, ' ', width);
	ft_memcpy(s, &c, 1);
	i = write(1, s, width);
	free(s);
	return (i);
}

/**
 * pr_c - Print a character with optional width and padding for %c conversion.
 *
 * Arguments:
 *   ap:   Pointer to the va_list of arguments.
 *   conv: The conversion string containing width and flags.
 *
 * Returns:
 *   The number of characters printed.
 *
 * Description:
 *   Handles the %c conversion in printf, printing a character with optional
 *   width and padding. Supports left and right padding based on flags.
 *   Precision and most flags are ignored for character conversion.
 *   If width is negative, left-justifies the character.
 */
ssize_t	pr_c(va_list *ap, char *conv)
{
	int	width;
	int	c;

	width = 0;
	if (ft_strchr(conv, '*'))
		width = va_arg(*ap, int);
	else
		width = width_prec_atoi(&conv);
	if (ft_strchr(conv, '-'))
		width *= -1;
	c = va_arg(*ap, int);
	if (width < 0)
		return (get_right_padding_c(-width, c));
	else
		return (get_left_padding_c(width, c));
}
