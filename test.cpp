#include <iostream>

using namespace std;

struct coeff {
    double a;
    double b;
    double c;
    double array[10000];
};

void printCoeff(coeff *cf);

int main()
{
    coeff cf = {1, 2, 1, {}};
    printCoeff(&cf);

    cout << cf.a << '\t' << cf.b << '\t' << cf.c << endl;

  //  cout << cf2.a << '\t' << cf2.b << '\t' << cf2.c << endl;

    return 0;
}

void printCoeff(coeff *cf)
{
    cout << (*cf).a << '\t' << (*cf).b << '\t' << (*cf).c << endl;
}
