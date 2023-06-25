#include "title.h"
#include "unit_test.h"
#include <stdio.h>
#include "solve_sq.h"
#include "title.h"
#include "equal_double.h"

int unit_tests()
{
    int warning = 0, num = 0;
    coeff sol{0, 0, 0, 0, 0, 0};

    for(double i = -5; i < 6; i++)
    {
        for(double j = -5; j < 6; j++)                                   // i = a, j = b, k = c
        {
            for(double k = -5; k < 6; k++)
            {
                sol = {i, j, k, 0, 0, 0};
                num = solve_sq(&sol);

                if(num == -1)
                    warning = !(equal_double(sol.a, 0) && equal_double(sol.b, 0) && equal_double(sol.c, 0)); // warning = ! (i == 0 && j == 0 && k == 0)

                if(num == 0)
                    warning = !((sol.b * sol.b) - (4 * sol.a * sol.c) <= 0);

                if(num == 1)
                    warning = !(equal_double(sol.a * sol.x1 * sol.x1 + sol.b * sol.x1 + sol.c, 0));

                if(num == 2)
                    warning = !(equal_double(sol.a * sol.x1 * sol.x1 + sol.b * sol.x1 + sol.c, 0) &&
                      equal_double(sol.a * sol.x2 * sol.x2 + sol.b * sol.x2 + sol.c, 0));


                if(warning == 1)
                printf("Error of %g %g %g test  7 %d %f\n", i, j, k, num, (sol.b * sol.b) - (4 * sol.a * sol.c)) ;
            }
        }
    }
    return 0;
}
