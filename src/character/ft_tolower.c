/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:36:14 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:40:20 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts uppercase letter to lowercase
 * 
 * If the character is an uppercase letter (A-Z), converts it to the
 * corresponding lowercase letter (a-z). If the character is not an
 * uppercase letter, returns it unchanged.
 * 
 * @param c The character to convert
 * @return The lowercase equivalent if c is uppercase, otherwise c unchanged
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
