#include "Lab3_z5.h"
#include <stdio.h>
#include <stdlib.h>

// rekurencyjne implementacja silni
static long long silnia(int n)
{
    if(n == 1 || n == 0)
        return 1;
    else 
        return (long long)(n) * silnia(n-1);
}

void solveLab3Z5(void)
{
    int n = 0;
    printf("Program oblicza silnie rekurencyjnie. Podaj n: ");
    if(scanf("%d",&n) != 1)
    {
        fprintf(stderr, "Nie udało się odczytać liczby!\r\n");
        exit(1);
    }
    printf("n=%d, n!=%lld\r\n",n, silnia(n));
}

// int main(void)
// {
//     solveLab3Z5();
//     return 0;
// }