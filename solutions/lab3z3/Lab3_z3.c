#include "Lab3_z3.h"
#include <ProjectConfig.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// określa maksymalną ilość danych jaką będzie można
// wczytać do tablicy z pliku
#define MAX_ARRAY_CAPACITY 100

// ścieżka do pliku
static const char * data_file_path = TEST_DATA_ABS_PATH;

// tablica typu int na dane z pliku
int data[MAX_ARRAY_CAPACITY];

// funkcja zwraca sumę elementów tablicy
static double sum(int * data, int length)
{
    double sum = 0;
    for(int i=0; i < length; i++)
        sum += (double)data[i];
    return sum;
}

// funkcja zwraca średnią arytmetyczną elementów tablicy
static double arithmetic_mean(int * data, int length)
{
    // wykorzystujemy funkcję sum()
    return (sum(data, length) / length);
}

// funkcja zwraca średnią geometryczną elementów tablicy
static double geometric_mean(int * data, int length)
{
    double base = 1.0;
    double power = (double)length;
    for(int i=0; i< length; i++)
        base *= (double)data[i];
    if(base > 0.0)
        // obliczamy pierwiastek k stopnia, gdzie k to długość talibcy
        return pow(base, 1.0/power);
    else
    {
        // bład gdy pod pierwiastkiem jest liczba ujemna
        fprintf(stderr, "geometric_mean: Base is negative!\r\n");
        exit(1);
    }
}

void solveLab3Z3(void)
{
    FILE *fp;
    int index = 0;

    // otwieramy plik w trybie tekstowym do odczytu
    if ((fp=fopen(data_file_path, "r")) == NULL)
    {
        printf("File not found!\r\n");
        exit(1);
    }

    // odczytujemy dane z pliku do póki nie osiągniemy końca pliku (EOF)
    // lub liczba danych nie osiągnie maksymalnej pojemności tablicy (MAX_ARRAY_CAPACITY)
    while(index < MAX_ARRAY_CAPACITY && (fscanf(fp, "%d", &data[index])) != EOF)
    {
        printf("read from file: dane[%d] = %d\r\n", index, data[index]);
        index++;
    }

    printf("data sum = %f\r\n", sum(data, index));
    printf("data arithmetic mean = %f\r\n", arithmetic_mean(data, index));
    printf("data geometric mean = %f\r\n", geometric_mean(data, index));

    fclose(fp);
}

// int main(void)
// {
//     solveLab3Z3();
//     return 0;
// }