#include "title.h"
#include <stdio.h>
#include <math.h>
#include "equal_double.h"
#include "ioput_function.h"

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

   /* scanf("%d", &num1);

    switch(getchar())
    {
      case '.':
      case ',':
      scanf("%d", &num2);
      break;

      case '\n':

      return;

      case ' ':
      case '\t':
      break;

    }  */

    while (scanf("%lg", &p) != 1)
    {
        while(getchar() != '\n')
            continue;

        printf("You are stupid idiot\nTry again: ");
    }

    /* if(getchar() == ',')
        {
            double dp = 0; //чтение дробной части числа
            scanf("%lg", &dp);


            if(dp > 0)                             //чтобы не ввели 2,-4
            {
                dp = dp / (10 * (int)log10(dp));   //преобразуем dp в 0.dp

                p += dp;
            }
        } */

    int inputed_numbers = 1, next_number = 0, not_num_written = 0;
    char is_written_not_num[256]{};
    for (char ch = getchar();  ch != '\n'; ch = getchar())
    {
        switch(ch)
        {
            case ' ':
            {
                next_number = 1;
            }
                break;

            case '0':  case '1':  case '2': case '3':  case '4':  case '5':
            case '6':  case '7':  case '8': case '9':
            {
                if(next_number)
                {
                    next_number = 0;
                    inputed_numbers++;
                }
            }
                break;

           /* case ',':
            {
                double dp = 0; //чтение дробной части числа


                if(scanf("%lg", &dp) == 1)
                {


                    if(dp > 0 && equal_double(p, (int)(p)) == 1 )                             //чтобы не ввели 2,-4    1.23,3
                    {
                        dp = dp / (pow(10, ((int)log10((int)dp))+1));   //преобразуем dp в 0.dp
                        p += dp;
                    }
                }
                else
                {
                    while(getchar() != '\n')
                        continue;
                }



            }
                break;   */

            default:
            {
                is_written_not_num[ch] = 1;
                not_num_written = 1;
            }
                break;
        }
    }

    for (int i = 0; i < 256; i++)
    {
        if(is_written_not_num[i] == 1)
            printf("%c ", i);
    }

    if(not_num_written == 1)
    {
        printf(": is not numbers.\n");
        printf("You should read only ONE NUMBER\n");
    }

    if(inputed_numbers > 1)
        printf("You have written %d numbers, but read only ONE!!!\n", inputed_numbers);

        printf("Number, what read: %lg\n\n", p);

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
