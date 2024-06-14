/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:05:28 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:45:42 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <ctype.h>
// #include <stdio.h>

// int	ft_isalpha(int c);

// int	main(void)
// {
// 	int		a;
// 	int		ft_a;
// 	char	b;

// 	b = 'c';
// 	a = isalpha(b);
// 	ft_a = ft_isalpha(b);
// 	printf("%d\n", a);
// 	printf("%d\n", ft_a);
// 	return (0);
// }

int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
