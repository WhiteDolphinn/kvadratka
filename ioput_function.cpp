#include "title.h"
#include <stdio.h>
#include <math.h>
#include "equal_double.h"
#include "ioput_function.h"
#include <assert.h>

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
    double p = 0, dnum2 = 0;
    long long num1 = 0, num2 = 0;

    while(scanf("%lld", &num1) != 1)
    {
        while(getchar() != '\n')
            continue;

        printf("You are stupid idiot\nTry again: ");
    }

    char ch = (char)getchar();
    int next_number = 0;


    switch(ch)
    {

        case'\n':
        {
            break;
        }

        case'.': case',':
        {
            while(scanf("%lld", &num2) != 1)
                break;

            dnum2 = (double)num2 / (pow(10, (int)log10(num2)+1));

                //break is absent!!!!!!!!!!!!!!
        }

        default:

            for (char ch2 = (char)getchar();  ch2 != '\n'; ch2 = (char)getchar())
            {
                switch(ch2)
                {
                    case '0':  case '1':  case '2': case '3':  case '4':  case '5':
                    case '6':  case '7':  case '8': case '9':
                    {
                        next_number = 1;
                    }
                    break;
                }
            }

            if(next_number == 1)
                printf("You wrote more than one number but read only the first\n");

            break;
       }

    p = num1 + dnum2;
    printf("Number, what read: %.*f \n\n", num2 ? (int)log10(num2)+1 : 0, p);
     return p;
}

void output(coeff* cf)
{
    assert(isfinite(cf->num));
    assert(isfinite(cf->x1));
    assert(isfinite(cf->x2));

    switch(cf->num)
    {
        case 2:
        {
            printf("Number of roots: %d\n", cf->num);
            printf("x1 = %lg\n", cf->x1);
            printf("x2 = %lg\n", cf->x2);
            break;
        }

        case 1:
        {
            printf("Number of roots: %d\n", cf->num);
            printf("x = %lg\n", cf->x1);
            break;
        }

        case 0:
        {
            printf("Number of roots: %d\n", cf->num);
            break;
        }

        case INF_ROOTS:
        {
            printf("Number of roots is infinitely\n");
            break;
        }
        default:
            printf("Unknown error\n");
    }
}
