/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:40:08 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:13:11 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putchar_fd - Output a character to a file descriptor.
 *
 * Arguments:
 *   c:  The character to output.
 *   fd: The file descriptor on which to write.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Outputs the character 'c' to the given file descriptor using write(2).
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
