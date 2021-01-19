#include "Lab3_z1.h"
#include <ProjectConfig.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// definicje MAKR związanych z obliczaniem f. kwadratowej  
#define DELTA(a,b,c) ((b)*(b)-(4.0*(a)*(c)))
#define X1(a,b,c) ((-(b) + sqrt(DELTA(a,b,c)))/(2 * (a)))
#define X2(a,b,c) ((-(b) - sqrt(DELTA(a,b,c)))/(2 * (a)))
#define X0(a,b) (-(b)/(2*(a)))

// c-string przechowujący ścieżkę do pliku
static const char * file_path = TEST_DATA_ABS_PATH;

// Definicja funkcji obliczającej pierwiastki f. kwadratowej
//
// Dodanie static przed wartością zwracaną w definicji funkcji w C powoduje, żę
// funkcja ta jest "widoczna" tylko w obrębie danego pliku i nie będzie konfliktu nazw
// w przypadku wystąpienia definicji identycznej funkcji w innym pliku. Ten trik został
// zastąpiony w C++ przez przestrzenie nazw.
static void solveQuadraticEquation(float a, float b, float c)
{
    float delta = DELTA(a, b, c); 
    if(delta < 0.0)
    {
        printf("Solution doesn't exist in R.\r\n");
    }
    else if (delta == 0.0)
    {
        printf("Doubled solution for x0=%f\r\n", X0(a,b));
    } 
    else
    {
        printf("Two solutions x1=%f i x2=%f\r\n", X1(a, b, c), X2(a, b, c));
    }    
}

void solveLab3Z1(void)
{
    // wskaźnik do struktury zawierającej dane o pliku (handle)
    FILE *fp;
    // współczynniki, które będziemy czytać z pliku
    float a, b, c;
    
    // otwieramy plik do odczytu w trybie tekstowym, możliwe tryby:
    // * "r"   - tryb tekstowy do odczytu
    // * "r+"  - tryb tekstowy od odczytu/zapisu
    // * "w"   - tryb tekstowy do zapisu
    // * "a"   - tryb tekstowy do nadpisywania
    // * "a+"  - tryb tekstowy do nadpisywania i odczytu
    if ((fp=fopen(file_path, "r")) == NULL)
    {
        // w przypadku zwrócenia NULL przez fopen
        printf("File not found!\r\n");
        exit(1);
    }

    // Każdorazowe użycie funkcji fscanf zszczytuje jedną linijkę pliku i przesuwa kursor
    // który wskazuje pozycję w pliku o jedną linijkę dalej. Jeżeli będziemy używać tej funkcji
    // w pętli, to w którymś momencie dojdziemy do końca pliku i funkcja zwróci EOF (end of file).
    while((fscanf(fp, "%f %f %f", &a, &b, &c) != EOF))
    {
        printf("From file: a=%.2f b=%.2f c=%.2f\r\n", a, b, c);
        // rozwiąż równanie dla danych z pliku
        solveQuadraticEquation(a, b, c);
    }

    // zamknij plik jak już skończyliśmy z nim pracę
    fclose(fp);
}

// int main(void)
// {
//     solveLab3Z1();
//     return 0;
// }
