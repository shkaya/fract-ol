/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:22:01 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:45:49 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <ctype.h>
// #include <stdio.h>

// int	ft_isascii(int c);

// int	main(void)
// {
// 	int test_chars[] = {0, 13, 57, 61, 73, 81, 97, 128, 357, 564, 48375};
//     int result;

// 	printf("Standard:");
//     for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
//     {
//         result = isascii(test_chars[i]);
//         printf("%d,", result);
//     }
//     printf("\n42:");
// 	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
//     {
//         result = ft_isascii(test_chars[i]);
//         printf("%d,", result);
//     }
// 	printf ("\n");
// 	return (0);
// }

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
