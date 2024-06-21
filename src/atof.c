#include "fractol.h"

// What is "atof"
// 文字列からdouble型の数値に変換する関数。

/* ポインタの中身を操作したい時は、()を忘れずに！！　*/
#include <stdio.h>

static int	power(int base, int index)
{
	if (index > 0)
		return (base * power(base, index - 1));
	else
		return (1);
}

static int	is_sign(const char **str)
{
	int	sign;

	sign = 0;
	if (**str == '-')
	{
		sign = 1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static double	change_to_double(const char *str, int *len)
{
	int		desimal_point_found;
	double	result;

	desimal_point_found = 0;
	result = 0;
	while (*str != '\0')
	{
		if (*str == '.')
		{
			desimal_point_found = 1;
			str++;
		}
		if ('0' <= *str && *str <= '9')
		{
			result = (result * 10) + (*str - '0');
			if (desimal_point_found)
				(*len)++;
		}
		else
			break ;
		str++;
	}
	return (result);
}

double	my_atof(const char *str)
{
	int		sign;
	double	result;
	int		len;

	sign = is_sign(&str);
	len = 0;
	result = change_to_double(str, &len);
	result = result / (double)power(10, len);
	if (sign)
		result = -result;
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//     printf("%f\n", atof("3.14987pdd"));
//     printf("%f\n", my_atof("3.14987pdd"));
//     return (0);
// }
