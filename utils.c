#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	char	*p;

	i = 0;
	if (s == (char *)0)
		return ;
	p = s;
	while (*s++)
		i++;
	write(fd, p, i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}