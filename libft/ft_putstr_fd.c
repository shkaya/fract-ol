/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:39:42 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 17:41:45 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// void	ft_putstr_fd(char *s, int fd);

// int main(void)
// {
// 	char	str[] = "Hello,world";
// 	ft_putstr_fd(str, 1);
// 	write(1, "\n", 1);
//     return (0);
// }

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	char	*p;

	i = 0;
	if (s == (char *)0)
		return ;
	p = s;
	while (*s++)
		i++;
	write(fd, p, i);
}
