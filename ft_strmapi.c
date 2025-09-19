/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:47:43 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 12:19:33 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strmapi - Create a new string by applying a function to each character.
 *
 * Arguments:
 *   s: The string on which to iterate.
 *   f: The function to apply to each character, taking its index and value.
 *
 * Returns:
 *   The string created from the successive applications of 'f'.
 *   Returns NULL if the allocation fails.
 *
 * Description:
 *   Applies the function 'f' to each character of the string 's',
 *   passing its index as the first argument, and creates a new string
 *   (allocated with malloc) resulting from successive applications of 'f'.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	count;
	char	*s2;
	size_t	i;

	i = 0;
	count = ft_strlen(s);
	s2 = malloc((count + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (count > i)
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = 0;
	return (s2);
}
