/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:24:53 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:24:56 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// int main(void)
// {
// 	t_list	*lst = NULL;
//     t_list	*current;
//     t_list	*tmp;

// 	int	data1 = 42;
//     int data2 = 13;
//     int data3 = 10;

// 	ft_lstadd_back(&lst, ft_lstnew(&data1));
// 	ft_lstadd_back(&lst, ft_lstnew(&data2));
//     ft_lstadd_back(&lst, ft_lstnew(&data3));

// 	current = lst;
//     while (current != NULL)
//     {
// 		printf("%d\n", *((int *)current->content));
//         tmp = current;
//         current = current->next;
//         free(tmp);
//     }
// 	return (0);
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != (t_list *)0)
		last = last->next;
	last->next = new;
}
