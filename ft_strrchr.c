/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:32:28 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 14:39:26 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of a character in a string
 * 
 * Locates the last occurrence of c (converted to a char) in the string
 * pointed to by s. The terminating null character is considered to be
 * part of the string; therefore if c is '\0', the function locates
 * the terminating '\0'.
 * 
 * @param s The string to search in
 * @param c The character to search for
 * @return A pointer to the last occurrence of the character, 
 * or NULL if not found
 * @note Returns NULL if s is NULL (differs from standard strrchr)
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

//int main()
//{
//	char s1[] = "tripouille";
//	printf("is this NULL? %s \n",ft_strrchr(s1, 'z'));
//	if ((char*)ft_strrchr(s1, 'z') == (char*)NULL)
//		printf("null after all.. \n");
//	printf("is this NULL? %s \n",(char*)NULL);
//	return (0);
//}
//char arr[BUFSIZ];
//
//bytes_read = read(fd, arr, BUFSIZ))
//while (bytes_read  > 0)
//{
//	if (write(1, arr, bytes_read) != bytes_read)
//		... write(1, "write error on file ...",24;
//	bytes_read = read(fd, arr, BUFSIZ))
//}
