/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:19:49 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:45:53 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <ctype.h>
// #include <stdio.h>

// int	ft_isdigit(int c);

// int	main(void)
// {
// 	char test_chars[] = {'a', '5', '!', '9', 'Z'};
// 	int	result;

// 	printf("Standard:");
// 	for(int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
// 	{
// 		result = isdigit(test_chars[i]);
// 		printf("%d,", result);
// 	}
// 	printf("\n42:");
// 	for(int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
// 	{
// 		result = ft_isdigit(test_chars[i]);
// 		printf("%d,", result);
// 	}
// 	printf ("\n");
// 	return(0);
// }

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
