/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:57:17 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 11:51:10 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isalpha - Check if a character is alphabetic.
 *
 * See man isalpha(3) for details.
 *
 * Arguments:
 *   c: Character to check.
 *
 * Returns:
 *   Non-zero if c is alphabetic, zero otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
