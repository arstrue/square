#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define  _CRT_SECURE_NO_WARNINGS

enum roots
{
    linear_func = 0,
    inf_numb_of_sol = 1,
    usual_square = 2,
};

int check(double a,double b, double c)
{
    if (0 == c && 0 == b && 0 == a)
    {
        return inf_numb_of_sol;
    }
    else if (0 == a)
    {
        return linear_func;
    }
    else
    {
        return usual_square;
    }
}

int sol(double a,double b, double c,double *x1,double *x2)
{
    double D = b*b - 4*a*c;

    if (D < 0){return 0;}

    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);
    return 1;
}

int main( )
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    scanf("%lg%lg%lg", &a, &b, &c);

    switch(check(a, b, c))
    {
        case linear_func: printf("x1 = %f", -c/b);
                break;
        case inf_numb_of_sol: printf("Any number is a solution.");
                break;
        case usual_square: if (sol(a, b, c, &x1, &x2))
                {
                    if (x1 == x2)
                    {
                        printf("x1 = x2 = %f", x1);
                    }
                    else
                    {
                        printf("x1 = %f   x2 = %f", x1, x2);
                    }
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
