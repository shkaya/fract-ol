/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:13:35 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 14:06:54 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

// int	main(void)
// {
// 	char dst[10];
//     char src[] = "hello";
// Case 1: dst is NULL
// segv
// 	printf("Return value when dst is NULL: %zu\n", strlcpy(NULL, src, 10));
// 	printf("Return value when dst is NULL: %zu\n", ft_strlcpy(NULL, src, 10));
// 	Case 2: src is NULL
// segv
// 	printf("Return value when src is NULL: %zu\n", strlcpy(dst, NULL, 10));
// 	printf("Return value when src is NULL: %zu\n", ft_strlcpy(dst, NULL, 10));
// Case 3: dstsize is 0
// return : src_size
// 	printf("Return value when dstsize is 0: %zu\n", strlcpy(dst, src, 0));
// 	printf("Return value when dstsize is 0: %zu\n", ft_strlcpy(dst, src, 0));
//     return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

size_t	ft_strlcpy(char *d, const char *s, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(s);
	i = 0;
	if (dstsize == 0)
		return (src_size);
	while (s[i] != '\0' && i < dstsize - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (src_size);
}
