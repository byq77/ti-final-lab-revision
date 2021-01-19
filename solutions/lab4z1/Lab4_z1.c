#include "Lab4_z1.h"
#include <stdio.h>
#include <stdlib.h>
#include "ProjectConfig.h"

// tag identyfikujący opcję sortowania rosnącego
#define ASCENDING 0
// tag identyfikujący opcję sortowania malejącego
#define DESCENDING 1
// maksymalna pojemność tablicy
#define MAX_ARRAY_CAPACITY 100

// ścieżka do pliku z danymi
static const char * file_path = TEST_DATA_ABS_PATH;

// tablica do przechowywania danych z pliku
static int data_array[MAX_ARRAY_CAPACITY];

// tablica do pracy z danymi
static int work_array[MAX_ARRAY_CAPACITY];

// zamienia wartości elementów a <-> b
static inline void swap(int * a, int * b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

// implementacja bubble sort z możliwością wyboru sortowania rosnącego lub malejącego
static void bubble_sort(int * array, int lenght, int order)
{
    for(int i=0; i<lenght-1; i++)
    {
        for(int j=lenght-1; j>=i+1; j--)
        {
            switch(order)
            {
                case ASCENDING:
                    if(array[j] < array[j-1])
                        swap(array+j, array+j-1);
                    break;
                case DESCENDING:
                    if(array[j] > array[j-1])
                        swap(array+j, array+j-1);
                    break;
                default:
                    fprintf(stderr,"Wrong order!");
                    exit(1);
            }
        }
    }
}

// funkcja wypisująca elementy tablicy na ekran
static void printArray(int * a, int l)
{
    for(int i=0;i<l;i++)
        printf("array[%d]=%d\r\n", i, a[i]);
}

// funkcja tworząca kopię tablicy
static void copyArray(int *destination, const int *source, int l)
{
    for(int i=0;i<l;i++)
        *(destination+i) = *(source+i); 
}

void solveLab4Z1(void)
{
    FILE *fp;
    int i=0;
    int array_lenght;

    if ((fp=fopen(file_path, "r")) == NULL)
    {
        // w przypadku zwrócenia NULL przez fopen
        printf("File not found!\r\n");
        exit(1);
    }

    // wczytaj dane do tablicy
    while(i < MAX_ARRAY_CAPACITY && (fscanf(fp, "%d", &data_array[i]) != EOF))
    {
        i++;
    }
    array_lenght = i;

    // zamknij plik jak już skończyliśmy z nim pracę
    fclose(fp);

    // wypisujemy tablice
    printf("Tablica przed sortowaniem:\r\n");
    printArray(data_array, array_lenght);

    // kopiujemy tablice do testowania sortowania
    copyArray(work_array, data_array, array_lenght);

    // sortujemy rosnąco
    bubble_sort(work_array, array_lenght, ASCENDING);

    // wypisujemy posortowaną tablicę
    printf("Tablica po sortowaniu rosnącym:\r\n");
    printArray(work_array, array_lenght);

    // kopiujemy tablice do testowania sortowania
    copyArray(work_array, data_array, array_lenght);

    // sortujemy malejąco
    bubble_sort(work_array, array_lenght, DESCENDING);

    // wypisujemy posortowaną tablicę
    printf("Tablica po sortowaniu malejącym:\r\n");
    printArray(work_array, array_lenght);
}

// int main()
// {
//     solveLab4Z1();
//     return 0;
// }