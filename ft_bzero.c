/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:17:06 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:06:19 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets bytes in memory to zero
 * 
 * Writes n zeroed bytes to the memory area pointed to by s.
 * If n is zero, ft_bzero does nothing.
 * 
 * @param s Pointer to the memory area to zero
 * @param n Number of bytes to set to zero
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
