#include "Lab4_z3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// struktura reprezentująca punk na płaszczyźnie
typedef struct Point_2D
{
    char symbol;
    double x;
    double y;
} Point_2D_t;

#define ARRAY_SIZE 4
#define POINT_A_INDEX 0
#define POINT_B_INDEX 1
#define POINT_C_INDEX 2
#define POINT_D_INDEX 3

// tablica punktów
const Point_2D_t points[] = {
    { .symbol = 'A', .x = 2.0, .y = 3.0 },
    { .symbol = 'B', .x = 4.0, .y = 5.0 },
    { .symbol = 'C', .x = -4.0, .y = 1.0 },
    { .symbol = 'D', .x = 2.0, .y = 2.0 }
};

// oblicz odległość między dwoma punktami
static void calculateDistance(const Point_2D_t *p1, const Point_2D_t *p2)
{
    double d1 = p2->x - p1->x;
    double d2 = p2->y - p2->y;
    double d = sqrt(d1*d1 + d2*d2);
    printf("|%c%c| = %lf\r\n", p1->symbol, p2->symbol, d);
}

// wypisz punkt
static inline void printPoint(const Point_2D_t * p)
{
    printf("%c = (%lf, %lf)\r\n", p->symbol, p->x, p->y);
}

void solveLab4Z3(void)
{
    for(int i=0;i<ARRAY_SIZE;i++)
        printPoint(&points[i]);

    // |AB|
    calculateDistance(&points[POINT_A_INDEX], &points[POINT_B_INDEX]);

    // |CD|
    calculateDistance(&points[POINT_C_INDEX], &points[POINT_D_INDEX]);
}

// int main()
// {
//     solveLab4Z3();
//     return 0;
// }