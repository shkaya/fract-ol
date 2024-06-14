/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:04:04 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/29 12:49:23 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len);

// int main(void)
// {
// 	char	str[] = "libft-test-tokyo";
// 	char	*p;
// 	int		i;

// 	p = ft_substr(str, 15, 100);
//     printf("%p\n", p);
// 	i = 0;
// 	while (p[i] != '\0')
//     {
// 		printf("%c", p[i]);
//         i++;
//     }
//     printf("\n");
//     free(p);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	size;

	substr = (char *)0;
	if (s == (char *)0)
		return (substr);
	size = ft_strlen(s);
	if (size < start)
		len = 0;
	if ((size - start) < len)
		len = size - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr)
	{
		i = 0;
		while (len-- && s[start + i])
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
