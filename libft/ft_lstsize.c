/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:26:34 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:26:35 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// int	ft_lstsize(t_list *lst);

// int main(void)
// {
// 	t_list	*lst = NULL;
//     int		len;

//     int	data1 = 42;
//     int	data2 = 13;
//     int data3 = 10;
// 	ft_lstadd_front(&lst, ft_lstnew(&data1));
// 	ft_lstadd_front(&lst, ft_lstnew(&data2));
// 	ft_lstadd_front(&lst, ft_lstnew(&data3));

// 	len = ft_lstsize(lst);
//     printf("%d\n", len);
//     return (0);
// }

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst != (t_list *)0)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
