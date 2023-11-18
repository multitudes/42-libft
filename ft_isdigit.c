/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:27:42 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/15 17:49:52 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 The isdigit() function tests for a decimal digit character.  Regardless of locale, this
 includes the following characters only:
 
 ``0''``1''``2''``3''``4''
 ``5''``6''``7''``8''``9''
 RETURN VALUES
 The isdigit() and isnumber() functions return zero if the character tests false and
 return non-zero if the character tests true.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
