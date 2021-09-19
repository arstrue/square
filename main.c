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

#include "square.h"

enum roots
{
    linear_func = 0,
    inf_numb_of_sol = 1,
    usual_square = 2,
};

///Сравнивает даблы.
int comparing_double(double n, double m)
{
    return fabs(n - m) < epsilon;
}

///Проверяет сколько у уравнения предполагаемых корней.
int check(double a,double b, double c)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    if (comparing_double(0, c) && comparing_double(0, b) && comparing_double(0, a))
    {
        return inf_numb_of_sol;//Бесконечное количество корней.
    }
    else if (comparing_double(0, a))
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
    assert(x1);
    assert(x2);
    assert(x1 != x2);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    double D = b*b - 4*a*c;

    if (D < 0){return 0;}

    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);

    return 1;
}

///Принимает с консоли три коэффицинта, проверяет, что это числа.
void get_coef(double *a, double *b, double *c, int  i)
{
    assert(a);
    assert(b);
    assert(c);

    printf("Please enter the coefficients of the equation number %d.\n", i);

    if (3 != scanf("%lg%lg%lg", a, b, c))//Срабатывает, когда введено не число.
    {
        printf("Input error, please try again.\n");
        while(fgetc(stdin) != '\n')//Просит ввести, пока не будут введены три числа.
        {
            getchar();
            if (3 != scanf("%lg%lg%lg", a, b, c))
            {
                printf("Input error, please try again.\n");
            }
        }
    }
}

struct coef_for_tests
{
    double a, b, c,x1, x2, x_1, x_2;//x_1 и x_2 переменные для сравнения после вычислений.
};

///Проверяет несколько частных случаев решений квадратных уравнений.
void Test_for_solving()
{
    struct coef_for_tests one = {1,2,1,0,0, -1,-1};
    struct coef_for_tests two = {5,-7,2,0,0, 1,0.4};
    struct coef_for_tests three = {1,4,2.5,0,0, -0.775255129,-3.22474487};
    struct coef_for_tests list[3] = {one, two, three};

    for (int i = 0; i < 3; ++i)
    {
        solving(list[i].a, list[i].b, list[i].c, &list[i].x1, &list[i].x2);
        assert(comparing_double(list[i].x1, list[i].x_1) && comparing_double(list[i].x2, list[i].x_2));
    }
}

void get_numb(int *n)
{
    if (!scanf("%d", n))//Срабатывает, когда введено не число.
    {
        printf("Input error, please try again.\n");
        while(fgetc(stdin) != '\n')//Просит ввести, пока не будут введены три числа.
        {
            getchar();
            if (!scanf("%d", n))
            {
                printf("Input error, please try again.\n");
            }
        }
    }
}

int main()
{
    Test_for_solving();

    int n = 0;
    printf("Hi, how many equations are you going to solve?\n");
    get_numb(&n);
    double *p;
    p = (double *) calloc(n, sizeof(double) * 3);
    assert(p);

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    for (int i = 0; i < n; ++i)
    {
        get_coef(&a, &b, &c, i);
        a_ = a;
        b_ = b;
        c_ = c;
    }

    for (int i = 0; i < n; ++i)
    {
        switch (check(a_, b_, c_))
        {
            case linear_func:
                printf("x1 = %lg\n", -c_ / b_);
                break;
            case inf_numb_of_sol:
                printf("Equation number %d: Any number is a solution.\n", i);
                break;
            case usual_square:
                if (solving(a_, b_, c_, &x1, &x2))
                {
                    if (comparing_double(x1, x2))
                    {
                        printf("Equation number %d: x1 = x2 = %lg\n", i, x1);
                    } else
                    {
                        printf("Equation number %d: x1 = %lg   x2 = %lg\n", i, x1, x2);
                    }
                } else
                {
                    printf("Equation number %d: There are no real solutions.\n", i);
                }
                break;
        }
    }
    free(p);
    return 0;
}
