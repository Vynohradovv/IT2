// Calculator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Math.h"

void usage(const char* program_name) {
    printf("\nHow to use: %s ", program_name);
    printf("\t<#numver1> <operation> <#number2>\n");
    printf("<operation> \n");
    printf("\t add or + \n");
    printf("\t sub or - \n");
    printf("\t mul or * \n");
    printf("\t div or / \n\n");
    printf("for example:\n");
    printf("\t 1 add 54\n");
    printf("\t 1.56 + 54\n\n");
    printf("code error \n");
    printf("\t -1 -> char in the argument\n");
    printf("\t -2 -> invalid argument format\n");
    exit(1);
}


int main(int argc, char* argv[])
{
    int i, count;
    int inumber1 = 0, inumber2 = 0;
    float fnumber1 = 0.0, fnumber2 = 0.0;

    int flag_flost = 0; 

    if (argc < 4) {
        usage("Calculator.exe");
    }
    
    flag_flost = intorfloat(argv[1]) + intorfloat(argv[3]);

    if (flag_flost >= 1) {
        fnumber1 = atof(argv[1]);
        fnumber2 = atof(argv[3]);
    }
    else if (flag_flost == 0) {
        inumber1 = atoi(argv[1]);
        inumber2 = atoi(argv[3]);
    }
    else {
        printf("Incorrect parameters, code %d\n", flag_flost);
        usage("Calculator.exe");
        exit(1);
    }
          

    tosmall(argv[2]);

    if (!strcmp(argv[2], "add") || !strcmp(argv[2], "+")) {     
        if (flag_flost) {
            print_result(fnumber1 + fnumber2);
            doPliku(argv, fnumber1 + fnumber2);
        }
        else {
            print_result(inumber1 + inumber2);
            doPliku(argv, (float)(inumber1 + inumber2));
        }
       
        exit(0);
    }

    if (!strcmp(argv[2], "sub") || !strcmp(argv[2], "-")) {
        if (flag_flost) {
            print_result((float)fnumber1 - fnumber2);
            doPliku(argv, fnumber1 - fnumber2);
        }
        else {
            print_result(inumber1 - inumber2);
            doPliku(argv, (float)(inumber1 - inumber2));
        }
        exit(0);
    }

    if (!strcmp(argv[2], "mul") || !strcmp(argv[2], "*")) {
        if (flag_flost) {
            print_result((float)fnumber1 * fnumber2);
            doPliku(argv, fnumber1 * fnumber2);
        }
        else {
            print_result(inumber1 * inumber2);
            doPliku(argv, (float)(inumber1 * inumber2));
        }
        exit(0);
    }

    if (!strcmp(argv[2], "div") || !strcmp(argv[2], "/")) {

        if ((inumber2 == 0) && (fnumber2 == 0)) {
            printf("must not divide by zero \n");
            exit(2);
        }

        if (flag_flost) {
            print_result(fnumber1 / fnumber2);
            doPliku(argv, fnumber1 / fnumber2);
        }
        else {
            print_result(inumber1 / inumber2);
            doPliku(argv, (float)(inumber1 / inumber2));
        }
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
