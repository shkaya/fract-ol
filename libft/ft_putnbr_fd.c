/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:55:14 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:47:11 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// void	ft_putnbr_fd(int n, int fd);

// int main(void)
// {
//     int n = 10;
//     ft_putnbr_fd(n,1);
//     write(1, "\n", 1);
// 	return (0);
// }

void	ft_putnbr_fd(int n, int fd)
{
	char	desit;
	long	ln;

	ln = (int)n;
	if (ln < 0)
	{
		ln = -ln;
		write(fd, "-", 1);
	}
	if (10 <= ln)
	{
		ft_putnbr_fd(ln / 10, fd);
	}
	desit = ln % 10 + '0';
	write (fd, &desit, 1);
}
