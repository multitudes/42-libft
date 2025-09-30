/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:21:57 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:11:51 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts lowercase letter to uppercase
 * 
 * If the character is a lowercase letter (a-z), converts it to the
 * corresponding uppercase letter (A-Z). If the character is not a
 * lowercase letter, returns it unchanged.
 * 
 * @param c The character to convert
 * @return The uppercase equivalent if c is lowercase, otherwise c unchanged
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
