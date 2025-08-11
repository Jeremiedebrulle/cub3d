/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:00:48 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 09:34:50 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*current;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	current = start;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		current->next = new_node;
		current = new_node;
		lst = lst->next;
	}
	return (start);
}

// #include <stdio.h>

// void *test(void *c)
// {
// 	return (c);
// }

// void test_free(void *c)
// {
// 	printf("del %s\n", c);
// 	(void)c;
// }

// void print(void *c)
// {
// 	printf("node = %s\n", c);
// }

// int main()
// {
// 	t_list *n = ft_lstnew("n1");
// 	ft_lstadd_back(&n, ft_lstnew("n2"));
// 	ft_lstadd_back(&n, ft_lstnew("n3"));
// 	ft_lstadd_back(&n, ft_lstnew("n4"));
// 	ft_lstadd_back(&n, ft_lstnew("n5"));
// 	ft_lstadd_back(&n, ft_lstnew("n6"));

// 	t_list *f = ft_lstmap(n, test, test_free);
// 	if (f == NULL)
// 		printf("f == null\n");
// 	else
// 		ft_lstiter(f, print);
// 	printf("size = %d\n", ft_lstsize(f));
// }
