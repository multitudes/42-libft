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
	
	char *test = ft_itoa(-122);
	debug("====ft_itoa( 0 ) ==  %s",test);
	mu_assert(ft_strncmp(test, "0", 1) == 0, "Output shd be 0");
	
//	mu_assert(ft_atoi("-0") == 0, "Output shd be 0");
//	debug("====atoi( -0 ) ==  %d",atoi("-0"));
//	
//	debug("====atoi(  \t++0) ==  %d",atoi("  \t++0"));
//	mu_assert(ft_atoi("  \t++0") == 0, "Output shd be 0");
//	
//	mu_assert(ft_atoi("  \t\v\f\n\radd") == 0, "Output shd be 0");
//	debug("====atoi( +0 ) ==  %d",atoi("  \t\v\f\n\radd"));
//	mu_assert(ft_atoi("2147483647") == 2147483647, "Output shd be int max");
//	debug("====atoi( int max) ==  %d",atoi("2147483647"));
//	
//	debug("====atoi( int max) ==  %d",atoi("21474836488"));
//	mu_assert(ft_atoi("21474836488") == 8, "Output shd be overflow max");
//	debug("====atoi( int min) ==  %d",atoi("-2147483648"));
//	mu_assert(ft_atoi("-2147483648") == -2147483648, "Output shd be int min");
//	debug("====atoi( int min) ==  %d",atoi("-2"));
//	mu_assert(ft_atoi("-2") == -2, "Output shd be int min");
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
	
	return NULL;
}

RUN_TESTS(all_tests);

