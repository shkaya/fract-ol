/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:25:20 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:25:21 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
// 	t_list	*lst = NULL;
//     t_list	*current;

// 	int	*data1 = (int *)malloc(sizeof(int));
//     int	*data2 = (int *)malloc(sizeof(int));
//     int	*data3 = (int *)malloc(sizeof(int));

//     *data1 = 42;
//     *data2 = 13;
//     *data3 = 10;

// 	ft_lstadd_front(&lst, ft_lstnew(data1));
//     ft_lstadd_front(&lst, ft_lstnew(data2));
//     ft_lstadd_front(&lst, ft_lstnew(data3));

// 	current = lst;
//     while (current != NULL)
//     {
//         printf("%d\n", *((int *)current->content));
//         current = current->next;
//     }
//     ft_lstclear(&lst, del);
//     printf("%p\n", lst);
//     return (0);
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current != (t_list *)0)
	{
		tmp = current;
		current = current->next;
		if (del)
			del(tmp->content);
		free(tmp);
	}
	*lst = (t_list *)0;
}
