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
	free(sub3);
	return NULL;
}

char *test_ft_strtrim()
{
	char test[20] = "hel-?lo ???!!??~~?~?~!-";
	char set[20] = " !-?~\t";
	char *res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	mu_assert(ft_strncmp(res, "hel-?lo", 7) == 0, "Output shd be hello world!");
	free(rea);

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
	free(sub3);
	return NULL;
}


char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_ft_substr);
	mu_run_test(test_ft_strjoin);
	mu_run_test(test_ft_strtrim);
	
	return NULL;
}

RUN_TESTS(all_tests);

