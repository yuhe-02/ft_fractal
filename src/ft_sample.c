#include "stdio.h"
#include "stdlib.h"
#include <complex.h>


typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

t_complex	ft_complex_add(t_complex z1, t_complex z2)
{
	t_complex	z;

	z.real = z1.real + z2.real;
	z.imag = z1.imag + z2.imag;
	return (z);
}

int main()
{
	t_complex z1;
	t_complex z2;
	double complex s1;
	double complex zero = 0.0 + 0.0 * I; // 複素数 0
	

	z1.real = 1;
	z1.imag = 1;
	z2.real = 3;
	z2.imag = 3;
	s1 = 1.0 + 2.0 * I;

	z1 = z2;
	s1 = s1 / zero;

	printf("%f %f \n", z1.real, z1.imag);
	printf("結果: %f + %fi\n", creal(s1), cimag(s1)); 
}