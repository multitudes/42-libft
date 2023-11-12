/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:44:16 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/10 14:44:18 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define UINT_MAX 4294967295
#define INT_MAX 2147483647
/*
 The malloc() function allocates size bytes of memory and returns a pointer 
 to the allocated memory The calloc() function contiguously allocates
 enough space for count objects that are size bytes of memory
 each and returns a pointer to the allocated memory.
 The allocated memory is filled with bytes of value zero.
 If successful, calloc(), malloc(), realloc(), reallocf(), valloc(),
 and aligned_alloc() functions return a pointer to allocated memory.
 If there is an error, they return a NULL pointer and set errno to ENOMEM.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	
	p = NULL;
	if ((count > (INT_MAX - 1) || size > (INT_MAX - 1)))
		if (!(size == 0) && !(count == 0))
			return (NULL);
	if (count == 0 || size == 0)
		count = size = 1;
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
