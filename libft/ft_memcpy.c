/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuntakaya <shuntakaya@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:12 by shkaya            #+#    #+#             */
/*   Updated: 2024/05/07 10:07:45 by shuntakaya       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	*ft_memcpy(void *dst, const void *src, size_t n);

// int	main(void)
// {
//     char str1[20];
//     char str2[] = "hello, world";
//     char ft_str1[20];
//     char ft_str2[] = "hello, world";

// 	memcpy(str1, str2, 5); 
//     ft_memcpy(ft_str1, ft_str2, 5);

// 	int i = 0;
//     while(str1[i] != '\0')
//     {
//         printf("%c", str1[i]);
//         i++;
//     }
//     printf("\n");
//     i = 0;
//     while (ft_str1[i] != '\0')
//     {
//         printf("%c", ft_str1[i]);
//         i++;
//     }
//     printf("\n");
//     return (0);
// }

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return ((void *)0);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (0 < n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
