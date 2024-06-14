/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:17:11 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 17:08:28 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	ft_strncmp(const char *s1, const char *s2, size_t n);

// int main(void)
// {
	// char str[] = "42tokyo";
	// char str2[] = "32tokyo";
// Case1: str2 is NULL && n is 0
// Return Value : 0
	// printf("%d\n", strncmp(str, NULL, 0));
	// printf("%d\n", ft_strncmp(str, NULL, 0));
// Case2: str1 is NULL && n is 0
// Return Value :  0
	// printf("%d\n", strncmp(NULL, str, 0));
	// printf("%d\n", ft_strncmp(NULL, str, 0));
// Case3: str1 is NULL && str2 is NULL && n is 0
// Return Value :  0
	// printf("%d\n", strncmp(NULL, NULL, 0));
	// printf("%d\n", ft_strncmp(NULL, NULL, 0));
// Case4: n is 0
// Return Value :  0
	// printf("%d\n", strncmp(str, str2, 0));
	// printf("%d\n", ft_strncmp(str, str2, 0));
// Case5: str is NULL
// segv
	// printf("%d\n", strncmp(NULL, str2, 10));
	// printf("%d\n", ft_strncmp(NULL, str2, 10));
// Case6: str2 is NULL
// segv
	// printf("%d\n", strncmp(str, NULL, 10));
	// printf("%d\n", ft_strncmp(str, NULL, 10));
//     return (0);
// } 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return ((int)0);
	while (*s1 != '\0' && *s2 != '\0' && 0 < n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return ((int)0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
