/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:50:52 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/29 15:37:05 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// char	*ft_strrchr(const char *s, int c);

// int main(void)
// {
// 	char str1[] = "hello";
//     char	*p;
// 	char	*ft_p;

//     p = strchr(str1, 'l');
//     printf("standard strchr : %p\n", p);
//     p = strrchr(str1, 'l' + 256);
//     printf("standard strrchr : %p\n", p);

// 	ft_p = ft_strrchr(str1, 'l' + 256);
//     printf("42 : %p\n", ft_p);
// 	return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	s += ft_strlen(s);
	while (0 < i)
	{
		if (*s == (char)c || *s == c - 256 || *s == c + 256)
			return ((char *)s);
		i--;
		s--;
	}
	return ((char *)0);
}
