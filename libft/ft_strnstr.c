/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:09:48 by shkaya            #+#    #+#             */
/*   Updated: 2024/04/28 14:34:17 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// int	main(void)
// {
	// char str[] = "42tokyo";
// Case1: str is NULL && len is NULL
// Return Value : 0x0
	// printf("Return Value : %p\n", strnstr(str, "42", 0));
	// printf("Return Value : %p\n", strnstr(str, "42", 0));
// Case2: str is NULL
// segv
	// printf("Return Value : %p\n", strnstr(NULL, "42", 10));
	// printf("Return Value : %p\n", strnstr(NULL, "42", 10));
// Case3: needle is NULL
// segv
	// printf("Return Value : %p\n", strnstr(str, NULL, 10));
	// printf("Return Value : %p\n", strnstr(str, NULL, 10));
// Case4: len is 0
// Return Value : 0x0
	// printf("Return Value : %p\n", strnstr(str, "42", 0));
	// printf("Return Value : %p\n", strnstr(str, "42", 0));
// Case5:
	// printf("Return Value : %p\n", strnstr(str, "\0", 0));
	// printf("Return Value : %p\n", strnstr(str, "\0", 0));
// Case6:
	// printf("Return Value : %p\n", strnstr("abbbcdefg", "bbc", 20));
	// printf("Return Value : %p\n", strnstr("abbbcdefg", "bbc", 20));
//     return (0);
// }

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	size_t		t_len;

	if (*needle == '\0')
		return ((char *)haystack);
	if (haystack == (char *)0 && len == 0)
		return ((char *)0);
	t_len = len;
	while (*haystack && 0 < len && 0 < t_len)
	{
		h = haystack;
		n = needle;
		t_len = len--;
		while (*h && *n && *h == *n && 0 < t_len)
		{
			h++;
			n++;
			t_len--;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return ((char *)0);
}
