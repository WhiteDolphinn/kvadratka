#include "title.h"
#include "intoutput.h"
#include "sol_sq.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int num = 0;

    input(&a, &b, &c);


    num = sol_sq(a, b, c, &x1, &x2);

    output(x1, x2, num);

    return 0;
}
