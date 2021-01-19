#include "Lab4_z4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// tag reprezentujący punkt znajdujący się wewnątrz okręgu
#define INSIDE 1
// tag reprezentujący punkt znajdujący się na okręgu
#define EDGE 2
// tag reprezentujący punkt znajdujący się poza okregiem
#define OUTSIDE 3

// struktura reprezentująca punk na płaszczyźnie
typedef struct Point_2D
{
    char symbol;
    double x;
    double y;
} Point_2D_t;

// struktura reprezentująca okrąg na płaszczyźnie
typedef struct Circle_2Ds
{
    Point_2D_t center;
    double radius;
} Circle_2D_t;

// wypisz punkt
static inline void printPoint(const Point_2D_t * p)
{
    printf("%c = (%lf, %lf)\r\n", p->symbol, p->x, p->y);
}

// oblicz odległość między dwoma punktami
static double calculateDistance(const Point_2D_t *p1, const Point_2D_t *p2)
{
    double d1 = p2->x - p1->x;
    double d2 = p2->y - p2->y;
    double d = sqrt(d1*d1 + d2*d2);
    // printf("|%c%c| = %lf\r\n", p1->symbol, p2->symbol, d);
    return d;
}

// funkcja sprawdza położenie punktu względem środka okręgu
static int checkRelativePosition(const Circle_2D_t *c, const Point_2D_t *p)
{
    double d = calculateDistance(&c->center, p);
    // wewnątrz okręgu
    if(d < c->radius)
        return INSIDE;
    // na okręgu
    else if(d == c->radius)
        return EDGE;
    // na zewnątrz okręgu
    else 
        return OUTSIDE;
}

void solveLab4Z4(void)
{
    Point_2D_t p = {.symbol='T',};
    Circle_2D_t c;
    printf("Podaj wspolrzedne x i y srodka okregu oraz jego promien: ");
    if(scanf("%lf %lf %lf", &c.center.x, &c.center.y, &c.radius) != 3)
    {
        fprintf(stderr, "Niepoprawne dane wejsciowe!\r\n");
        exit(1);
    }
    printf("Podaj wspolrzedne x i y punktu: ");
    if(scanf("%lf %lf", &p.x, &p.y) != 2)
    {
        fprintf(stderr, "Niepoprawne dane wejsciowe!\r\n");
        exit(1);
    }
    
    switch(checkRelativePosition(&c, &p))
    {
        case INSIDE:
            printf("Punkt znajduje sie wewnatrz okregu.\r\n");
            break;
        case OUTSIDE:
            printf("Punkt znajduje sie nazewnatrz okregu.\r\n");
            break;
        case EDGE:
            printf("Punkt znajduje sie na okregu.\r\n");
            break;
        default:
            break;
    }
}

// int main()
// {
//     solveLab4Z4();
//     return 0;
// }