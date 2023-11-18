/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:59:08 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/16 19:53:40 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"
#include "libft.h"

/*
 lst:  The address of a pointer to a node.
 del:  The address of the function used to delete
 the content of the node.
 Deletes and frees the given node and every
 successor of that node, using the function ’del’
 and free(3).
 Finally, the pointer to the list must be set to
 NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	**l;
	t_list	*temp;

	if (*lst == NULL)
		return;
	l = lst;
	temp = *lst;
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		ft_lstdelone(temp, del);
		temp = *lst;
	}
	ft_lstdelone(temp, del);
	*l = NULL;
}

//void	del(void *content)
//{
//	printf("==== freed content  %s =====  \n", (char*)content);
//}
//
//int main()
//{
//	t_list *list = NULL;
//	char *test1 = "hello world!";
//	char *test2 = "Another hello world!";
//	char *test3 = "A third hello world!";
//	
//	list = ft_lstnew(test1);
//	t_list *new = ft_lstnew(test2);
//	ft_lstadd_front(&list, new);
//	
//	new = ft_lstnew(test3);
//	ft_lstadd_front(&list, new);
//	
//	printf("==== %s \n",(char*)list->content);
//	int count = ft_lstsize(list);
//	printf("==== counting the list now %d =====  \n", count);
//	ft_lstclear(&list, del);
//	return 0;
//}
