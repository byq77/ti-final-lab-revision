#include "Lab3_z4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// funkcja generująca losową liczbę całkowitą z przedziału <l_min,l_max>
static int losowanie(int l_min, int l_max)
{
    srand(time(NULL));
    return rand() % (l_max - l_min+1) + l_min;
}

// funkcja mimikująca wyszukiwanie binarne
// wyszukiwanie binarne stosuje się w poszukiwaniu indeksu
// elementu w zbiorach posortowanych (rosnąco, malejąco)
static int pseudo_binary_search(int l_min, int l_max, int num)
{
    int step = 1;
    int guess; 

    do{
        // znajdujemy czy szukany element jest w środku zbioru
        guess = floor((l_min + l_max )/ 2.0);

        printf("Krok %d: Zgaduje libcze: %d\r\n", step, guess);
        if(num > guess)
        {
            l_min = guess;
        }
        else
        {
            l_max = guess;
        }

    // powtarzamy dopóki nie natrafimy na szukany element
    }while(guess != num);

    return guess;
}

void solveLab3Z4(void)
{
    int range_max, range_min, random_num;
    printf("Podaj zakres losowanej liczby (MIN MAX): ");
    if(scanf("%d %d", &range_min, &range_max) != 2)
    {
        fprintf(stderr, "Nie udało się pobrać zakresu!\r\n");
        exit(1);
    }
    random_num = losowanie(range_min, range_max);
    printf("Wylosowana liczba z zakresu %d-%d: %d\r\n", range_min, range_max, random_num);
    printf("Znaleziono liczbe! Poszukiwana liczba to: %d\r\n", pseudo_binary_search(range_min, range_max, random_num));
}

// int main(void)
// {
//     solveLab3Z4();
//     return 0;
// }