#include "pch.h"
#include <iostream>

#pragma warning (disable : 4996)

//cikkszám, darab, ár/db
int termekek[5][3];

//vásárló globális változói
int kosar[5][2];
int kassza = 500;
int vegosszeg = 0;
int kosarIndex = 0;

void kosarNull() {
	//Kosár mátrix mezõinek feltöltése -1-gyel hibakezelés céljából
	kosar[0][0] = -1;
	kosar[1][0] = -1;
	kosar[2][0] = -1;
	kosar[3][0] = -1;
	kosar[4][0] = -1;

	kosar[0][1] = -1;
	kosar[1][1] = -1;
	kosar[2][1] = -1;
	kosar[3][1] = -1;
	kosar[4][1] = -1;
}

void feltoltes() {
	//1. feladat, a táblázat feltöltése

	//cikkszámok
	for (int i = 0; i < 5; i++)
		termekek[i][0] = 1000 + i;

	termekek[0][1] = 34;
	termekek[1][1] = 102;
	termekek[2][1] = 17;
	termekek[3][1] = 54;
	termekek[4][1] = 63;

	termekek[0][2] = 138;
	termekek[1][2] = 207;
	termekek[2][2] = 82;
	termekek[3][2] = 33;
	termekek[4][2] = 506;

	kosarNull();
}

void kirajzol() {
	printf("\ncikk\tdb\tár\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", termekek[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void kosarKirajzol() {
	printf("\ncikk\tdb\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d\t", kosar[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int charToInt(char c) {
	switch (c)
	{
	case '0': {
		return 0;
	}
	case '1': {
		return 1;
	}
	case '2': {
		return 2;
	}
	case '3': {
		return 3;
	}
	case '4': {
		return 4;
	}
	case '5': {
		return 5;
	}
	case '6': {
		return 6;
	}
	case '7': {
		return 7;
	}
	case '8': {
		return 8;
	}
	case '9': {
		return 9;
	}
	default:
		break;
	}
}

int bankkartyaEllenoriz(char szam[]) {
	int elsoNegy = 0;
	elsoNegy = charToInt(szam[0]) * 1000 + charToInt(szam[1]) * 100 + charToInt(szam[2]) * 10 + charToInt(szam[3]);
	//if (szam[4] != ' ' || szam[9] != ' ' || szam[14] != ' ') return 0;
	if (elsoNegy % 11 == 0) return 1;
	//scanf az elsõ 4 karaktert olvassa csak be a szóköz miatt
	//szóközök nélkül mûködik
	return 0;
}

int egyenleg() {
	if (kassza >= vegosszeg) {
		//Van elég pénze
		return 1;
	}
	else {
		//Nincs elég pénze
		return 0;
	}
}

void fizetes() {
	for (int i = 0; i < 5; i++)
	{
		int cikkszam = kosar[i][0];
		int darabszam = kosar[i][1];
		if (cikkszam != -1 && darabszam != -1) {
			for (int j = 0; j < 5; j++)
			{
				if (termekek[j][0] == cikkszam)
					vegosszeg += darabszam * termekek[j][2];
			}
		}
	}

	printf("A végösszeg: %d\n", vegosszeg);
}

char* bankkartyaBeker() {
	printf("Kérem a bankkártyaszámát: ");
	char kartyaszam[19];
	scanf("%s", kartyaszam);

	return kartyaszam;
}

void menu() {
	kirajzol();
	//1. vásárlás, 2. fizetés, 3. kilépés
	int valasz = -1;

	printf("\n1. Vásárlás\n2. Fizetés\n3. Kilépés\nVálasszon egy menüpontot: ");
	scanf(" %d", &valasz);

	if (valasz == 1) {
		//Vásárlás
		int valasztottCikkszam = -1;
		int valasztottDarabszam = -1;

		printf("Kérek egy cikkszámot: ");
		scanf(" %d", &valasztottCikkszam);

		if (valasztottCikkszam < 1000 || valasztottCikkszam > 1004) {
			system("CLS");
			if (valasztottCikkszam == 0)
				printf("Vásárlás vége!\n");
			else 
				printf("Nincs ilyen termék!\n");
			menu();
		}

		printf("Hány darabot szeretne?: ");
		scanf(" %d", &valasztottDarabszam);

		if (valasztottDarabszam == 0) {
			//A vásárlás véget ért...
		}
		else {					
			for (int i = 0; i < 5; i++)
			{
				if (termekek[i][0] == valasztottCikkszam) {
					if (valasztottDarabszam > termekek[i][1]) {
						//Nincs elég a raktárban
						system("CLS");
						printf("Nincs elég ebbõl a termékbõl a raktárban!\n");
						menu();
					}
					else {
						//Van elég termék a raktáron...
						if (kosarIndex < 5) {
							kosar[kosarIndex][0] = valasztottCikkszam;
							kosar[kosarIndex][1] = valasztottDarabszam;
							kosarIndex++;
							system("CLS");
							printf("A termék hozzáadva a kosárhoz!\n");
							termekek[i][1] -= valasztottDarabszam;						
							menu();
						}
						else {
							system("CLS");
							printf("Tele a kosár!\n");
							menu();
						}
					}
				}
			}
		}
	}
	else if (valasz == 2) {
		//Fizetés
		fizetes();
		if (vegosszeg > 0) {
			if (bankkartyaEllenoriz(bankkartyaBeker()) == 0) {
				//Érvénytelen kártyaszám, vissza a menübe
				system("CLS");
				printf("Érvénytelen a kártyaszám, a fizetést megtagadom! Próbálja újra!\n");
				menu();
			}
			else if (bankkartyaEllenoriz(bankkartyaBeker()) == 1) {
				//Érvényes kártyaszám
				if (egyenleg() == 1) {
					//Sikeres fizetés
					system("CLS");
					printf("Fizetés rendben!\n");
					vegosszeg = 0;
					kosarNull();
					menu();
				}
				else if (egyenleg() == 0) {
					//Sikertelen fizetés
					system("CLS");
					printf("Nincs elegendõ egyenlege, a fizetést megtagadom!\n");
					//A szóközök miatt sokszor kiírhatja a menüt hibás válasszal
					menu();
				}
			}
			else menu();
		}
		else {
			system("CLS");
			printf("Nem vásárolt semmit!\n");
			menu();
		}
	}
	else if (valasz == 3) {
		//Kilépés
		printf("Program vége!");
	}
	else{		
		printf("Hibás válasz (%d), újra!\n", valasz);
		menu();
	}
}

int main()
{
	setlocale(LC_ALL, "");
	feltoltes();
	//kirajzol();
	menu();
}