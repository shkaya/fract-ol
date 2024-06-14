/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:22:25 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/29 15:39:10 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// char	*ft_strchr(const char *s, int c);

// int main(void)
// {
//     char	str1[] = "hello";
//     char	*p;
//     char	*ft_p;

// 	p = strchr(str1, '\0');
//     ft_p = ft_strchr(str1, '\0');
//     printf("%p\n", p);
//     printf("%p\n", ft_p);
//     return (0);
// }

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c || *s == c - 256 || *s == c + 256)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)0);
}
