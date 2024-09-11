#include "ft_fractal.h"

char *ft_delete_space(const char *str)
{
	int	i;
	int	start;
	char *str2;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	start = i;
	while (!(ft_isspace(str[i])) && str[i])
		i++;
	str2 = ft_substr(str, start, i - start);
	if (!str2)
		exit(1);
	return (str2);
}