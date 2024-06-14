/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:50:46 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:46:38 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	*ft_memmove(void *dst, const void *src, size_t n);

// int main(void)
// {
// 	char str1[50];
//     char str2[] = "Hello,world";
// 	char ft_str1[50];
//     char ft_str2[] = "Hello,world";

//     memmove(str1, str2, 10);
//     ft_memmove(ft_str1, ft_str2, 10);
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%c", str1[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%c", ft_str1[i]);
//     }
// 	printf("\n");
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else if (d > s)
	{
		d += (n - 1);
		s += (n - 1);
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dest);
}
