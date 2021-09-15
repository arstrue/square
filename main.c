/*!
    \file
    This program solves square equations.
    \param [in] (a) senior coefficient
    \param [in] (b) coefficient at x
    \param [in] (c) free coefficient
    \param [out] (x1) first root
    \param [out] (x2) second root

    \return {roots of equation}

    \note
          1. In case of a = b = c = 0 returns "Any number is a solution."
          2. In case of a = 0 returns root of a linear equation.
          3. In case of complex roots returns "There are no real solutions."
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#define  _CRT_SECURE_NO_WARNINGS
#define epsilon 1e-7///<const for comparing double

enum roots
{
    linear_func = 0,
    inf_numb_of_sol = 1,
    usual_square = 2,
};

///Проверяет сколько у уравнения предполагаемых корней.
int check(double a,double b, double c)
{
    if (0 == c && 0 == b && 0 == a)
    {
        return inf_numb_of_sol;//Бесконечное количество корней.
    }
    else if (0 == a)
    {
        return linear_func;//Один корень.
    }
    else
    {
        return usual_square;//До двух корней.
    }
}

///Решает квадратное уравнение.
int solving(double a, double b, double c, double *x1, double *x2)
{
    double D = b*b - 4*a*c;

    if (D < 0){return 0;}

    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);
    return 1;
}

///Принимает с консоли три коэффицинта, проверяет, что это числа.
int get_coef(double *a, double *b, double *c)
{
    if (3 != scanf("%lg%lg%lg", a, b, c))//Срабатывает, когда введено не число.
    {
        printf("Input error, please try again.\n");
        while(fgetc(stdin) != '\n')//Просит ввести, пока не будут введены три числа.
        {
            if (3 != scanf("%lg%lg%lg", a, b, c))
            {
                printf("Input error, please try again.\n");
            }
        }
    }
    return 0;
}

///Проверяет несколько частных случаев решений квадратных уравнений.
void Test_for_solving()
{
    double a = 1, b = 2, c = 1,x1 = 0,x2 = 0;
    solving(a,b,c,&x1,&x2);
    assert(x1 - (-1) < epsilon && x2 - (-1) < epsilon);//Ожидаемый корень -1.

    a = 5, b = 7, c = 2,x1 = 0,x2 = 0;
    solving(a,b,c,&x1,&x2);
    assert(x1 - (-0.4) < epsilon && x2 - (-1) < epsilon);//Ожидаемые корни -1 и -0,4.

    a = 5, b = -9, c = 3,x1 = 0,x2 = 0;
    solving(a,b,c,&x1,&x2);
    assert((fabs(x1 - 1.35825757) < epsilon) && (fabs(x2 - 0.441742431) < epsilon));
    //Ожидаемые корни 1.35825757 и 0.441742431.
}

///Несколько частных случаев для предполагаемого количества корней.
 void Tests_for_check()
 {
    assert(check(0,1,1) == linear_func);

    assert(check(0,0,0) == inf_numb_of_sol);

    assert(check(1,2,1) == usual_square);
 }

int main()
{
    Test_for_solving();
    Tests_for_check();

    double a = 0, b = 0, c = 0,x1 = 0,x2 = 0;
    get_coef(&a, &b, &c);

    switch(check(a, b, c))
    {
        case linear_func: printf("x1 = %f\n", -c/b);
                break;
        case inf_numb_of_sol: printf("Any number is a solution.\n");
                break;
        case usual_square: if (solving(a, b, c, &x1, &x2))
                           {
                                if (fabs(x1 - x2) < epsilon)
                                {
                                    printf("x1 = x2 = %lg\n", x1);
                                }
                                else
                                {
                                    printf("x1 = %lg   x2 = %lg\n", x1, x2);
                                }
                           }
                           else
                           {
                               printf("There are no real solutions.\n");
                           }
                           break;
    }
    return 0;
}
