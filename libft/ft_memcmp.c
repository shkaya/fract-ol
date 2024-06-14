/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:35 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:46:21 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// int	ft_memcmp(const void *s1, const void *s2, size_t n);

// int main(void)
// {
//     char str1[] = "apple";
//     char str2[] = "applepen";
// 	int	result;
// 	int	ft_result;

//     result = memcmp(str1, str2, 7);
//     ft_result  = ft_memcmp(str1, str2, 7);
//     printf("%d\n", result);
//     printf("%d\n", ft_result);
//     return (0);
// }

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1 = s1;
	const unsigned char	*str2 = s2;

	while (0 < n)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
