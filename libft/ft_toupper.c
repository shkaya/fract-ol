/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:59:34 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:49:39 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <ctype.h>

// int	ft_toupper(int c);

// int	main(void)
// {
//     printf("%c\n", toupper ('b'));
//     printf("%c\n", ft_toupper('b'));
//     return (0);
// }

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		c -= 'a' - 'A';
	}
	return (c);
}
