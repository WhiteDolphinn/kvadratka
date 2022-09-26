#include "title.h"
#include "iput.h"
#include "sol_sq.h"

int main()
{

    coeff coef;
    input(&coef);
    coef.num = sol_sq(&coef);

    output(&coef);

    return 0;
}
