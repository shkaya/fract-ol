/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:25:07 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 19:25:09 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	ft_lstadd_front(t_list **lst, t_list *new);

// int main(void)
// {
//     t_list	*lst = NULL;
//     t_list	*current;
//     t_list 	*tmp;

// 	int	data1 = 42;
//     int	data2 = 13;

// 	ft_lstadd_front(&lst, ft_lstnew(&data1));
//     current = lst;
//     printf("%d\n", *((int *)current->content));
//     ft_lstadd_front(&lst, ft_lstnew(&data2));
//     current = lst;
//     printf("%d\n", *((int *)current->content));
//     while (current != NULL)
//     {
//         printf("%d\n", *((int *)current->content));
//         tmp = current;
//         current = current->next;
//         free(tmp);
//     }
//     return (0);
// }

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
