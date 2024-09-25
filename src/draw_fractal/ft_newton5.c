#include "ft_fractal.h"

static double complex newton_method(double complex z, double power, double section) 
{
    double complex f;
    double complex df;

    f = cpow(z, power) + section;
    df = power * cpow(z, power - 1) ;
    if (creal(df) != 0 || cimag(df) != 0) 
        return (z - f / df);
    else
        return (z);
}

static double complex root_of_func(double complex z, int *iterations, double power, double section) 
{
    int     counter;
    double  complex z_new;
    double  eps;

    counter = 0;
    while (counter < MAX_ITER) 
    {
        z_new = newton_method(z, power, section);
        eps = cabs(z_new - z);
        if (eps < EPS)
            break ;
        z = z_new;
        counter++;
    }
    *iterations = counter; // 反復回数を返す
    return z_new;
}

t_coord *calc_newton5_set(t_data *img, int x, int y) 
{
    t_coord *cd;
    int     iterations;
    double  complex z;
    double  complex  root;

    cd = (t_coord *)malloc(sizeof(t_coord));
    if (!cd)
        exit(1);
    cd->zx = (x - WIDTH / 2.0) * (FRACTAL_RANGE / WIDTH) / img->zoom + img->offsetX;
    cd->cx = (y - HEIGHT / 2.0) * (FRACTAL_RANGE / HEIGHT) / img->zoom + img->offsetY;
    z = cd->zx + cd->cx * I;
    root = root_of_func(z, &iterations, img->param1, img->param2);
    cd->cx = creal(z);  // zの実部
    cd->cy = cimag(z);  // zの虚部
    cd->zx = creal(root);  // rootの実部
    cd->zy = cimag(root);  // rootの虚部
    cd->iterations = iterations;
    return (cd);
}
