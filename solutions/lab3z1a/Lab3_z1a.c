#include "Lab3_z1a.h"
#include <ProjectConfig.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tag: górny zakres temperatury, którą może odczytać sensor 
#define SENSOR_MAX_TEMP_CELSIUS 100
// tag: dolny zakres temperatury, którą może odczytać sensor 
#define SENSOR_MIN_TEMP_CELSIUS 0

// ilość różnych identyfikatorów lokacji
#define LOCATION_ID_NUM 5

// ilość odczytów dopisywanych za jednym razem
#define NUM_READING 2

// tagi identyfikujące różne lokacje (w zapisie szesnastkowym)
#define LOCATION_ID_BATHROOM    (0xAA)
#define LOCATION_ID_BEDROOM_1   (0xBB)
#define LOCATION_ID_BEDROOM_2   (0xCC)
#define LOCATION_ID_LIVING_ROOM (0xDD)
#define LOCATION_ID_DINING_ROOM (0xEE)

// Stała (nieedytowalna) talica przechowująca różne lokacje
// proszę zauważyć, że przy deklaracji nie używam bezpośrednio
// literałów jak 5, 4, ale definicji, które coś oznaczają, w ten sposób 
// kod jest bardziej czytelny - jest to jedna z podstawowych dobrych praktyk
// w budowaniu złożonego kodu.
static const int location_ids[LOCATION_ID_NUM] =
{
    LOCATION_ID_BATHROOM,
    LOCATION_ID_BEDROOM_1,
    LOCATION_ID_BEDROOM_2,
    LOCATION_ID_LIVING_ROOM,
    LOCATION_ID_DINING_ROOM
};

static inline void initGenerator(void)
{
    // zainicjalizuj ziarno generatora liczb pseudolosowych
    srand(time(NULL));
}

static inline int generateRandomNum(int a, int b)
{
    // funkcja rand() zwraca liczbę z przedziału od 0 do RAND_MAX włącznie
    return random() % (b - a + 1) + a;
}

// definicja struktury użytkownika, używamy typedef, żeby potem unikać powtarzania słowa struct
// w kodzie, jest to kolejna dobra praktyka dla kodu C
typedef struct TempSensorData 
{
	int location;
	float temperature;
}TempSensorData_t;

// nasza funkcja udająca odczyt z sensora, funkcja przyjmuje jako argument wskaźnik do naszej
// customowej struktury
static void generateTemperatureReading(TempSensorData_t * sensor)
{
    // generujemy losowy indeks z przedziału 0 do LOCATION_ID_NUM-1, potem użyjemy go do wybrania
    // ID lokacji z tablicy location_ids
    // Pamiętaj, żę gdy używamy wskaźnika, to do pól struktury odnosimy się 
    // poprzez ->, w innym wypadku używamy kropki .
    int index = generateRandomNum(0, LOCATION_ID_NUM-1);
    sensor->location = location_ids[index];

    // generujemy losową temperaturę z przedziału dla sensora, znowu używamy tagów    
    int temp = generateRandomNum(SENSOR_MIN_TEMP_CELSIUS, SENSOR_MAX_TEMP_CELSIUS);

    sensor->temperature = temp;
}

// c-string przechowujący ścieżkę do pliku
static const char * file_path = TEST_DATA_ABS_PATH;

void solveLab3Z1a(void)
{
    // wskaźnik do struktury zawierającej dane o pliku (handle)
    FILE *fp;
    TempSensorData_t my_sensor_data;

    // twieramy plik do odczytu w trybie binarnym, możliwe tryby:
    // * "rb"   - tryb binarny do odczytu
    // * "rb+"  - tryb binarny od odczytu/zapisu
    // * "wb"   - tryb binarny do zapisu
    // * "ab"   - tryb binarny do nadpisywania
    // * "ab+"  - tryb binarny do nadpisywania i odczytu
    if ((fp=fopen(file_path, "ab")) == NULL)
    {
        // w przypadku zwrócenia NULL przez fopen
        printf("File not found!\r\n");
        exit(1);
    }

    // initialize pseudo-random generator
    initGenerator();

    for(int i =0; i<NUM_READING; i++)
    {
        // generujemy udawany odczyt
        generateTemperatureReading(&my_sensor_data);
        // zapisujemy udawany odczyt do pliku, sizeof zwraca wielkość struktury
        // TempSensorData_t w bajtach
        fwrite(&my_sensor_data, sizeof(TempSensorData_t), 1, fp);
    }

    fclose(fp);
}

// int main(void)
// {
//     solveLab3Z1a();
//     return 0;
// }