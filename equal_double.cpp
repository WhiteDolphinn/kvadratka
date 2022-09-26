#include <math.h>
#include "equal_double.h"

int equal_double(double a, double b)
{
    if(fabs(a - b) < 1e-7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
