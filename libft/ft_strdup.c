/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:54:35 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/27 22:52:25 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// char	*ft_strdup(const char *s1);

// int main(void)
// {
// 	int	i = 0;
// 	char str1[] = "Hello,world";
//     char	*p;
// 	char	*ft_p;

//     p = strdup(str1);
//     ft_p = ft_strdup(str1);
//     if (p == NULL || ft_p == NULL)
//     {
//         printf("error : p == NIULL or ft_p == NULL");
// 		return (1);
//     }
//     printf("Standard : %p\n", p);
//     while (p[i] != '\0')
//     {
//         printf("%c", p[i]);
// 		i++;
//     }
//     printf("\n");
//     i = 0;
//     printf("42 : %p\n", ft_p);
// 	while (ft_p[i] != '\0')
//     {
//         printf("%c", ft_p[i]);
//         i++;
//     }
//     printf("\n");
//     free(p);
//     free(ft_p);
//     return(0);
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

char	*ft_strdup(const char *s1)
{
	size_t	total;
	char	*p;
	int		i;

	total = ft_strlen(s1) + 1;
	p = (char *)malloc(total * sizeof(char));
	if (p == NULL)
		return ((char *)0);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
