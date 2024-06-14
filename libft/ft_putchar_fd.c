/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:48 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:46:52 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>

// void	ft_putchar_fd(char c, int fd);

// int main(void)
// {
//     ft_putchar_fd('a', 1);
//     write(1, "\n", 1);
//     return (0);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
