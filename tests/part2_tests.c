#include "dbg.h"
#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>

char *test_ft_substr()
{
	char test[20] = "hello world!";
	char *sub1 = ft_substr(test, 6, 4);
	debug("==== %s \n",sub1) ;
	mu_assert(ft_strncmp(sub1, "worl", 4) == 0, "Output shd be 0");
	free(sub1);

	char *sub2 = ft_substr(test, 10, 4);
	debug("==== %s \n",sub2) ;
	mu_assert(ft_strncmp(sub2, "d!", 2) == 0, "Output shd be 0");
	free(sub2);
	
//	char * s = ft_substr("tripouille", 0, 42000);
//	/* 1 */ check(!strcmp(s, "tripouille"));
//	/* 2 */ mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
//	
//	s = ft_substr("tripouille", 1, 1);
//	/* 3 */ check(!strcmp(s, "r"));
//	/* 4 */ mcheck(s, 2); free(s); showLeaks();
//	
//	s = ft_substr("tripouille", 100, 1);
//	/* 5 */ check(!strcmp(s, ""));
//	/* 6 */ mcheck(s, 1); free(s); showLeaks();
//	
//	char * str = strdup("1");
//	s = ft_substr(str, 42, 42000000);
//	/* 7 */ check(!strcmp(s, ""));
//	/* 8 */ mcheck(s, 1); free(s); free(str); showLeaks();
//	
//	str = strdup("0123456789");
//	s = ft_substr(str, 9, 10);
//	/* 9  mbueno-g */ check(!strcmp(s, "9"));
//	/* 10  mbueno-g */ mcheck(s, 2); free(s); free(str); showLeaks();
//	
//	s = ft_substr("42", 0, 0);
//	/* 11  fcaquard */ check(!strcmp(s, ""));
//	/* 12  fcaquard */ mcheck(s, 1); free(s); showLeaks();
//	
//	s = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
//	/* 13  dfarhi */ check(!strcmp(s, "LES HARICOTS !"));
//	/* 14  dfarhi */ mcheck(s, 15); free(s); showLeaks();
//	
//	s = ft_substr("test", 1, 2);
//	/* 15  dfarhi */ check(!strcmp(s, "es"));
//	/* 16  dfarhi */ mcheck(s, 3); free(s); showLeaks();
	
	return NULL;
}

char *test_ft_strjoin()
{
	char test[20] = "hello ";
	char test2[20] = "world!";
	char *sub1 = ft_strjoin(test, test2);
	debug("==== %s \n",sub1) ;
	mu_assert(ft_strncmp(sub1, "hello world!", 12) == 0, "Output shd be hello world!");
	free(sub1);

	char test3[20] = "";
	char test4[20] = "world!";
	char *sub2 = ft_strjoin(test3, test4);
	debug("==== %s \n",sub2) ;
	mu_assert(ft_strncmp(sub2, "world!", 6) == 0, "Output shd be world!");
	free(sub2);

	char test5[20] = "";
	char test6[20] = "";
	char *sub3 = ft_strjoin(test5, test6);
	debug("==== %s \n",sub3) ;
	mu_assert(ft_strncmp(sub3, "", 1) == 0, "Output shd be ''");
	free(sub3);

	char test7[20] = " hello";
	char test8[20] = "";
	char *sub4 = ft_strjoin(test7, test8);
	debug("==== %s \n",sub4) ;
	mu_assert(ft_strncmp(sub4, " hello", 6) == 0, "Output shd be hello");
	free(sub4);
	return NULL;
}

