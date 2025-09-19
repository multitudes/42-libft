/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 13:40:22 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * err_s - Print the problematic portion of a format string.
 *
 * Arguments:
 *   ap:   Pointer to the va_list (unused).
 *   conv: The conversion string, or NULL if memory error.
 *
 * Returns:
 *   The number of characters printed (always 1).
 *
 * Description:
 *   Prints the '%' character and, if 'conv' is not NULL, prints the
 *   conversion string. Frees 'conv' if allocated. Mimics the behavior
 *   of original printf when encountering an invalid or problematic
 *   format specifier or memory error.
 */
ssize_t	err_s(va_list *ap, char *conv)
{
	(void)ap;
	write(1, "%", 1);
	if (conv)
	{
		write(1, conv, ft_strlen(conv));
		free(conv);
	}
	return (1);
}
