/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:03:15 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/16 17:43:54 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
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
 ps char	*ft_strrchr(const char *s, int c);
 */
// inspired by apple open source '83
// I use a char** str because the string *str will be changed in the func

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

// I first count 
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
// res = ft_split(" tripouille 42 ", ' ');
// 	printf("==== -%s-\n",res[0]);
	// printf("==== -%s \n",res[1]);
// freeTab(res);
// res = ft_split("  tripouille  42--", ' ');
// 	printf("==== %s \n",res[0]);
// 	printf("==== %s \n",res[1]);
// 	// printf("==== %s \n",res[2]);
// 	freeTab(res);
// // // 	/* 1 */ mcheck(tab, sizeof(char *) * 3);
// // // 	/* 2 */ check(!strcmp(tab[0], "tripouille"));
// // // 	/* 3 */ mcheck(tab[0], strlen("tripouille") + 1);
// // // 	/* 4 */ check(!strcmp(tab[1], "42"));
// // // 	/* 5 */ mcheck(tab[1], strlen("42") + 1);
// // // 	/* 6 */ check(tab[2] == NULL);
// // // 	freeTab(tab); showLeaks();
// // // 	tab = ft_split("tripouille", 0);
// // // 	/* 7 */ check(!strcmp(tab[0], "tripouille"));
// // // 	/* 8 */ check(tab[1] == NULL);
// // // 	freeTab(tab); showLeaks();
// --1-2--3---4----5-----42
// // // 	tab = ft_split("     ", ' ');
// // // 	/* 9 */ check(tab[0] == NULL);
// // // 	free(tab); showLeaks();
// // // 	char * invalidReadCheck = new char; *invalidReadCheck = 0;
// // // 	tab = ft_split(invalidReadCheck, 0);
// // // 	/* 10 */ check(tab[0] == NULL); delete invalidReadCheck;
// // // 	free(tab); showLeaks();
// // // 	tab = ft_split("chinimala", ' ');
// // // 	/* 11 */ mcheck(tab, sizeof(char *) * 2);
// // // 	/* 12 */ check(!strcmp(tab[0], "chinimala"));
// // // 	/* 13 */ check(tab[1] == NULL);
// // // 	freeTab(tab); showLeaks();
// // // 	tab = ft_split("", ' ');
// // // 	/* 14 */ mcheck(tab, sizeof(char *) * 1);
// // // 	/* 15 */ check(tab[0] == NULL);
// // // 	freeTab(tab); showLeaks();
// // // 	/* sguerra- */
// // // 	char * splitme = strdup("Tripouille");
// // // 	tab = ft_split(splitme, ' ');
// // // 	/* 16 */ mcheck(tab, sizeof(char *) * 2);
// // // 	/* 17 */ check(!strcmp(tab[0], "Tripouille"));
// // // 	/* 18 */ check(tab[1] == NULL);
// // // 	free(splitme); freeTab(tab); showLeaks();
// // // 	splitme = strdup("Tripouille ");
// // // 	tab = ft_split(splitme, ' ');
// // // 	/* 19 */ mcheck(tab, sizeof(char *) * 2);
// // // 	/* 20 */ check(!strcmp(tab[0], "Tripouille"));
// // // 	/* 21 */ check(tab[1] == NULL);
// // // 	free(splitme); freeTab(tab); showLeaks();
// // // 	splitme = strdup(" Tripouille");
// // // 	tab = ft_split(splitme, ' ');
// // // 	/* 22 */ mcheck(tab, sizeof(char *) * 2);
// // // 	/* 23 */ check(!strcmp(tab[0], "Tripouille"));
// // // 	/* 24 */ check(tab[1] == NULL);
// // // 	free(splitme); freeTab(tab); showLeaks();
// // // 	splitme = strdup(" Tripouille ");
// // // 	tab = ft_split(splitme, ' ');
// // // 	/* 25 */ mcheck(tab, sizeof(char *) * 2);
// // // 	/* 26 */ check(!strcmp(tab[0], "Tripouille"));
// // // 	/* 27 */ mcheck(tab[0], strlen("Tripouille") + 1);
// // // 	/* 28 */ check(tab[1] == NULL);
// // // 	free(splitme); freeTab(tab); showLeaks();
// // // 	/* wleite */
// // // 	splitme = strdup("--1-2--3---4----5-----42");
// // // 	tab = ft_split(splitme, '-');
// // // 	/* 29 */ mcheck(tab, sizeof(char *) * 7);
// // // 	/* 30 */ check(!strcmp(tab[0], "1"));
// // // 	/* 31 */ mcheck(tab[0], strlen("1") + 1);
// // // 	/* 32 */ check(!strcmp(tab[1], "2"));
// // // 	/* 33 */ mcheck(tab[1], strlen("2") + 1);
// // // 	/* 34 */ check(!strcmp(tab[2], "3"));
// // // 	/* 35 */ mcheck(tab[2], strlen("3") + 1);
// // // 	/* 36 */ check(!strcmp(tab[3], "4"));
// // // 	/* 37 */ mcheck(tab[3], strlen("4") + 1);
// // // 	/* 38 */ check(!strcmp(tab[4], "5"));
// // // 	/* 39 */ mcheck(tab[4], strlen("5") + 1);
// // // 	/* 40 */ check(!strcmp(tab[5], "42"));
// // // 	/* 41 */ mcheck(tab[5], strlen("42") + 1);
// // // 	/* 42 */ check(tab[6] == NULL);
// // // 	free(splitme); freeTab(tab); showLeaks();
// }