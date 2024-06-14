/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:26:29 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:26:30 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// t_list	*ft_lstnew(void *content);

// int main(void)
// {
//     t_list	*lst;
//     t_list	*current;
//     int	data1;

// 	data1 = 42;
// 	lst = ft_lstnew(&data1);
//     if (lst == NULL)
//     	return (0);
// 	current = lst;
//     printf("%d\n", *((int *)current->content));
//     free(lst);
//     return (0);
// }

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return ((t_list *)0);
	lst->content = content;
	lst->next = (t_list *)0;
	return (lst);
}
