/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:18:55 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 13:43:29 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * pr_ - Print a literal '%' character for the '%%' format specifier.
 *
 * Arguments:
 *   ap:   Pointer to the va_list (unused).
 *   conv: The conversion string (can be "%%" or similar).
 *
 * Returns:
 *   The number of characters printed (always 1).
 *
 * Description:
 *   Handles the '%%' case in printf, printing a single '%' character.
 *   Ignores the arguments and conversion string.
 */
ssize_t	pr_(va_list *ap, char *conv)
{
	(void)ap;
	(void)conv;
	return (write(1, "%", 1));
}
