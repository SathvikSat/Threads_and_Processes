#include <stdio.h>
#include "Process1.h"

void do_one_thing(int *pnum_times)
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        printf("do one thing\n");
        for (j = 0; j < 2; j++)
            x = x + i;
        (*pnum_times)++;
    }
}

void do_another_thing(int *pnum_times)
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        printf("do another\n");
        for (j = 0; j < 2; j++)
            x = x + i;
        (*pnum_times)++;
    }
}

void do_wrap_it_up(int one_times, int another_times)
{

    int total;

    total = one_times + another_times;
    printf("wrap up: one thing %d, another %d, total %d\n", one_times, another_times, total);
}
