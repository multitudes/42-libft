/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:26:42 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:17:14 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_striteri - Apply a function to each character of a string with its index.
 *
 * Arguments:
 *   s: The string on which to iterate.
 *   f: The function to apply to each character.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Applies the function 'f' on each character of the string 's',
 *   passing its index as the first argument. Each character is passed
 *   by address to 'f' to be modified if necessary.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	count;

	if (s == NULL || f == NULL)
		return ;
	count = ft_strlen(s);
	while (count > 0)
	{
		count--;
		f(count, &s[count]);
	}
}
