#include "title.h"
#include <stdio.h>
#include "iput.h"

static double readDouble();

void input(coeff* cf)
{
    printf("Please, write a, b, c of ax^2 +bx + c = 0\n");

    printf("a = ");
    cf->a = readDouble();

    printf("b = ");
    cf->b = readDouble();

    printf("c = ");
    cf->c = readDouble();
}


static double readDouble()
{
    double p = 0;

    while (scanf("%lg", &p) != 1)
    {
        while(getchar() != '\n')
            continue;

        printf("You are stupid idiot\nTry again: ");
    }

    while (getchar() != '\n')
        continue;

    return p;
}



void output(coeff* cf)
{
    if (cf->num == 2)
    {
        printf("Number of roots: %d\n", cf->num);
        printf("x1 = %lg\n", cf->x1);
        printf("x2 = %lg\n", cf->x2);
    }

    if (cf->num == 1)
    {
        printf("Number of roots: %d\n", cf->num);
        printf("x = %lg\n", cf->x1);
    }

    if (cf->num == 0)
    {
        printf("Number of roots: %d\n", cf->num);
    }

    if (cf->num == INF_ROOTS)
    {
        printf("Number of roots is infinitely\n");
    }
}
