/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:11:53 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:23:03 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a string followed by a newline to a file descriptor
 * 
 * Outputs the string 's' to the given file descriptor followed by
 * a newline character.
 * 
 * @param s The string to output
 * @param fd The file descriptor on which to write
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
