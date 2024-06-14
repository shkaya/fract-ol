/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:25:39 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:25:41 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// int main(void)
// {
//     t_list	*lst = NULL;
//     t_list	*lst_last;

// 	int	data1 = 42;
//     int data2 = 13;
//     int data3 = 10;

//     ft_lstadd_front(&lst, ft_lstnew(&data1));
//     ft_lstadd_front(&lst, ft_lstnew(&data2));
//     ft_lstadd_front(&lst, ft_lstnew(&data3));
// 	lst_last = ft_lstlast(lst);
//     printf("%d\n", *((int *)lst_last->content));
//     return (0);
// }

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return ((t_list *)0);
	while (lst->next != (t_list *)0)
		lst = lst->next;
	return (lst);
}
