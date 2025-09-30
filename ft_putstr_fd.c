/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:49:09 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:23:50 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a string to a file descriptor
 * 
 * Outputs the string 's' to the given file descriptor using write().
 * 
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		return ;
	count = (int)ft_strlen(s);
	write(fd, s, count);
}
