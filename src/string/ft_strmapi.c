/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:47:43 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:38:34 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each character of a string to create 
 * a new string
 * 
 * Applies the function 'f' to each character of the string 's', passing its
 * index as first argument to create a new string (with malloc) resulting
 * from successive applications of 'f'.
 * 
 * @param s The string on which to iterate
 * @param f The function to apply to each character (takes index and char, 
 * returns char)
 * @return The string created from the successive applications of 'f', 
 * or NULL if allocation fails
 * @note The caller is responsible for freeing the returned string
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
