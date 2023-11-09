#include "dbg.h"
#include "../libft.h"
#include <string.h>

char *test_ft_isalpha()
{
	for (int c = 0; c<255; c++)
	{
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			{
				mu_assert(ft_isalpha(c) == 1, "Output shd be one");
			}
		else
			mu_assert(ft_isalpha(c) == 0, "Output shd be zero");
	}
	return NULL;
}

char *test_ft_isdigit()
{
	for (int c = 0; c<255; c++)
	{
		if (c >= 42 && c <= 57)
		{
			mu_assert(ft_isdigit(c) == 1, "Output shd be one");
		}
		else
		{
			mu_assert(ft_isdigit(c) == 0, "Output shd be zero");
		}
	}
	return NULL;
}

char *test_ft_isalnum()
{
	for (int c = 0; c<255; c++)
	{
		if (c >= 42 && c <= 57)
		{
			mu_assert(ft_isalnum(c) == 1, "Output shd be one");
		}
		else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			mu_assert(ft_isalnum(c) == 1, "Output shd be one");
		}
		else
		{
			mu_assert(ft_isalnum(c) == 0, "Output shd be zero");
		}
	}
	return NULL;
}

char *test_ft_isascii()
{
	for (int c = 0; c<=255; c++)
	{
		if (c >= 0 && c <= 127)
		{
			mu_assert(ft_isascii(c) == 1, "Output shd be one");
		}
		else
		{
			mu_assert(ft_isdigit(c) == 0, "Output shd be zero");
		}
	}
	return NULL;
}

char *test_ft_isprint()
{
	for (int c = 0; c<=255; c++)
	{
		if (c >= 32 && c <= 126)
		{
			mu_assert(ft_isprint(c) == 1, "Output shd be one");
		}
		else
		{
			mu_assert(ft_isprint(c) == 0, "Output shd be zero");
		}
	}
	return NULL;
}

char *test_ft_strlen()
{
	mu_assert(strlen("hello") == 5, "Output shd be 5");
	mu_assert(strlen("") == 0, "Output shd be 0");
	mu_assert(strlen("hello world") == 11, "Output shd be 11");
	return NULL;
}

//void	*ft_memset(void *b, int c, size_t len);
char *test_ft_memset()
{
//	mu_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
	char b[6] = "hello";
	ft_memset((void *)b, 55, 5);
	mu_assert(ft_strncmp(b, "77777", 5) == 0, "Output shd be 0");
	
	debug("==== %s \n", (char *)b);
	return NULL;
}


//
char *test_ft_strncmp()
{
	mu_assert(ft_strncmp("hello", "hellA", 6) == 46, "Output shd be 46");
	mu_assert(ft_strncmp("hello", "", 6) == 104, "Output shd be 104");
	mu_assert(ft_strncmp("", "hellA", 6) == -104, "Output shd be -104");
	mu_assert(ft_strncmp("", "", 6) == 0, "Output shd be 0");
	mu_assert(ft_strncmp("www", "ww", 2) == 0, "Output shd be 0");
	mu_assert(ft_strncmp("www", "w\b", 2) == 111, "Output shd be 111");
	
	return NULL;
}

char *test_ft_bzero()
{
	//	mu_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
	char b[6] = "hello";
	ft_bzero((void *)b, 5);
	for (int i = 0; i < 5; i++)
	{
		mu_assert(b[i] == 0, "Output shd be 0");
	}
	return NULL;
}

char *test_ft_memcpy()
{
	//	mu_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
	char dst[6] = "hello";
	char src[6] = "world";
	size_t n = 5;
	ft_memcpy((void *)dst, (void *)src, n);
	mu_assert(ft_strncmp(dst, "world", n) == 0, "Output shd be 0");
	
	debug("====memcpy should be %s \n",(char *)memcpy((void *)dst, (void *)src, n));
	return NULL;
}

