#include "Lab3_z1b.h"
#include <ProjectConfig.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ilość różnych identyfikatorów lokacji
#define LOCATION_ID_NUM 5

// tagi identyfikujące różne lokacje (w zapisie szesnastkowym)
#define LOCATION_ID_BATHROOM    (0xAA)
#define LOCATION_ID_BEDROOM_1   (0xBB)
#define LOCATION_ID_BEDROOM_2   (0xCC)
#define LOCATION_ID_LIVING_ROOM (0xDD)
#define LOCATION_ID_DINING_ROOM (0xEE)
#define LOCATION_ID_TO_STR(id) #id

static const int location_ids[LOCATION_ID_NUM] =
{
    LOCATION_ID_BATHROOM,
    LOCATION_ID_BEDROOM_1,
    LOCATION_ID_BEDROOM_2,
    LOCATION_ID_LIVING_ROOM,
    LOCATION_ID_DINING_ROOM
};

// tablica c-stringów stworzonych z tagów za pomocą makra
// LOCATION_ID_TO_STR 
static const char * location_ids_str[LOCATION_ID_NUM] = 
{
    LOCATION_ID_TO_STR(LOCATION_ID_BATHROOM),
    LOCATION_ID_TO_STR(LOCATION_ID_BEDROOM_1),
    LOCATION_ID_TO_STR(LOCATION_ID_BEDROOM_2),
    LOCATION_ID_TO_STR(LOCATION_ID_LIVING_ROOM),
    LOCATION_ID_TO_STR(LOCATION_ID_DINING_ROOM)
};

typedef struct TempSensorData 
{
	int location;
	float temperature;
}TempSensorData_t;

// c-string przechowujący ścieżkę do pliku
static const char * file_path = TEST_DATA_ABS_PATH;

// kopnwertuje odczytaną wartość lokacji do jej nazwy
static const char * convertLocationIdToStr(int location_id)
{
    for(int i=0; i<LOCATION_ID_NUM; i++)
        if(location_id == location_ids[i])
            return location_ids_str[i];
    return "Wrong ID";
}

void solveLab3Z1b(void)
{
    // wskaźnik do struktury zawierającej dane o pliku (handle)
    FILE *fp;
    TempSensorData_t my_sensor_data;

    // otwórz plik w trybie binarnym
    if ((fp=fopen(file_path, "rb")) == NULL)
    {
        // w przypadku zwrócenia NULL przez fopen
        printf("File not found!\r\n");
        exit(1);
    }

    int i = 1;

    // czytaj dane do momentu dojścia do końca pliku
    while(!feof(fp))
    {
        // czytamy dane, jak funkcja zwraca ilość zczytanych danych
        // jeżeli nie ma już danych to funkcja zwróci zero, wtedy
        // wychodzimy z pętli
        if(fread(&my_sensor_data, sizeof(TempSensorData_t), 1, fp) == 0)
            break;
        // wypisz odczytane dane
        printf("Rekord %d: temp=%.2fC, loc=\"%s\"\r\n", 
                i++, 
                my_sensor_data.temperature, 
                convertLocationIdToStr(my_sensor_data.location));
    }

    fclose(fp);
}

// int main(void)
// {
//     solveLab3Z1b();
//     return 0;
// }