char *test_ft_strtrim()
{
	char test[30] = "hel-?lo ? ?!!? ?~~\t?~?~!-";
	char set[20] = " !-?~\t";
	char *res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	mu_assert(ft_strncmp(res, "hel-?lo", 7) == 0, "Output shd be hel-?lo");
	free(res);

//	char * s = ft_strtrim("   xxxtripouille", " x");
//	/* 1 */ check(!strcmp(s, "tripouille"));
//	/* 2 */ mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
//	
//	s = ft_strtrim("tripouille   xxx", " x");
//	/* 3 */ check(!strcmp(s, "tripouille"));
//	/* 4 */ mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
//	
//	s = ft_strtrim("   xxxtripouille   xxx", " x");
//	/* 5 */ check(!strcmp(s, "tripouille"));
//	/* 6 */ mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
//	
//	s = ft_strtrim("   xxx   xxx", " x");
//	/* 7 */ check(!strcmp(s, ""));
//	/* 8 */ mcheck(s, 1); free(s); showLeaks();
//	
//	s = ft_strtrim("", "123");
//	/* 9 */ check(!strcmp(s, ""));
//	/* 10 */ mcheck(s, 1); free(s); showLeaks();
//	
//	s = ft_strtrim("123", "");
//	/* 11 */ check(!strcmp(s, "123"));
//	/* 12 */ mcheck(s, 4); free(s); showLeaks();
//	
//	s = ft_strtrim("", "");
//	/* 13 */ check(!strcmp(s, ""));
//	/* 14 */ mcheck(s, 1); free(s); showLeaks();
//	
//	s = ft_strtrim("abcdba", "acb");
//	/* opsec-infosec 15 */ check(!strcmp(s, "d"));
//	/* opsec-infosec 16 */ mcheck(s, 2); free(s); showLeaks();
//	
	return NULL;
}

char *test_ft_split()
{
	char test[30] = "hello-and-thanks for-the-fish";
	char **res = ft_split(test, '-');
	debug("==== %s \n",res[0]);
	debug("==== %s \n",res[1]);
	debug("==== %s \n",res[2]);
	debug("==== %s \n",res[3]);
	debug("==== %s \n",res[4]);

	mu_assert(ft_strncmp(res[0], "hello", 5) == 0, "Output shd be hello");
	mu_assert(ft_strncmp(res[1], "and", 3) == 0, "Output shd be hello");
	mu_assert(ft_strncmp(res[2], "thanks for", 10) == 0, "Output shd be hello");
	mu_assert(ft_strncmp(res[3], "the", 3) == 0, "Output shd be hello");
	mu_assert(ft_strncmp(res[4], "fish", 4) == 0, "Output shd be fish");
	
	char **res2 = ft_split(test, ' ');
	debug("==== %s \n",res2[0]);
	debug("==== %s \n",res2[1]);
	
	mu_assert(ft_strncmp(res2[0], "hello-and-thanks", 5) == 0, "Output shd be hello-and-thanks");
	mu_assert(ft_strncmp(res2[1], "for-the-fish", 3) == 0, "Output shd be for-the-fish");

	char **res3 = ft_split(test, '!');
	debug("==== %s \n",res3[0]);
	mu_assert(ft_strncmp(res3[0], test, 20) == 0, "Output shd be hello-and-thanks for-the-fish");

	char **res4 = ft_split("", '!');
	debug("==== %s \n",res4[0]);
	mu_assert(ft_strncmp(res4[0], "", 1) == 0, "Output shd be empty");

	
	for (int i = 0; res[i] != NULL; i++)
		free(res[i]);
	free(res);	
	for (int i = 0; res2[i] != NULL; i++)
		free(res2[i]);
	free(res2);
	for (int i = 0; res3[i] != NULL; i++)
		free(res3[i]);
	free(res3);	
	for (int i = 0; res4[i] != NULL; i++)
		free(res4[i]);
	free(res4);
	return NULL;
}

char *test_ft_itoa()
{
	// int max is still 2147483647 on a 64 bit machine
	debug("====int max ==  %d",INT_MAX);
	
	char *test = ft_itoa(INT_MAX);
	debug("====ft_itoa( INT_MAX ) ==  %s",test);
	mu_assert(ft_strncmp(test, "2147483647", 10) == 0, "Output shd be 0");
	
	test = ft_itoa(-2147483648);
	debug("====ft_itoa( int min ) ==  %s",test);
	mu_assert(ft_strncmp(test, "-2147483648", 11) == 0, "Output shd be 0");
	
	test = ft_itoa(-1);
	debug("====ft_itoa( -1 ) ==  %s",test);
	mu_assert(ft_strncmp(test, "-1", 2) == 0, "Output shd be 0");
	
	test = ft_itoa(5);
	debug("====ft_itoa( 5 ) ==  %s",test);
	mu_assert(ft_strncmp(test, "5", 1) == 0, "Output shd be 0");
	
	free(test);
	return NULL;
}

