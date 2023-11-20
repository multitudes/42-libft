/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:03:15 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/20 11:14:07 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

/*
 s:  The string to be split.
 c:  The delimiter character.
 Return value
 The array of new strings resulting from the split.
 NULL if the allocation fails.
 Allocates (with malloc(3)) and returns an array
 of strings obtained by splitting ’s’ using the
 character ’c’ as a delimiter.  The array must end
 with a NULL pointer.
 allowed are malloc, free
 */
// inspired by UNIX
// I use a char** str because the string *str will be changed 
// in the func
static char	*ft_strsep(char **str, char *delim)
{
	char	*s;
	int		c;
	char	*tok;	

	s = *str;
	while (*s == *delim)
		s++;
	if (*s == 0)
		return (NULL);
	tok = s;
	while (1)
	{
		c = *s++;
		if (c == *delim || c == '\0') 
		{
			if (c == 0)
				s = NULL;
			else
				s[-1] = 0;
			*str = s;
			return (tok);
		}
	}
}

// Counting the words divided by the char c 
static int	my_word_count(const char *s, char c)
{
	int		count;
	int		state;

	state = OUT;
	count = 0;
	while (*s != '\0' && (s != NULL))
	{
		if (*s == c)
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	*splitstr;	
	char	**arr;

	i = 0;
	count = 0;
	count = my_word_count(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	while (i < count)
	{
		splitstr = ft_strsep((char **)&s, &c); 
		arr[i] = ft_strdup(splitstr);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

// void freeTab(char * * tab)
// {
// 	for (int i = 0; tab[i] != NULL; ++i)
// 	{
// 		printf("freeing in arr[%d] ===> %s\n", i, tab[i]);
// 		free(tab[i]);
// 	}
// 	free(tab);
// }

// int main()
// {
// 	char **res5 = ft_split("hello", 0);
// 	printf("==== %s \n",res5[0]);
// 	//my_assert(ft_strncmp(res5[0], "hello", 5) == 0, "Output shd be hello");
// }

// int main()
// {
	// char test[45] = "---     hello-and-thanks for-all-the--fish---";
	// char **res = ft_split(test, '-');
// 	printf("==== %s \n",res[0]);
// 	printf("==== %s \n",res[1]);
// 	printf("==== %s \n",res[2]);
// 	printf("==== %s \n",res[3]);
// 	printf("==== %s \n",res[4]);
// 	printf("==== %s \n",res[5]);
// 	printf("==== %s \n",res[6]);
	// char test[45] = "--1-2--3---4----5-----42";
	// char **res = ft_split(test, '-');
	// printf("==== %s-\n",res[0]);
	// printf("==== %s \n",res[1]);
	// printf("==== %s \n",res[2]);
// 	// printf("==== %s \n",res[3]);
// freeTab(res);
// }
