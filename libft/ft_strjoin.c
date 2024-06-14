/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:58:49 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 17:05:55 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// char	*ft_strjoin(char const *s1, char const *s2);

// int main (void)
// {
//     char	str1[] = "Hello";
//     char	str2[] = "world";
// 	char	*p;

//     p = ft_strjoin(str1, str2);
// 	if (p == NULL)
// 	{
// 		printf("error");
// 		return (1);
// 	}
//     printf("%p\n", p);
// 	int	i = 0;
//     while (p[i] != '\0')
//     {
//         printf("%c", p[i]);
//         i++;
//     }
// 	printf("\n");
//     free(p);
//     return (0);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	total;
	int		i;
	int		j;

	if (s1 == (char const *)0 || s2 == (char const *)0)
		return ((char *)0);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(total * sizeof(char));
	if (p == NULL)
		return ((char *)0);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	return (p);
}
