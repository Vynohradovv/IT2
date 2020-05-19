// Calculator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Math.h"

using namespace std;

void usage(const char* program_name) {

    cout << "\nHow to use: %s " << program_name;
    cout << "\t<#numver1> <operation> <#number2>" << endl;
    cout << "<operation>" << endl;
    cout << "\t add or + " << endl;
    cout << "\t sub or -" << endl;
    cout << "\t mul or *" << endl;
    cout << "\t div or /\n" << endl;
    cout << "for example:" << endl;
    cout << "\t 1 add 54" << endl;
    cout << "\t 1.56 + 54\n" << endl;
    cout << "code error" << endl;
    cout << "\t -1 -> char in the argument" << endl;
    cout << "\t -2 -> invalid argument format" << endl;

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

        cout << "Incorrect parameters, code" << endl << flag_flost;
        
        usage("Calculator.exe");
        exit(1);
    }


    tosmall(argv[2]);

    if (!strcmp(argv[2], "add") || !strcmp(argv[2], "+")) {
        if (flag_flost) {
            print_result(fnumber1 + fnumber2);
        }
        else {
            print_result(inumber1 + inumber2);
        }
        exit(0);
    }

    if (!strcmp(argv[2], "sub") || !strcmp(argv[2], "-")) {
        if (flag_flost) {
            print_result((float)fnumber1 - fnumber2);
        }
        else {
            print_result(inumber1 - inumber2);
        }
        exit(0);
    }

    if (!strcmp(argv[2], "mul") || !strcmp(argv[2], "*")) {
        if (flag_flost) {
            print_result((float)fnumber1 * fnumber2);
        }
        else {
            print_result(inumber1 * inumber2);
        }
        exit(0);
    }

    if (!strcmp(argv[2], "div") || !strcmp(argv[2], "/")) {

        if ((inumber2 == 0) && (fnumber2 == 0)) {

            cout << "must not divide by zero" << endl;
          
            exit(2);
        }

        if (flag_flost) {
            print_result(fnumber1 / fnumber2);
        }
        else {
            print_result(inumber1 / inumber2);
        }
        exit(0);
    }

    cout << "unexpected error" << endl;
    
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
