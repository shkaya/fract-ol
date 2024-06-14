/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:25:34 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:25:35 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	dataprint(void *content)
// {
// 	printf("%d\n", *((int *)content));
// }

// int main(void)
// {
// 	t_list	*lst = NULL;

// 	int	data1 = 42;
// 	int	data2 = 13;
//     int	data3 = 10;

// 	ft_lstadd_front(&lst, ft_lstnew(&data1));
//     ft_lstadd_front(&lst, ft_lstnew(&data2));
//     ft_lstadd_front(&lst, ft_lstnew(&data3));

// 	ft_lstiter(lst, dataprint);
//     ft_lstclear(&lst, NULL);
//     return (0);
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != (t_list *)0)
	{
		f(lst->content);
		lst = lst->next;
	}
}
