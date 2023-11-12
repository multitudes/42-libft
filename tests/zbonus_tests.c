#include "dbg.h"
#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "../_bonus.h"

static t_list *list = NULL;
char *test1 = "hello world!";
char *test2 = "Another hello world!";
char *test3 = "A third hello world!";

char *test_ft_lstnew()
{
	list = ft_lstnew(test1);
	mu_assert(list != NULL, "failed to create node");
	debug("==== %s \n",(char*)list->content);
	mu_assert(ft_strncmp(test1, (char*)list->content, 10) == 0, "failed to get content");
	
	list->content = test2;
	debug("==== %s \n",(char*)list->content);
	mu_assert(ft_strncmp(test2, (char*)list->content, 10) == 0, "failed to get content");
	list->content = test3;
	debug("==== %s \n",(char*)list->content);
	mu_assert(ft_strncmp(test3, (char*)list->content, 10) == 0, "failed to get content");
	
	return NULL;
}

char *test_ft_lstadd_front()
{
	list->content = test1;
	t_list *new = ft_lstnew(test2);
	mu_assert(new != NULL, "failed to create node");
	debug("==== new node value %s \n",(char*)new->content);
	mu_assert(ft_strncmp(test2, (char*)new->content, 10) == 0, "failed to get content");
	
	ft_lstadd_front(&list, new);
	debug("==== %s first node value is now same as new \n",(char*)list->content);
	mu_assert(ft_strncmp(test2, (char*)list->content, 10) == 0, "failed to get content");
	debug("==== next node val is old first node value %s \n",(char*)list->next->content);
	mu_assert(ft_strncmp(test1, (char*)list->next->content, 10) == 0, "failed to get content");
	

	return NULL;
}


char *test_ft_lstsize()
{
	int count = ft_lstsize(list);
	debug("==== counting the list now %d =====  \n", count);
	mu_assert(count == 2, "starting point of test is wrong");
	t_list *new = ft_lstnew(test3);
	mu_assert(new != NULL, "failed to create node");
	debug("==== new node value %s \n",(char*)new->content);
	mu_assert(ft_strncmp(test3, (char*)new->content, 10) == 0, "failed to get content");
	
	ft_lstadd_front(&list, new);
	debug("==== first node value is now same as test3 ==> %s \n",(char*)list->content);
	mu_assert(ft_strncmp(test3, (char*)list->content, 10) == 0, "failed to get content");
	count = ft_lstsize(list);
	debug("==== counting the list %d =====  \n", count);
	debug("==== content first %s =====  \n", (char*)list->content);
	debug("==== content second %s =====  \n", (char*)list->next->content);
	debug("==== content third %s =====  \n", (char*)list->next->next->content);
	
	return NULL;
}

char *test_ft_lstlast()
{
	int count = ft_lstsize(list);
	debug("==== counting the list now %d =====  \n", count);
	mu_assert(count == 3, "starting point of test is wrong");
	
	t_list *last = ft_lstlast(list);
	mu_assert(last != NULL, "failed to get last");
	debug("==== content last %s =====  \n", (char*)last->content);
	
	mu_assert(ft_strncmp(test1, (char*)last->content, 10) == 0, "failed to last list content");
	
	return NULL;
}

char *test_ft_lstadd_back()
{
	t_list *backnode = ft_lstnew("to add on the back!");
	mu_assert(list != NULL, "failed to create node");
	ft_lstadd_back(&list,backnode);
	
	t_list *last = ft_lstlast(list);
	mu_assert(last != NULL, "failed to get last");
	debug("==== content last %s =====  \n", (char*)last->content);
	mu_assert(ft_strncmp("to add on the back!", (char*)last->content, 10) == 0, "failed to last list content");
	return NULL;
}

void	del(void *content);
void	del(void *content)
{
	debug("==== freed content  %s =====  \n", (char*)content);
}

// bug here because I need to wlk down the list and set the
// next property of the previous node to null as well!
char *test_ft_lstdelone()
{
	t_list *new = ft_lstnew(test1);
	mu_assert(new != NULL, "failed to get node");
	debug("==== content last %s =====  \n", (char*)new->content);
	ft_lstdelone(new,del);
	debug("==== freed  node =====  \n");
	return NULL;
}

//ft_lstclear(t_list **lst, void (*del)(void*))
char *test_ft_lstclear()
{
	list = NULL;
	
	list = ft_lstnew(test1);
	t_list *new = ft_lstnew(test2);
	ft_lstadd_front(&list, new);
	
	new = ft_lstnew(test3);
	ft_lstadd_front(&list, new);
	
	debug("==== %s \n",(char*)list->content);
	int count = ft_lstsize(list);
	debug("==== counting the list now %d =====  \n", count);
	ft_lstclear(&list, del);
	count = ft_lstsize(list);
	debug("==== counting the empty list now %d =====  \n", count);
	mu_assert(count == 0, "list not empty");
	mu_assert(list == NULL, "list pointer not freed");
	
	return NULL;
}

void f2(void *content);
void f2(void *content)
{
	debug("=== content of node => %s\n", (char*)content);
	
}

//void	ft_lstiter(t_list *lst, void (*f)(void *))
char *test_ft_lstiter()
{
	// list clear ran on the last test!
	list = NULL;
	
	list = ft_lstnew(test1);
	t_list *new = ft_lstnew(test2);
	ft_lstadd_front(&list, new);
	
	new = ft_lstnew(test3);
	ft_lstadd_front(&list, new);
	
	int count = ft_lstsize(list);
	debug("==== counting the list now %d =====  \n", count);
	mu_assert(count == 3, "starting point of test is wrong");
	

	ft_lstiter(list, f2);
	
	return NULL;
}



char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_ft_lstnew);
	mu_run_test(test_ft_lstadd_front);
	mu_run_test(test_ft_lstsize);
	mu_run_test(test_ft_lstlast);
	mu_run_test(test_ft_lstadd_back);
	mu_run_test(test_ft_lstdelone);
	mu_run_test(test_ft_lstclear);
	mu_run_test(test_ft_lstiter);
	
	return NULL;
}

RUN_TESTS(all_tests);

