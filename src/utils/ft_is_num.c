#include "ft_fractal.h"

int	ft_is_num(int c)
{
	if (c >= '0' && c <= '9')
		return (FT_TRUE);
	return (FT_FALSE);
}