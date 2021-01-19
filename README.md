# ti-final-lab-revision

## Wymagane rozszerzenia VSC
* https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
* https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools

## Jak zbudować rozwiązanie zadania

W root `CMakeLists.txt` odblokuj przykład, który chcesz zbudować używając dostępnych opcji (jednocześnie może być odblokowany tylko jeden):
```cmake
option(LAB3_ZAD1_SOLUTION "Build solution for zad1 from lab3" ON)
option(LAB3_ZAD1A_SOLUTION "Build solution for zad1a" OFF)
option(LAB3_ZAD1B_SOLUTION "Build solution for zad1b" OFF)
option(LAB3_ZAD2_SOLUTION "Build solution for zad2 from lab3" OFF)
option(LAB3_ZAD3_SOLUTION "Build solution for zad3 from lab3" OFF)
option(LAB3_ZAD4_SOLUTION "Build solution for zad4 from lab3" OFF)
option(LAB3_ZAD5_SOLUTION "Build solution for zad5 from lab3" OFF)
option(LAB4_ZAD1_SOLUTION "Build solution for zad1 from lab4" OFF)
option(LAB4_ZAD2_SOLUTION "Build solution for zad2 from lab4" OFF)
option(LAB4_ZAD3_SOLUTION "Build solution for zad3 from lab4" OFF)
option(LAB4_ZAD4_SOLUTION "Build solution for zad4 from lab4" OFF)
```

## Evernote
Notatka "Trochę o C na ostatnie labki": https://tinyurl.com/y6fb4vr6