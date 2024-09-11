#include "ft_fractal.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*str2;
	size_t			last;

	if (!(s))
		return (0);
	last = 0;
	str2 = (char *)s;
	if ((int)start < ft_strlen(str2))
		last = ft_strlen(str2) - start;
	if (last > len)
		last = len;
	str = (char *)malloc(last + 1);
	if (!(str))
		return (NULL);
	ft_strlcpy(str, str2 + start, last + 1);
	return (str);
}