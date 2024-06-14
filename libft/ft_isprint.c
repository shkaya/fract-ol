/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:17:44 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:45:58 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <ctype.h>

// int	ft_isprint(int c);

// int	main(void)
// {
// 	char test_chars[] = {0, 31, 65, 126, 127};
// 	int	result;

// 	printf("Standard:");
//     for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
//     {
//         result = isprint(test_chars[i]);
//         printf("%d,", result);
//     }
//     printf("\n42:");
//     for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
//     {
//         result = ft_isprint(test_chars[i]);
//         printf("%d,", result);
//     }
// 	printf("\n");
//     return (0);
// }

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
