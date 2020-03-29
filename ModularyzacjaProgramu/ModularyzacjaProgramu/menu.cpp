#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"funkcje_swap.h"

#define L_WIERSZY 4
#define L_KOLUMN  4

void wyswietl_dane(int tab[][L_KOLUMN]);

void _done(int tab[][L_KOLUMN]) {

	wyswietl_dane(tab);
	printf("\n Udalo ci sie!!!");
	printf("\t Nacisnij dowolny przycisk");
	_getch();
	system("cls");

}

void wprowadz_dane(int tab[][L_KOLUMN])
{
	for (int i = 0; i < L_WIERSZY; i++) {
		for (int x = 0; x < L_KOLUMN; x++) {
			wyswietl_dane(tab);
			printf("wprowadz dane [%d][%d] -> ", i, x);
			scanf("%d", &tab[i][x]);
			system("cls");
		}
	}

	_done(tab);
}

void swap_menu(int tab[][L_KOLUMN]) {
	int iKolumn1 = 0, iWierszy1 = 0;
	int iKolumn2 = 0, iWierszy2 = 0;

	wyswietl_dane(tab);
	printf_s("Wprowadz [WIERSZE] [KOLUMNE] pierwszego elementu - > ");
	scanf("%d", &iWierszy1);
	scanf("%d", &iKolumn1);
	printf_s("Wprowadz [WIERSZE] [KOLUMNE] drugego elementu - > ");
	scanf("%d", &iWierszy2);
	scanf("%d", &iKolumn2);
	swap_tab_wsk(&tab[iWierszy1 - 1][iKolumn1 - 1], &tab[iWierszy2 - 1][iKolumn2 - 1]);
	system("cls");
	_done(tab);
}
void wprowadz_dane_losowo(int tab[][L_KOLUMN])
{
	printf("Generacja danych losowych \n");
	printf("\n");

	for (int i = 0; i < L_WIERSZY; i++) {
		for (int x = 0; x < L_KOLUMN; x++) {
			tab[i][x] = rand() % 99;
		}
	}

	_done(tab);
}

void wyswietl_dane(int tab[][L_KOLUMN])
{
	int temp = 0;
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			printf_s("%4d", tab[wiersze][kolumny]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}

float srednia(int tab[][L_KOLUMN])
{
	int sum = 0, kol = 0;

	for (int i = 0; i < L_WIERSZY; i++) {
		for (int x = 0; x < L_KOLUMN; x++) {
			sum += tab[i][x];
			kol++;
		}
	}
	return (float)sum / kol;
}

float mediana(int tab[][L_KOLUMN], int tab_sort[])
{
	int count = 0;

	for (int i = 0; i < L_WIERSZY; i++) {
		for (int x = 0; x < L_KOLUMN; x++) {
			tab_sort[count++] = tab[i][x];
		}
	}


	for (int i = 0; i < count; i++)
	{
		for (int j = (count - 1); j > 0; j--)
		{
			if (tab_sort[j - 1] > tab_sort[j])
			{
				int temp = tab_sort[j - 1];
				tab_sort[j - 1] = tab_sort[j];
				tab_sort[j] = temp;
			}
		}
	}

	if (count % 2)
		return (float)tab_sort[count / 2];
	else
		return ((float)(tab_sort[(count - 1) / 2] + tab_sort[count / 2]) / 2);
}

void zapisz_dane(int tab[][L_KOLUMN])
{
	FILE* fp;
	char name[] = "out.txt";

	if ((fp = fopen(name, "w")) == NULL) {
		printf_s("Zapis nieudana!!!\n");
		return;
	}

	for (int i = 0; i < L_WIERSZY; i++) {
		for (int x = 0; x < L_KOLUMN; x++) {
			fprintf(fp, "%d ", tab[i][x]);
		}
		fprintf(fp, "%c", '\r');
	}

	fclose(fp);
	printf_s("Zapisano dane do pliku %s\n", name);
}

void wczytaj_dane(int tab[][L_KOLUMN])
{

	FILE* fp;
	char name[] = "out.txt";

	if ((fp = fopen(name, "r")) == NULL) {
		printf_s("Plik nie istnieje !!!\n");
		return;
	}

	for (int i = 0; i < L_WIERSZY; i++) {
		for (int x = 0; x < L_KOLUMN; x++) {
			fscanf(fp, "%d", &tab[i][x]);
		}
	}

	fclose(fp);
	printf_s("Odczytano dane z pliku %s\n", name);
}

void zamien_min_max(int tab[][L_KOLUMN])
{
	int _max[3] = { 0, 0, tab[0][0] };
	int _min[3] = { 0, 0, tab[0][0] };

	for (int i = 0; i < L_WIERSZY; i++) {
		for (int x = 0; x < L_KOLUMN; x++) {
			if (_max[2] < tab[i][x]) {
				_max[0] = i;
				_max[1] = x;
				_max[2] = tab[i][x];
			}

			if (_min[2] > tab[i][x]) {
				_min[0] = i;
				_min[1] = x;
				_min[2] = tab[i][x];
			}
		}
	}

	tab[_max[0]][_max[1]] = _min[2];
	tab[_min[0]][_min[1]] = _max[2];

	printf("Zmieniono wartosc minimalna i maksymalna \n\n");
	_done(tab);

}

void menu(void)
{
	printf_s("\n");
	printf_s("1 - wprowadz dane\n");
	printf_s("2 - wyswietl dane\n");
	printf_s("3 - oblicz srednia i mediane\n");
	printf_s("4 - zamien wartosc minimalna z maksymalna\n");
	printf_s("5 - generuj dane losowo\n");
	printf_s("6 - zamiana odpowiadajacych sobie elementow tablic\n");
	printf_s("z - zapisz dane do pliku\n");
	printf_s("w - wczytaj dane z pliku\n");
	printf_s("k - koniec programu\n");
	printf_s("\n");
}

void vMenuDemo(void)
{
	int tablica[L_WIERSZY][L_KOLUMN] = { 0 };
	int tab_sort_temp[L_WIERSZY * L_KOLUMN] = { 0 };
	char opcja = 0;

	while (opcja != 'k')
	{
		menu();
		opcja = _getch();

		switch (opcja)
		{
		case '1':
			system("cls");
			wprowadz_dane(tablica);
			break;

		case '2':
			system("cls");
			wyswietl_dane(tablica);
			break;

		case '3':
			system("cls");
			printf_s("Srednia wartosci znajdujacych sie w tabeli wynosi: %f\n", srednia(tablica));
			printf_s("Mediana wartosci znajdujacych sie w tabeli wynosi: %f\n", mediana(tablica, tab_sort_temp));
			break;

		case '4':
			system("cls");
			zamien_min_max(tablica);
			break;

		case '5':
			system("cls");
			wprowadz_dane_losowo(tablica);
			break;

		case '6':
			system("cls");
			swap_menu(tablica);
			break;

		case 'z':
			system("cls");
			zapisz_dane(tablica);
			break;

		case 'w':
			system("cls");
			wczytaj_dane(tablica);
			break;

		case 'k':
			//zakonczenie programu
			break;

		default:
			system("cls");
			printf_s("Wybierz wlasciwa opcje.\n\n");
			break;
		}
	}
	
}
