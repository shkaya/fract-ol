/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:06:27 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/29 11:30:07 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// void	*ft_calloc(size_t count, size_t size);

// int	main(void)
// {
// 	char	*p;
// 	char	*ft_p;
// 	int		n = 5;

// // Case1:
// 	p = (char *)calloc(n, sizeof(char));
// 	ft_p = (char *)ft_calloc(n, sizeof(char));
// // Case2:
// 	// p = (char *)calloc(0, 0);
// 	// ft_p = (char *)ft_calloc(0, 0);
// 	if (p == NULL || ft_p == NULL)
// 	{
// 		printf("error : p == NULL or ft_p == NULL\n");
// 		return (1);
// 	}
// 	printf("%p\n", p);
// 	printf("%p\n", ft_p);
// 	printf("ARRAY :|");
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("%c|", p[i]);
// 	}
// 	printf("\n");
// 	printf("FT_ARRAY :|");
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("%c|", ft_p[i]);
// 	}
// 	printf("\n");
// 	free(p);
// 	free(ft_p);
// 	return (0);
// }

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*p;

// 	p = b;
// 	while (0 < len)
// 	{
// 		*p = (unsigned char)c;
// 		p++;
// 		len--;
// 	}
// 	return (b);
// }

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (size != 0 && count > SIZE_MAX / size)
	{
		return ((void *)0);
	}
	total = count * size;
	if (total == 0)
		return ((void *)0);
	p = malloc(total);
	if (p == NULL)
	{
		return ((void *)0);
	}
	ft_memset(p, 0, total);
	return (p);
}
