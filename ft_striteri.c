/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:26:42 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:38:57 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each character of a string with its index
 * 
 * Applies the function 'f' on each character of the string passed as
 * argument, passing its index as first argument. Each character is
 * passed by address to 'f' to be modified if necessary.
 * 
 * @param s The string on which to iterate
 * @param f The function to apply to each character 
 * (takes index and char pointer)
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
