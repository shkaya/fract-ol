/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:47:26 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 14:07:13 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// int	main(void)
// {
	// char dst[10];
	// char src[] = "42tokyo";
// Case 1: dst is NULL
// segv
	// printf("Return value when dst is NULL: %zu\n", strlcat(NULL, src, 10));
	// printf("Return value when dst is NULL: %zu\n", ft_strlcat(NULL, src, 10));
// Case 2: src is NULL
// segv
	// printf("Return value when src is NULL: %zu\n", strlcat(dst, NULL, 10));
	// printf("Return value when src is NULL: %zu\n", ft_strlcat(dst, NULL, 10));
// Case 3: dstsize is 0
// return : src_size(= strlen(src))
	// printf("Return value when dstsize is 0: %zu\n", strlcat(dst, src, 0));
	// printf("Return value when dstsize is 0: %zu\n", ft_strlcat(dst, src, 0));
// Case 4: dst is NULL && dstsize = 0
// return : src_size(= strlen(src))
	// printf("Return value : %zu\n", strlcat(NULL, src, 0));
	// printf("Return value : %zu\n", ft_strlcat(NULL, src, 0));
	// return (0);
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	int		i;
	int		j;

	if ((dst == (char *)0) && (dstsize == 0))
		return (ft_strlen(src));
	total = ft_strlen(dst) + ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = 0;
	while ((dst[i] != '\0') && (0 < dstsize - 1))
	{
		i++;
		dstsize--;
	}
	j = 0;
	while (src[j] != '\0' && (0 < dstsize - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (total);
}
