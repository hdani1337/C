#include "pch.h"
#include <iostream>

#pragma warning (disable : 4996)

//cikksz�m, darab, �r/db
int termekek[5][3];

//v�s�rl� glob�lis v�ltoz�i
int kosar[5][2];
int kassza = 500;
int vegosszeg = 0;
int kosarIndex = 0;

void kosarNull() {
	//Kos�r m�trix mez�inek felt�lt�se -1-gyel hibakezel�s c�lj�b�l
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
	//1. feladat, a t�bl�zat felt�lt�se

	//cikksz�mok
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
	printf("\ncikk\tdb\t�r\n");
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
	//scanf az els� 4 karaktert olvassa csak be a sz�k�z miatt
	//sz�k�z�k n�lk�l m�k�dik
	return 0;
}

int egyenleg() {
	if (kassza >= vegosszeg) {
		//Van el�g p�nze
		return 1;
	}
	else {
		//Nincs el�g p�nze
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

	printf("A v�g�sszeg: %d\n", vegosszeg);
}

char* bankkartyaBeker() {
	printf("K�rem a bankk�rtyasz�m�t: ");
	char kartyaszam[19];
	scanf("%s", kartyaszam);

	return kartyaszam;
}

void menu() {
	kirajzol();
	//1. v�s�rl�s, 2. fizet�s, 3. kil�p�s
	int valasz = -1;

	printf("\n1. V�s�rl�s\n2. Fizet�s\n3. Kil�p�s\nV�lasszon egy men�pontot: ");
	scanf(" %d", &valasz);

	if (valasz == 1) {
		//V�s�rl�s
		int valasztottCikkszam = -1;
		int valasztottDarabszam = -1;

		printf("K�rek egy cikksz�mot: ");
		scanf(" %d", &valasztottCikkszam);

		if (valasztottCikkszam < 1000 || valasztottCikkszam > 1004) {
			system("CLS");
			if (valasztottCikkszam == 0)
				printf("V�s�rl�s v�ge!\n");
			else 
				printf("Nincs ilyen term�k!\n");
			menu();
		}

		printf("H�ny darabot szeretne?: ");
		scanf(" %d", &valasztottDarabszam);

		if (valasztottDarabszam == 0) {
			//A v�s�rl�s v�get �rt...
		}
		else {					
			for (int i = 0; i < 5; i++)
			{
				if (termekek[i][0] == valasztottCikkszam) {
					if (valasztottDarabszam > termekek[i][1]) {
						//Nincs el�g a rakt�rban
						system("CLS");
						printf("Nincs el�g ebb�l a term�kb�l a rakt�rban!\n");
						menu();
					}
					else {
						//Van el�g term�k a rakt�ron...
						if (kosarIndex < 5) {
							kosar[kosarIndex][0] = valasztottCikkszam;
							kosar[kosarIndex][1] = valasztottDarabszam;
							kosarIndex++;
							system("CLS");
							printf("A term�k hozz�adva a kos�rhoz!\n");
							termekek[i][1] -= valasztottDarabszam;						
							menu();
						}
						else {
							system("CLS");
							printf("Tele a kos�r!\n");
							menu();
						}
					}
				}
			}
		}
	}
	else if (valasz == 2) {
		//Fizet�s
		fizetes();
		if (vegosszeg > 0) {
			if (bankkartyaEllenoriz(bankkartyaBeker()) == 0) {
				//�rv�nytelen k�rtyasz�m, vissza a men�be
				system("CLS");
				printf("�rv�nytelen a k�rtyasz�m, a fizet�st megtagadom! Pr�b�lja �jra!\n");
				menu();
			}
			else if (bankkartyaEllenoriz(bankkartyaBeker()) == 1) {
				//�rv�nyes k�rtyasz�m
				if (egyenleg() == 1) {
					//Sikeres fizet�s
					system("CLS");
					printf("Fizet�s rendben!\n");
					vegosszeg = 0;
					kosarNull();
					menu();
				}
				else if (egyenleg() == 0) {
					//Sikertelen fizet�s
					system("CLS");
					printf("Nincs elegend� egyenlege, a fizet�st megtagadom!\n");
					//A sz�k�z�k miatt sokszor ki�rhatja a men�t hib�s v�lasszal
					menu();
				}
			}
			else menu();
		}
		else {
			system("CLS");
			printf("Nem v�s�rolt semmit!\n");
			menu();
		}
	}
	else if (valasz == 3) {
		//Kil�p�s
		printf("Program v�ge!");
	}
	else{		
		printf("Hib�s v�lasz (%d), �jra!\n", valasz);
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