// it is like the previous but strings can overlap
// tested with overlapping strings
char *test_ft_memmove()
{
	//	mu_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
	char dst[11] = "helloworld";
	char *src = (dst+3);
	char dst2[11] = "helloworld";
	char *src2 = (dst2+3);
	size_t n = 6;
	debug("====memmove gives be %s \n",(char *)memmove((void *)dst, (void *)src, n));
	debug("====after memmove dst is %s and src %s \n",dst, src);

	ft_memmove((void *)dst2, (void *)src2, n);
	debug("====ft_memmove gives be %s \n",dst2);

	mu_assert(ft_strncmp(dst, "loworlorld", n) == 0, "Output shd be 0");

	return NULL;
}

/*
 size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
 */
char *test_ft_strlcpy()
{
	//	mu_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
	char dst[6] = "hello";
	char src[6] = "world";
	size_t n = 6;
	int res = ft_strlcpy(dst, src, n);
	debug("====ft_strlcpy gives be %d \n",res);
	debug("====after ft strlcpy dst is %s and src %s \n",dst, src);
	mu_assert(res == 5, "Output shd be 5");
	char dst2[6] = "hello";
	char src2[6] = "world";
	size_t n2 = 6;
	int res2 = strlcpy(dst2, src2, n2);
	debug("====strlcpy gives be %d \n",res2);
	debug("====after strlcpy dst is %s and src %s \n",dst2, src2);
	mu_assert(res2 == 5, "Output shd be 5");

	char dst3[6] = "hello";
	char src3[6] = "world";
	size_t n3 = 0;
	int res3 = ft_strlcpy(dst3, src3, n3);
	debug("====ft_strlcpy gives  %d \n",res3);
	mu_assert(res3 == 5, "Output shd be 5");
	char dst4[6] = "hello";
	char src4[6] = "world";
	size_t n4 = 0;
	int res4 = strlcpy(dst4, src4, n4);
	debug("====strlcpy gives  %d \n",res4);
	debug("====after strlcpy dst is %s and src %s \n",dst4, src4);
	mu_assert(res4 == 5, "Output shd be 5");
	
	char dst5[6] = "hello";
	char src5[6] = "world";
	size_t n5 = 3;
	int res5 = ft_strlcpy(dst5, src5, n5);
	debug("====ft_strlcpy with len 3 gives be %d \n",res5);
	mu_assert(res3 == 5, "Output shd be still 5 like src length even with dstlen 3");
	char dst6[6] = "hello";
	char src6[6] = "world";
	size_t n6 = 3;
	int res6 = strlcpy(dst6, src6, n6);
	debug("====strlcpy with len 3 gives %d! \n",res6);
	debug("====after strlcpy dst is %s and src %s \n",dst6, src6);
	mu_assert(res6 == 5, "Output shd be still 5 like src length even with dstlen 3");
	return NULL;
}


