/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:49:09 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:14:00 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putstr_fd - Output a string to a file descriptor.
 *
 * Arguments:
 *   s:  The string to output.
 *   fd: The file descriptor on which to write.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Outputs the string 's' to the given file descriptor using write(2).
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		return ;
	count = (int)ft_strlen(s);
	write(fd, s, count);
}
