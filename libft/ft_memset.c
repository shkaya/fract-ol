/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:19:22 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:46:46 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	*ft_memset(void *b, int c, size_t len);

// int	main(void)
// {
// 	char str[5];
//     char ft_str[5];

// 	memset(str, 'A', 5);
//     ft_memset(ft_str, 'A', 5);

// 	printf("Standard:");
//     for (int i = 0; i < 5; i++)
//     {
// 		printf("%c", str[i]);
//     }
//     printf("\n");

//     printf("42:");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%c", ft_str[i]);
//     }
//     printf("\n");
//     return (0);
// }

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (0 < len)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}
