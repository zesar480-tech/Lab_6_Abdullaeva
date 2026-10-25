/*
 *          | x^2 - 3x + 9,   при x <= 3
 *   F(x) = |
 *          | 1 / (x^3 + 6),  при x > 3
 *
 * Контрольные примеры:
 * Ветвь x <= 3:
 * x = 1 -> 1 - 3 + 9  = 7
 * x = -1  -> 1 + 3 + 9  = 13
 * x = 3  -> 9 - 9 + 9  = 9
 * (граница, входит в первую ветвь)
 *
 * Ветвь x > 3:
 * x = 10 -> 1 / (1000 + 6)  = 1/1006 = 0.000994   
 * x = 4    -> 1 / (64 + 6) = 1/70  = 0.014286
 * x = 5    -> 1 / (125 + 6)= 1/131 = 0.007634
 *
 * Знаменатель x^3 + 6 обращается в 0 только при x ≈ -1.817,
 * а вторая ветвь работает при x > 3, поэтому деления на ноль нет.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

    double f(double x);

int main()
{
    double x;
    double result;

    setlocale(LC_ALL, "Russian");
    printf("/n ===== Задание 2 ===== /n");
    printf("Введите x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Ошибка: нужно ввести число.\n");
        return 1;
    }

    result = f(x);

    printf("/n Вывод с использованием тернарной операции в printf: /n");
    printf("F(%g) = %.6f, использована формула %s\n",
        x, result,
        (x <= 3) ? "x^2 - 3x + 9 (x <= 3)" : "1/(x^3 + 6) (x > 3)");

    return 0;
}

double f(double x)
{
    double y;
    if (x <= 3)
        y = x * x - 3 * x + 9;
    else
        y = 1.0 / (x * x * x + 6);
    return y;
}