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
