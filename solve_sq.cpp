#include "title.h"
#include "solve_sq.h"
#include "equal_double.h"
#include <math.h>


static int solve_lin(double k, double b, double *x);

int solve_sq(coeff* cf)
{
    if (equal_double(cf->a, 0))
        return solve_lin(cf->b, cf->c, &cf->x1);

    if (equal_double(cf->c, 0))
    {
        if(equal_double(cf->b, 0))
            return 1;

        cf->x2 = 0;
        return (solve_lin(cf->a, cf->b, &cf->x1) + 1);
    }

    double d = (cf->b * cf->b) - 4 * cf->a * cf->c;

    if (d > 0)
    {
        double sqd = sqrt(d);

        cf->x1 = (-cf->b + sqd) / (2 * cf->a);
        cf->x2 = (-cf->b - sqd) / (2 * cf->a);

        return 2;
    }

    if (d < 0)
        return 0;

    if (d == 0)
    {
            cf->x1 = (-cf->b) / (2 * cf->a);

            return 1;
    }
}

static int solve_lin(double k, double b, double *x)
{
    if (k == 0 && b == 0)
        return INF_ROOTS;

    if (k == 0)
        return 0;

    *x = - b / k;

    return 1;
}

