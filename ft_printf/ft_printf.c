/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:17:39 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 13:41:38 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * getops_nr - Find the conversion operator index in the conversion array.
 *
 * Arguments:
 *   s:    Pointer to the format substring after '%'.
 *   conv: Address of a pointer to store the conversion substring.
 *   ii:   Pointer to the format string index to update.
 *
 * Returns:
 *   Index of the conversion operator in the conversion array,
 *   or CONV_ERROR if not found.
 *
 * Description:
 *   Scans the format substring 's' for a valid conversion character.
 *   If found, sets 'conv' to the substring before the conversion character,
 *   updates 'ii' to the new position, and returns the operator index.
 *   Returns CONV_ERROR if no valid conversion is found or if an invalid
 *   conversion character is encountered.
 */
int	getops_nr(char *s, char **conv, int *ii)
{
	int		i;
	char	*r;

	i = 0;
	r = 0;
	while (s[i])
	{
		r = ft_strchr(CONVS, (char)(s[i]));
		if (r != NULL)
		{
			*conv = ft_substr(s, 0, i);
			*ii += i + 1;
			return ((int)(r - CONVS));
		}
		if (ft_isalpha(s[i]))
			return (CONV_ERROR);
		i++;
	}
	return (CONV_ERROR);
}


/**
 * get_conv - Dispatch the correct conversion function for a format specifier.
 *
 * Arguments:
 *   format: The format string.
 *   ii:     Pointer to the format string index to update.
 *   ap:     Pointer to the va_list of arguments.
 *
 * Returns:
 *   The number of characters written by the conversion function.
 *
 * Description:
 *   Looks up the correct conversion function in the ops array and calls it.
 *   If the conversion is invalid, prints the original conversion string.
 *   Handles updating the format string index and freeing memory as needed.
 */
ssize_t	get_conv(char *format, int *ii, va_list *ap)
{
	ssize_t	n;
	int		opnr;
	char	*conv;
	t_ffunc	ops[MAX_OPS];

	n = 0;
	++(*ii);
	init_ops(ops);
	conv = NULL;
	opnr = getops_nr(format + (*ii), &conv, ii);
	if (!conv)
		return (ops[CONV_ERROR](ap, conv));
	if (opnr == CONV_ERROR)
		return (ops[CONV_ERROR](ap, conv));
	n = ops[opnr](ap, conv);
	free(conv);
	return (n);
}

/**
 * ft_printf - Print formatted output to standard output.
 *
 * See man printf(3) for details.
 *
 * Arguments:
 *   format: The format string containing conversion specifiers.
 *   ...   : Additional arguments to format and print.
 *
 * Returns:
 *   The number of characters printed, or -1 on error.
 *
 * Description:
 *   Mimics the behavior of the standard printf function. Parses the format
 *   string, handles conversion specifiers, and prints formatted output to
 *   standard output. Supports flags, width, precision, and conversion types
 *   as specified in the format string. Returns the total number of characters
 *   printed, or -1 if an error occurs.
 */
int	ft_printf(const char *format, ...)
{
	ssize_t	n;
	int		i;
	va_list	ap;

	i = 0;
	n = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			n += get_conv((char *)format, &i, &ap);
		else
			n += write(1, format + i++, 1);
	}
	va_end(ap);
	return (n);
}
