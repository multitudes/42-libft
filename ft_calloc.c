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
	void	*ptr;
	
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
