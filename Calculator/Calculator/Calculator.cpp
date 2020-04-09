// Calculator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>

void usage(const char* program_name) {
    printf("How to use: %s <#numver1> <operation> <#number2>/n", program_name);
    exit(1);
}

int main(int argc, char const* argv[])
{
    int i, count;
    int number1 = 0, number2 = 0, result = 0;

    if (argc < 3) {
        usage(argv[0]);
    }

    number1 = atoi(argv[1]);
    number2 = atoi(argv[3]);

    if (!strcmp(argv[2], "add")) {
        result = number1 + number2;
        printf("result: %d \n", result);
        exit(0);
    }

    if (!strcmp(argv[2], "sub")) {
        result = number1 - number2;
        printf("result: %d \n", result);
        exit(0);
    }

    if (!strcmp(argv[2], "mul")) {
        result = number1 * number2;
        printf("result: %d \n", result);
        exit(0);
    }

    if (!strcmp(argv[2], "div")) {

        if (number2 == 0) {
            printf("must not divide by zero \n");
            exit(2);
        }
        result = number1 / number2;
        printf("result: %d \n", result);
        exit(0);
    }

    printf("unexpected error \n");
    exit(3);
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
