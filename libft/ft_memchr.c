/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:12:56 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:46:16 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	*ft_memchr(const void *s, int c, size_t n);

// int main(void)
// {
//     char str1[] = "hello";
//     char	*p;
//     char	*ft_p;

//     p = memchr(str1, 'l', 4);
//     ft_p = ft_memchr(str1, 'l', 4);
// 	printf("%p\n", p);
//     printf("%p\n", ft_p);
//     return (0);
// }

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str;
	unsigned char			c2;

	c2 = c;
	str = s;
	while (0 < n)
	{
		if (*str == c2)
			return ((void *)str);
		str++;
		n--;
	}
	return ((void *)0);
}
