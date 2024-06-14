/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:25:26 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 17:24:18 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	del(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
//     t_list	*lst = NULL;
// 	int		*data1 = (int *)malloc(sizeof(int));
// 	*data1 = 42;
// 	ft_lstadd_front(&lst, ft_lstnew(data1));
//     printf("%d\n", *((int *)lst->content));
//     ft_lstdelone(lst, del);
//     // printf("%d\n", *((int *)lst->content));
// 	return (0);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == (t_list *)0)
		return ;
	if (del)
		del(lst->content);
	else
		return ;
	free(lst);
}
