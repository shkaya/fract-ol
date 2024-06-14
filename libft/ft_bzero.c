/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:18:02 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:45:23 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <strings.h>

// void	ft_bzero(void *s, size_t n);

// int main(void)
// {
//     char str[] = "Hello, world";
//     char ft_str[] = "Hello, world";
//     bzero(str, 5);
//     ft_bzero(ft_str, 5);
//     for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
//     {
//         printf("%c", str[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < sizeof(ft_str) / sizeof(ft_str[0]); i++)
//     {
//         printf("%c", ft_str[i]);
//     }
//     printf("\n");
//     return (0);
// }

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (0 < n)
	{
		*p = (unsigned char)0;
		p++;
		n--;
	}
}
