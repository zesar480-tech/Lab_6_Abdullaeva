/*
* Вариант 2:
Написать программу, которая переводит время из секунд в целое значение часов, минут и секунд. Если значение часов равно 0, то слово «час» не выводится.
* 
* 
* 
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int get_hours(int total);
int get_minutes(int total);
int get_seconds(int total);
int word_form(int n);

int main()
{
    int total;
    int h, m, s;
    int fh, fm, fs;

    setlocale(LC_ALL, "Russian");
    printf("\nДомашнее задание\n");

    printf("Введите время в секундах: ");
    if (scanf("%d", &total) != 1 || total < 0)
    {
        printf("Ошибка: нужно ввести целое неотрицательное число.\n");
        return 1;
    }

    h = get_hours(total);
    m = get_minutes(total);
    s = get_seconds(total);

    fh = word_form(h);
    fm = word_form(m);
    fs = word_form(s);

    printf("%d сек = ", total);
    if (h != 0)
        printf("%d %s ", h, fh == 1 ? "час" : (fh == 2 ? "часа" : "часов"));
    printf("%d %s %d %s\n",
        m, fm == 1 ? "минута" : (fm == 2 ? "минуты" : "минут"),
        s, fs == 1 ? "секунда" : (fs == 2 ? "секунды" : "секунд"));

    return 0;
}

int get_hours(int total)
{
    int h;
    h = total / 3600;
    return h;
}

int get_minutes(int total)
{
    int m;
    m = (total % 3600) / 60;
    return m;
}

int get_seconds(int total)
{
    int s;
    s = total % 60;
    return s;
}

/* Форма слова после числа n: 1 — «час», 2 — «часа», 5 — «часов» */
int word_form(int n)
{
    int n100, n10, form;
    n100 = n % 100;
    n10 = n % 10;
    if (n100 >= 11 && n100 <= 14)
        form = 5;
    else if (n10 == 1)
        form = 1;
    else if (n10 >= 2 && n10 <= 4)
        form = 2;
    else
        form = 5;
    return form;
}