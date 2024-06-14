/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:35:09 by shkaya            #+#    #+#             */
/*   Updated: 2024/05/02 16:57:48 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <stdio.h>

// char	*ft_itoa(int n);
// int	numlen(long ln);

// int main(void)
// {
// 	char	*p;

// 	p = ft_itoa(-12345678);
//     if (p == NULL)
//     {
//     	printf("error: p == NULL\n");
//         return (1);
//     }
//     int	i = 0;
//     while (p[i] != '\0')
//     {
//         printf("%c", p[i]);
//         i++;
//     }
// 	printf("\n");
// 	return (0);
// }

static int	numlen(long ln)
{
	int	i;

	i = 0;
	if (ln == 0)
		i++;
	while (1 <= ln)
	{
		ln = ln / 10;
		i++;
	}
	return (i);
}

static long	power(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	else
	{
		return (base * power(base, exponent - 1));
	}
}

static void	num_cpy(int sign, char *p, long ln)
{
	int	i;
	int	num;

	num = numlen(ln);
	i = 0;
	if (sign)
		p[i++] = '-';
	while (0 < num)
	{
		p[i++] = (ln / power(10, num - 1)) % 10 + '0';
		num--;
	}
	p[i] = '\0';
}

char	*ft_itoa(int n)
{
	long	ln;
	int		sign;
	char	*p;

	ln = (long)n;
	sign = 0;
	if (ln < 0)
	{
		ln = -ln;
		sign = 1;
	}
	if (sign)
		p = (char *)malloc(numlen(ln) * sizeof(char) + 2);
	else
		p = (char *)malloc(numlen(ln) * sizeof(char) + 1);
	if (p == NULL)
		return ((char *)0);
	num_cpy(sign, p, ln);
	return (p);
}
