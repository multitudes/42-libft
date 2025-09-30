/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:28:46 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 13:23:29 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs an integer to a file descriptor
 * 
 * Outputs the integer 'n' to the given file descriptor by converting
 * it to a string and writing it.
 * 
 * @param n The integer to output
 * @param fd The file descriptor on which to write
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
