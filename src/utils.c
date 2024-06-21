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

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	total;
	char	*p;
	int		i;

	total = ft_strlen(s1) + 1;
	p = (char *)malloc(total * sizeof(char));
	if (p == NULL)
		return ((char *)0);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
