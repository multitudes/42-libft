/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:28:46 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:13:47 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putnbr_fd - Output an integer to a file descriptor.
 *
 * Arguments:
 *   n:  The integer to output.
 *   fd: The file descriptor on which to write.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Outputs the integer 'n' to the given file descriptor using write(2).
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	*temp;
	size_t	c;

	c = 0;
	temp = NULL;
	temp = ft_itoa(n);
	c = ft_strlen(temp);
	write(fd, temp, c);
	if (temp != NULL)
		free(temp);
}
