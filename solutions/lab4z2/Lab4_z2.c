#include "Lab4_z2.h"
#include <stdio.h>
#include <stdlib.h>

// wartości zwracane przez funkcję formula_parser()
#define FORMULA_PARSE_SUCCESS 0
#define FORMULA_PARSE_FAILURE 1

// funkcja parsujące wejście
// @return result wskaźnik do zmiennej przechowującej wynik
// działania formuły matematycznej
// 
// Obsługiwane działania:
// a+b
// a-b
// ab
// a/b
static int formula_parser(double *result)
{
    double a, b;
    char c;

    // wczytaj z klawiatury
    if(scanf("%lf%c%lf", &a,&c,&b) != 3)
    {
        // niepoprawne wejście
        return FORMULA_PARSE_FAILURE;
    }
    else
    {
        // jeżeli wyrażenie jest poprawne to oblicz wynik w 
        // zależności od typu działania
        switch(c)
        {
            case '+':
                *result = a + b;
                return FORMULA_PARSE_SUCCESS;
            case '-':
                *result = a - b;
                return FORMULA_PARSE_SUCCESS;
            case '*':
                *result = a * b;
                return FORMULA_PARSE_SUCCESS;
            case '/':
                *result = a / b;
                return FORMULA_PARSE_SUCCESS;
            default:
                return FORMULA_PARSE_FAILURE;
        }
    }
}

void solveLab4Z2(void)
{
    double result;
    char answer;
    do
    {
        printf("Podaj wyrażenie: ");
        if(formula_parser(&result) == FORMULA_PARSE_FAILURE)
        {
            printf("Niepoprawne dane wejściowe!\r\n");
        }
        else
        {
            printf("= %f\r\n", result);
        }
        printf("Licz jeszcze raz? (T/N): ");
        while ((getchar()) != '\n'); // clear stdin buffer
        answer = getchar(); 
    } while (answer == 'T' || answer == 't');
}

// int main()
// {
//     solveLab4Z2();
//     return 0;
// }