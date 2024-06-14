/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:22:19 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 11:06:49 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <ctype.h>
// #include <stdio.h>

// int	ft_isalnum(int c);

// int main(void)
// {
// 	int	result;
// 	char test_chars[] = {35, 'a', 36, '5', 65};

// 	printf("Standard:");
// 	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
//     {
//         result = isalnum(test_chars[i]);
// 		printf("%d,", result);
//     }
//     printf("\n42:");
//     for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[i]); i++)
//     {
//         result = ft_isalnum(test_chars[i]);
//         printf("%d,",result);
//     }
// 	printf ("\n");
// 	return(0);
// }

int	ft_isalnum(int c)
{
	if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
