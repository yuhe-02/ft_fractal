#include "ft_fractal.h"

void set_error(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}