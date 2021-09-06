#include <stdio.h>
#include <math.h>
#define  _CRT_SECURE_NO_WARNINGS

int check(double a,double b, double c)
{
    if (0 == c && 0 == b && 0 == a)
    {
        return 1;
    }
    else if (0 == a)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

double x1 = 0, x2 = 0;
int sol(double a,double b, double c)
{
    double D = b*b - 4*a*c;

    if (D < 0){return 0;}

    x1 = (-b + sqrt(D))/(2*a);
    x2 = (-b - sqrt(D))/(2*a);
    return 1;
}

int main( )
{
    double a = 0, b = 0, c = 0;
    scanf("%lg%lg%lg", &a, &b, &c);

    switch(check(a, b, c))//0: linear func; 1: inf numb of solutions; 2: usual square
    {
        case 0: printf("x1 = %f", -c/b);
                break;
        case 1: printf("Any number is a solution.");
                break;
        case 2: if (sol(a, b, c))
                {
                    printf("x1 = %f   x2 = %f", x1, x2);
                    break;
                }
                else
                {
                    printf("There are no real solutions.");
                }
                break;
    }
    return 0;
}