//declare f as pointer to function (unsigned int, char) returning char
char f(unsigned int a, char c);

char f(unsigned int a, char c)
{
	char	e;
	
	e = 'e';
	if ((a % 2) || (c == 'a'))
		e = c;

	return e;
}

char *test_ft_strmapi()
{
	char s[40] = "hello-and-thanks for-all-the-fish";
	char *test = ft_strmapi(s, f);
//	eeele-ane-ehanesefereaeleteeefese
	debug("====test ==  %s",test);
	mu_assert(ft_strncmp(test, "eeele-ane-ehanesefereaeleteeefese", 30) == 0, "Output shd be 0");
	
	char s2[40] = "";
	test = ft_strmapi(s2, f);
	//	eeele-ane-ehanesefereaeleteeefese
	debug("====test ==  %s",test);
	mu_assert(ft_strncmp(test, "", 1) == 0, "Output shd be 0");

	char s3[4] = "eh";
	test = ft_strmapi(s3, f);
	debug("====test ==  %s",test);
	mu_assert(ft_strncmp(test, "eh", 2) == 0, "Output shd be 0");

	
	free(test);
	return NULL;
}

//declare f as pointer to function (unsigned int, char) returning char
void f2(unsigned int a, char* c);

void f2(unsigned int a, char* c)
{
	if ((a % 2) || (*c == 'a'))
		 ;
	else
		*c = 'e';
}

char *test_ft_striteri()
{
	char s[40] = "hello-and-thanks for-all-the-fish";
	ft_striteri(s, f2);
//	eeele-ane-ehanesefereaeleteeefese
	debug("====test ==  %s",s);
	mu_assert(ft_strncmp(s, "eeele-ane-ehanesefereaeleteeefese", 30) == 0, "Output shd be 0");
	
	char s2[40] = "";
	ft_striteri(s2, f2);
	debug("====test ==  %s",s2);
	mu_assert(ft_strncmp(s2, "", 1) == 0, "Output shd be 0");

	char s3[4] = "eh";
	ft_striteri(s3, f2);
	debug("====test ==  %s",s3);
	mu_assert(ft_strncmp(s3, "eh", 2) == 0, "Output shd be 0");

	return NULL;
}

char *test_ft_putchar_fd()
{
	
	ft_putchar_fd('t', 2);
	ft_putchar_fd('h', 2);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('n', 2);
	ft_putchar_fd('k', 2);
	ft_putchar_fd('s', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('f', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('l', 2);
	ft_putchar_fd('l', 2);
	ft_putchar_fd(' ', 2);
	ft_putchar_fd('t', 2);
	ft_putchar_fd('h', 2);
	ft_putchar_fd('e', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('f', 2);
	ft_putchar_fd('i', 2);
	ft_putchar_fd('s', 2);
	ft_putchar_fd('h', 2);
	
	return NULL;
}

char *test_ft_putstr_fd()
{
	ft_putstr_fd("hello-and-thanks for-all-the-fish", 2);
	ft_putstr_fd("2147483648", 2);
	
	return NULL;
}

char *test_ft_putendl_fd()
{
	ft_putendl_fd("2147483648", 2);
	ft_putendl_fd("hello-and-thanks for-all-the-fish", 2);

	ft_putendl_fd("", 2);
	ft_putendl_fd("1", 2);
	
	return NULL;
}

char *test_ft_putnbr_fd()
{

	ft_putnbr_fd(-2147483648, 2);
	ft_putnbr_fd(2147483647, 2);
	ft_putnbr_fd(0, 2);
	ft_putnbr_fd(1, 2);
	ft_putnbr_fd(-1, 2);
	
	return NULL;
}

char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_ft_substr);
	mu_run_test(test_ft_strjoin);
	mu_run_test(test_ft_strtrim);
	mu_run_test(test_ft_split);
	mu_run_test(test_ft_itoa);
	mu_run_test(test_ft_strmapi);
	mu_run_test(test_ft_striteri);
	mu_run_test(test_ft_putchar_fd);
	mu_run_test(test_ft_putstr_fd);
	mu_run_test(test_ft_putendl_fd);
	mu_run_test(test_ft_putnbr_fd);
	
	return NULL;
}

RUN_TESTS(all_tests);

