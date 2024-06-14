/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:06:41 by shkaya            #+#    #+#             */
/*   Updated: 2024/05/02 16:58:06 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int	ft_atoi(const char *str);

// int main(void)
// {
// Case1: str is NULL
	// printf("%d\n", atoi(NULL));
	// printf("%d\n", ft_atoi(NULL));
// Case2: str is ""
	// printf("%d\n", atoi(""));
	// printf("%d\n", ft_atoi(""));
// Case3: str is "hello"
	// printf("%d\n", atoi("hello"));
	// printf("%d\n", ft_atoi("hello"));
// Case4: LONG_MAX
// LONG_MAX = 9223372036854775807
	// printf("%d\n", atoi("9223372036854775807"));
	// printf("%d\n", ft_atoi("9223372036854775807"));
// Case5: LONG_MIN
// LONG_MIN = -9223372036854775808
	// printf("%d\n", atoi("-9223372036854775808"));
	// printf("%d\n", ft_atoi("-9223372036854775808"));
// Case6: INT_MIN
// INT_MIN = -2147483648
	// printf("%d\n", atoi("-2147483648"));
	// printf("%d\n", ft_atoi("-2147483648"));
// Case7: INT_MAX
// INT_MAX = 214748367
	// printf("%d\n", atoi("214748367"));
	// printf("%d\n", ft_atoi("214748367"));
// Case8: skip?
	// printf("%d\n", atoi("\e06050"));
	// printf("%d\n", ft_atoi("\e06050"));
// Case: skip?
	// printf("%d\n", atoi("\t\v\f\r\n \f- \f\t\n\r    06050"));
	// printf("%d\n", ft_atoi("\t\v\f\r\n \f- \f\t\n\r    06050"));
//     return (0);
// }

static int	is_negative(const char **nptr)
{
	int		negative;

	negative = 0;
	while (**nptr == ' ' || **nptr == '\n' || **nptr == '\t'
		|| **nptr == '\r' || **nptr == '\f' || **nptr == '\v')
		(*nptr)++;
	if (**nptr == '-')
	{
		negative = 1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (negative);
}

static int	get_base(const char **nptr, int base)
{
	if (base == 0)
	{
		if (**nptr == '0')
		{
			(*nptr)++;
			if (**nptr == 'x' || **nptr == 'X')
			{
				base = 16;
				(*nptr)++;
			}
			else
				base = 8;
		}
		else
			base = 10;
	}
	return (base);
}

static long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int		negative;
	long	result;
	int		digit;

	negative = is_negative(&nptr);
	base = get_base(&nptr, base);
	result = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		digit = *nptr - '0';
		if (digit >= base)
			break ;
		if (negative && (result > (LONG_MAX - digit) / base))
			return (0);
		if (!negative && (result > (LONG_MAX - digit) / base))
			return (LONG_MAX);
		result = result * base + digit;
		nptr++;
	}
	if (negative)
		result = -result;
	if (endptr != (char **)0)
		*endptr = (char *)nptr;
	return (result);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, (char **)0, 10));
}
