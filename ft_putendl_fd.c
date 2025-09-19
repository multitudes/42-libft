/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:11:53 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:13:26 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putendl_fd - Output a string followed by a newline to a file descriptor.
 *
 * Arguments:
 *   s:  The string to output.
 *   fd: The file descriptor on which to write.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Outputs the string 's' to the given file descriptor, followed by a newline.
 */
void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		return ;
	count = ft_strlen(s);
	write(fd, s, count);
	write(fd, NEWLINE, 1);
}
