//#define DEBUG
#ifndef DEBUG
#include "title.h"
#include "ioput_function.h"
#include "solve_sq.h"

int main()
{


    coeff coef;
    input(&coef);
    coef.num = solve_sq(&coef);

    output(&coef);

    return 0;
}
#else
#include "title.h"
#include <stdio.h>
#include "unit_test.h"

int main()
{
    if(unit_tests() == 0)
        printf("OK\n");
}
#endif
