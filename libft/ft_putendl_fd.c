/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:46:42 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 18:03:45 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

// void	ft_putendl_fd(char *s, int fd);

// int main(void)
// {
// 	char str[] = "Hello,world";
// 	ft_putend_fd(str, 1); //0,1,2
//     return (0);
// }

void	ft_putendl_fd(char *s, int fd)
{
	if (s == (char *)0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
