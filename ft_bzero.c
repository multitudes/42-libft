/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:17:06 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 11:50:03 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero - Write zeroed bytes to a memory area.
 *
 * See man bzero(3) for details.
 *
 * Arguments:
 *   s: Pointer to the memory.
 *   n: Number of bytes to zero.
 *
 * Returns:
 *   None.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	if (s == NULL || n == 0)
		return ;
	tmp = (char *) s;
	while (n > 0)
	{
		*tmp++ = 0;
		n--;
	}
}
