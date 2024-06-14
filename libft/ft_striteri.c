/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:27:04 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/24 16:44:39 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// void	test_function(unsigned int index, char *c)
// {
// 	printf("Index: %u, Char: %c\n", index, *c);
// }

// int main(void)
// {
// 	char	str[] = "abcde";
// 	ft_striteri(str, test_function);
//     return (0);
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s == (char *)0 || f == NULL)
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
