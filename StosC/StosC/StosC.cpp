// StosC.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Stack.h"

#define SIZE_STACK      3

#define _FULL_          1
#define _EMPTY_         1
#define _NULL_          0

void menu(void) {
    printf("\n");
    printf("STOS - implementacja w tablicy[%d] dunamicznej\n", SIZE_STACK);
    printf("----------------------------------------------\n");
    printf("1 - poloz liczbe na stosie (Push)\n");
    printf("2 - odczytaj wartosc ze szczytu stosu (Top)\n");
    printf("3 - zdejmij liczbe ze stosu (Pop)\n");
    printf("4 - sprawdz czy stos jest pusty\n");
    printf("5 - sprawdz czy stos jest pelny\n");
    printf("k - koniec programu\n");
    printf("\n");

}

bool CheckStos(bool full, bool empty) {

    if ((full == _FULL_)&&(empty == _EMPTY_)) {

        return false;
    }

    if (full == _FULL_) {

        if (isStackFull() == true) {
            printf_s("Stos jest pelny !!!\n");
            return false;
        }
    }

    if (empty == _EMPTY_) {

        if (isStackEmpty() == true) {
            printf_s("Stos jest pusty !!!\n");
            return false;
        }
    }

    return true;
}


int main()
{
    int temp = 0;
    char opcja = 0;    

    if (StackInit(SIZE_STACK) == true) {

        while (opcja != 'k') {
            
            menu();
            opcja = _getch();
            system("cls");

            switch (opcja) {

            case '1':

                if (CheckStos(_FULL_, _NULL_) == true) {

                    printf_s("Podaj wartosc: ");
                    scanf_s("%d", &temp);
                    Push(temp);
                }

                break;

            case '2':

                if (CheckStos(_NULL_, _EMPTY_) == true) {

                    printf_s("Wartosc stosu %d: TOP()\n", Top());

                }

                break;

            case '3':

                if (CheckStos(_NULL_, _EMPTY_) == true) {

                    printf_s("Wartosc stosu %d POP()\n ", Pop());
                }

                break;

            case '4':

                if (CheckStos(_NULL_, _EMPTY_) == true) {

                    printf_s("Stos nie jest pusty \n");
                }

                break;

            case '5':

                if (CheckStos(_FULL_, _NULL_) == true) {

                    printf_s("Stos nie jest pelny \n");

                }
                break;

            default:
                break;


            }
        }

        StackDeinit();

        return 0;
    }
    else {
        
        printf("Nie udalo sie alokowac !!!\n");

        return 1;
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
