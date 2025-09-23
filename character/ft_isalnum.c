/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:35:59 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 11:50:56 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isalnum - Check if a character is alphanumeric.
 *
 * See man isalnum(3) for details.
 *
 * Arguments:
 *   c: Character to check.
 *
 * Returns:
 *   Non-zero if c is alphanumeric, zero otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
