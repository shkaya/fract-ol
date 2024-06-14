/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:07:05 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 16:50:31 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// char	toupper_str(unsigned int index, char c)
// {
//     (void)index;
//     if (97 <= c && c <= 122)
//     {
//         c -= 32;
//     }
//     return (c);
// }

// int main(void)
// {
// 	char	str[] = "Hello, world";
//     char	*result = ft_strmapi(str, toupper_str);

// 	if (result == NULL)
//     {
//         printf("error");
//         free(result);
//         return (1);
//     }
// 	int i = 0;
//     while (result[i] != '\0')
//     {
//         printf("%c", result[i]);
//         i++;
//     }
//     printf("\n");
//     return (0);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*p;
	int		i;

	if (s == (char const *)0 || f == NULL)
		return ((char *)0);
	len = ft_strlen(s);
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return ((char *)0);
	i = 0;
	while (0 < len)
	{
		p[i] = f(i, s[i]);
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}
