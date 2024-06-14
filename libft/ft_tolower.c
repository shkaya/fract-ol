/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:15:15 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/22 16:49:35 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <ctype.h>

// int	ft_tolower(int c);

// int main(void)
// {
//     printf("%c\n", tolower('a'));
//     printf("%c\n", ft_tolower('a'));
//     return (0);
// }

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		c += 'a' - 'A';
	}
	return (c);
}
