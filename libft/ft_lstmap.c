/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:25:47 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:26:23 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	*double_f(void *content)
// {
//     *((int *)content) *= 2;
//     return (content);
// }

// void	del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list	*lst = NULL;
//     t_list	*new_lst;
//     t_list 	*current;

// 	int	*data1 = (int *)malloc(sizeof(int));
//     int	*data2 = (int *)malloc(sizeof(int));
//     int	*data3 = (int *)malloc(sizeof(int));
// 	*data1 = 42;
// 	*data2 = 13;
// 	*data3 = 10;
// 	ft_lstadd_front(&lst, ft_lstnew(data1));
//     ft_lstadd_front(&lst, ft_lstnew(data2));
//     ft_lstadd_front(&lst, ft_lstnew(data3));
// 	new_lst = ft_lstmap(lst, double_f, del);
//     current = new_lst;
//     while (current != NULL)
//     {
//         printf("%d\n", *((int *)current->content));
//         current = current->next;
//     }

//     return (0);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*current;
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return ((t_list *)0);
	new_lst = (t_list *)0;
	current = lst;
	while (current != (t_list *)0)
	{
		new_node = ft_lstnew(f(current->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return ((t_list *)0);
		}
		ft_lstadd_back(&new_lst, new_node);
		current = current->next;
	}
	return (new_lst);
}