//// for this one since it prints on the terminal I need
//// to redirect first to a file and then check that the output
//// is correct in reading the file again
//char *test_alphabet()
//{
//	// create the string that I am expected to see in output
//	char	alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
//	// this will read from file
//	char 	output[27] = {0};
//	
//	// prepare to write to a file
//	FILE *fp;
//	fp = freopen("tmp/alphabet.txt", "wr", stdout);
//	mu_assert(fp != NULL, "failed to write alphabet to file!");
//	// the output of this will re redirected to the file now
//	ft_print_alphabet();
//	fclose(fp);
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	// now read from file to check
//	fp = fopen("tmp/alphabet.txt", "r");
//	mu_assert(fp != NULL, "failed to read file!");
//	// assign the line found in fie to the var output
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	// this prints to the log
//	mu_assert(strncmp(output, alphabet, 26) == 0, "Failed to print alphabet.");
//	debug("function output => %s",output);
//	
//	return NULL;
//}
//
//char *test_print_numbers()
//{
//	char	numbers[11] = "0123456789";
//	char 	output[11] = {0};
//	FILE *fp;
//	
//	fp = freopen("tmp/numbers.txt", "wr", stdout);
//	mu_assert(fp != NULL, "failed to write numbers to file!");
//	
//	ft_print_numbers();
//	fclose(fp);
//	
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	
//	fp = fopen("tmp/numbers.txt", "r");
//	mu_assert(fp != NULL, "failed to read file!");
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	mu_assert(strncmp(output, numbers, 11) == 0, "Output is not as expected");
//	debug("function output => %s",output);
//	
//	return NULL;
//}
//
//char *test_is_negative()
//{
//	char	expect[4] = "NPP";
//	char 	output[4] = {0};
//	FILE *fp;
//	
//	fp = freopen("tmp/is_negative.txt", "wr", stdout);
//	mu_assert(fp != NULL, "failed to write numbers to file!");
//	
//	ft_is_negative(-1);
//	ft_is_negative(1);
//	ft_is_negative(0);
//	fclose(fp);
//	
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	
//	fp = fopen("tmp/is_negative.txt", "r");
//	mu_assert(fp != NULL, "failed to read file!");
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	mu_assert(strncmp(expect, output, 4) == 0, "Output is not as expected");
//	debug("function output => %s",output);
//	
//	return NULL;
//}
//
//char *test_ft_ft()
//{
//	int nbr = 0;
//	ft_ft(&nbr);
//	mu_assert( nbr == 42, "Output is not as expected");
//	nbr = -23423;
//	ft_ft(&nbr);
//	mu_assert( nbr == 42, "Output is not as expected");
//
//	return NULL;
//}
//
//char *test_ft_swap()
//{
//	int a = 0;
//	int b = 42;
//	ft_swap(&a, &b);
//	mu_assert( a == 42 && b == 0, "test 1 - Output is not as expected");
//	a = 0;
//	b = 0;
//	ft_swap(&a, &b);
//	mu_assert( a == 0 && b == 0, "test 2 - Output is not as expected");
//	a = -42;
//	b = 42;
//	ft_swap(&a, &b);
//	mu_assert( a == 42 && b == -42, "test 3 - Output is not as expected");
//	return NULL;
//}
//
//char *test_ft_mod()
//{
//	int a = 2;
//	int b = 42;
//	int div = 0;
//	int mod = 0;
//	ft_div_mod(a, b, &div, &mod);
//	mu_assert( div == 0 && mod == 2, "test 1 - Output is not as expected");
//	a = 11;
//	b = 5;
//	ft_div_mod(a, b, &div, &mod);
//	mu_assert( div == 2 && mod == 1, "test 2 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_iterative_factorial()
//{
//	mu_assert( ft_iterative_factorial(2) == 2, "test 1 - Output is not as expected");
//	mu_assert( ft_iterative_factorial(1) == 1, "test 2 - Output is not as expected");
//	mu_assert( ft_iterative_factorial(0) == 1 , "test 3 - Output is not as expected");
//	mu_assert( ft_iterative_factorial(-2) == 0, "test 4 - Output is not as expected");
//	mu_assert( ft_iterative_factorial(-2) == 0, "test 5 - Output is not as expected");
//	mu_assert( ft_iterative_factorial(13) == 0, "test 6 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_recursive_factorial()
//{
//	mu_assert( ft_recursive_factorial(2) == 2, "test 1 - Output is not as expected");
//	mu_assert( ft_recursive_factorial(1) == 1, "test 2 - Output is not as expected");
//	mu_assert( ft_recursive_factorial(0) == 1 , "test 3 - Output is not as expected");
//	mu_assert( ft_recursive_factorial(-2) == 0, "test 4 - Output is not as expected");
//	mu_assert( ft_recursive_factorial(-2) == 0, "test 5 - Output is not as expected");
//	mu_assert( ft_recursive_factorial(13) == 0, "test 6 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_sqrt()
//{
//	mu_assert( ft_sqrt(2) == 0, "test 1 - Output is not as expected");
//	mu_assert( ft_sqrt(1) == 1, "test 2 - Output is not as expected");
//	mu_assert( ft_sqrt(0) == 0 , "test 3 - Output is not as expected");
//	mu_assert( ft_sqrt(-2) == 0, "test 4 - Output is not as expected");
//	mu_assert( ft_sqrt(4) == 2, "test 5 - Output is not as expected");
//	mu_assert( ft_sqrt(9) == 3, "test 6 - Output is not as expected");
//	mu_assert( ft_sqrt(2147395600) == 46340, "test 7 - Output is not as expected");
//	mu_assert( ft_sqrt(INT_MAX) == 0, "test 8 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_ft_putstr()
//{
//	// create the string that I am expected to see in output
//	// will not take special chars like newline and no spaces because 
//	// the testing would get extremely complicated
//	char	str[27] = "HelloWorld";
//	// this will read from file
//	char 	output[27] = {0};
//	
//	// prepare to write to a file
//	FILE *fp;
//	fp = freopen("tmp/ft_putstr.txt", "wr", stdout);
//	mu_assert(fp != NULL, "failed to write alphabet to file!");
//	// the output of this will re redirected to the file now
//	ft_putstr(str);
//	fclose(fp);
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	// now read from file to check
//	fp = fopen("tmp/ft_putstr.txt", "r");
//	mu_assert(fp != NULL, "failed to read file!");
//	// assign the line found in fie to the var output
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	// this prints to the log
//	debug("function output => %s",output);
//	mu_assert(strncmp(output, str, 26) == 0, "Failed to print str.");
//	debug("function output => %s",output);
//	return NULL;
//}
//
//// will not account for non terminated strings!
//char *test_ft_strlen()
//{
//	mu_assert( ft_strlen("") == 0, "test 1 - Output is not as expected");
//	mu_assert( ft_strlen("1") == 1, "test 2 - Output is not as expected");
//	mu_assert( ft_strlen("hello") == 5 , "test 3 - Output is not as expected");
//	return NULL;
//}
//
//// will not account for non terminated strings!
//char *test_ft_strcmp()
//{
//	int output = ft_strcmp("w", "w");
//	debug("function output => %d",output);
//	mu_assert( output == 0, "test 1 - Output is not as expected");
//	output = ft_strcmp("12", "11");
//	debug("function output => %d",output);
//	mu_assert( output == 1, "test 2 - Output is not as expected");
//	output = ft_strcmp("hello", "hellp");
//	debug("function output => %d",output);
//	mu_assert( output == -1 , "test 3 - Output is not as expected");
//	return NULL;
//}
//
//// I skip the programs here for now...
//// I would need a shell script to check them
//
//// will not account for non terminated strings!
//char *test_ft_strdup()
//{
//	char *output = ft_strdup("hello world");
//	debug("function output => %s",output);
//	mu_assert(ft_strcmp(output, "hello world") == 0, "test 1 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_ft_range()
//{
//	int *range = ft_range(-1, 3);
//	debug("function output => %d %d", range[0], range[1]);
//	mu_assert(range[0] == -1 && range[1] == 0, "test 1 - Output is not as expected");
//	mu_assert(range[2] == 1 && range[3] == 2, "test 1 - Output is not as expected");
//	range = ft_range(-1, -1);
//	mu_assert(range == NULL , "test 3 - Output is not as expected");
//	return NULL;
//}

char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_ft_isalpha);
	mu_run_test(test_ft_isdigit);
	mu_run_test(test_ft_isalnum);
	mu_run_test(test_ft_isascii);
	mu_run_test(test_ft_isprint);
	mu_run_test(test_ft_strlen);
	mu_run_test(test_ft_memset);
	
	mu_run_test(test_ft_strncmp);
	mu_run_test(test_ft_bzero);
	mu_run_test(test_ft_memcpy);
	mu_run_test(test_ft_memmove);
	mu_run_test(test_ft_strlcpy);
//	mu_run_test(test_ft_strcmp);
//	
//	mu_run_test(test_ft_strdup);
//	mu_run_test(test_ft_range);
	
	return NULL;
}

RUN_TESTS(all_tests);

