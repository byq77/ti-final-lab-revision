#include "Lab3_z2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// ten plik nagłówkowy zawiera definicje wartości maksymalnych i minimalnych dla różnych typów
#include <limits.h>

// ścieżka do pliku (system Linux)
const char * data_file_path = "/home/byq77/workspace/c-workspace/ti-final-lab-revision/solutions/lab3z2/dane.txt";

// definicje funkcji inline zwracających maksimum lub minimum
static inline int imin(int a, int b) { return (a > b ? b : a); }
static inline int imax(int a, int b) { return (a > b ? a : b); }

void solveLab3Z2(void)
{
    // wskaźnik do struktury zawierającej dane o pliku (handle)
    FILE *fp;

    // wstępnie inicjalizujemy zmienne wartościami maksymalnymi i miniamlnymi dla int
    int min_num = INT_MAX; 
    int max_num = INT_MIN;
    int current_num;

    // open file in text mode to read
    if ((fp=fopen(data_file_path, "r")) == NULL)
    {
        printf("File not found!\r\n");
        exit(1);
    }

    // iterujemy przez plik w poszukiwaniu wartości max i min
    while((fscanf(fp, "%d", &current_num)) != EOF)
    {
        min_num = imin(min_num, current_num);
        max_num = imax(max_num, current_num);
    }

    printf("max num = %d, min num = %d\r\n", max_num, min_num );

    fclose(fp);

}

// int main(void)
// {
//     solveLab3Z2();
//     return 0;
// }