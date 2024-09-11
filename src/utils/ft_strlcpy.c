#include "ft_fractal.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(src + i))
		i++;
	if (!n)
		return (i);
	while (j < n - 1 && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}