/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:58:34 by shkaya            #+#    #+#             */
/*   Updated: 2024/05/02 15:04:28 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// char	**ft_split(char const *s, int c);
// size_t	ft_skipcount(char const *s, char c);

// int main(void)
// {
//     int	i = 0;
// // Case1: 
// 	char	**p = ft_split("//42//toyko",'/');
//     while(p[i])
//     printf("%s\n",p[i++]);
// //TEST
// 	printf("%zu\n", ft_skipcount("//42//tokyo//",'/'));
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

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char		*substr;
// 	size_t		i;
// 	size_t		j;

// 	if (s == (char *)0)
// 		return ((char *)0);
// 	substr = (char *)malloc(len + 1);
// 	if (substr == NULL)
// 		return ((char *)0);
// 	i = 0;
// 	j = start;
// 	while (0 < len && s[j] != '\0' && j <= ft_strlen(s))
// 	{
// 		substr[i] = s[j];
// 		i++;
// 		j++;
// 		len--;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }

static void	ft_free_pointer(char **p, int n)
{
	while (0 <= n)
		free(p[n--]);
	return ;
}

static size_t	ft_strchar_set(char const *s, char c, char **p)
{
	size_t	i;
	size_t	j;
	size_t	start_point;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		start_point = i;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
		{
			p[j] = ft_substr(s, start_point, i - start_point);
			if (p[j] == NULL)
			{
				ft_free_pointer(p, j - 1);
				return (1);
			}
		}
		j++;
	}
	return (0);
}

static size_t	ft_skipcount(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			i++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**p;

	if (s == (char const *)0)
		return ((char **)0);
	count = ft_skipcount(s, c);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (p == NULL)
		return ((char **)0);
	if (count != 0)
	{
		if (ft_strchar_set(s, c, p))
		{
			free (p);
			return ((char **)0);
		}
	}
	p[count] = (char *)0;
	return (p);
}
