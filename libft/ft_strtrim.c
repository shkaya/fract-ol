/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:18:13 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/25 11:49:48 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strtrim(char const *s1, char const *set);

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("", ""));
//     printf("%s\n", ft_strtrim("    hello world     ", " "));
//     printf("%s\n", ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz"));
// 	// char str[] = "Hello world";
//     // char	*p = ft_substr(str, 5, 6);
//     // printf("%s\n", p);

//     // char *p = ft_strchr(str, 'H');
//     // printf("%ld\n", str - p);
//     // printf("%p\n",p);
//     return (0);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	len;

	len = 0;
	if (s1 == (char *)0)
		return ((char *)0);
	if (set != (char *)0)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
	}
	len = ft_strlen(s1);
	if (set != (char *)0)
	{
		while (0 < len && ft_strchr(set, s1[len - 1]))
			len--;
	}
	p = ft_substr(s1, 0, len);
	if (p == (char *)0)
		return ((char *)0);
	return (p);
}
