/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:28:46 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/15 17:40:37 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Outputs the integer ’n’ to the given file
 descriptor.
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	*temp;
	size_t	c;

	temp = ft_itoa(n);
	c = ft_strlen(temp);
	write(fd, temp, c);
	free(temp);
}
