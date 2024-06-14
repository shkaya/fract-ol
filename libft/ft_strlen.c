/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:41:58 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:48:29 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlen(const char *s);
// // #define size_t unsigned long
// int	main(void)
// {
// 	int 	result;
// 	char 	str[] = "Hello,world!urvbru";

// 	result = strlen(str);
//     printf("%s : %d\n", str, result);
//     result = ft_strlen(str);
// 	printf("%s : %d\n", str, result);
// }

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
