#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

/*
	�tlag sz�m�t�s vektorban
	24 �ra m�r�si adata, 1 m�r�s/�ra, �tlag ki�r�sa
	a, h�m�rs�klet �rt�kek 0-25 fok tartom�nyb�l
	b, h�m�rs�klet �rt�kek -15 -- 5 fok tartom�nyb�l
	c, random �rt�kek a 20 fok k�r�li +- 2 fokos tartom�nyb�l
	d, felmeleged�si-visszah�l�si �ve legyen a h�m�rs�kletnek -15-t�l +5 fokig �s vissza. Ezen az �ven random �rt�kek +-2 fokos tartom�nyb�l
*/
void idojarasMeroA(int max) {
	int meresek[24];
	double sum = 0.0;
	for (int i = 0; i < 24; i++)
	{
		meresek[i] = rand() % max;
		sum += meresek[i];
		printf("%d. M�r�s: %d\n", i, meresek[i]);
	}
	double atlag = sum / 24;
	printf("0-%d fok k�zti m�r�sek �tlaga: %.2lf\n\n", max, atlag);
}

void idojarasMeroB(int min, int max) {
	int meresek[24];
	double sum = 0.0;
	for (int i = 0; i < 24; i++)
	{
		meresek[i] = max - (rand() % (abs(min)+abs(max)));
		sum += meresek[i];
		printf("%d. M�r�s: %d\n", i, meresek[i]);
	}
	double atlag = sum / 24;
	printf("%d-%d fok k�zti m�r�sek �tlaga: %.2lf\n\n", min, max, atlag);
}

void idojarasMeroC(int alaphomerseklet, int elteres) {
	int meresek[24];
	double sum = 0.0;
	for (int i = 0; i < 24; i++)
	{
		meresek[i] = (alaphomerseklet+elteres) - (rand() % ((elteres*2)+1));
		sum += meresek[i];
		printf("%d. M�r�s: %d\n",i,meresek[i]);
	}
	double atlag = sum / 24;
	printf("%d+-%d fok k�zti m�r�sek �tlaga: %.2lf\n\n", alaphomerseklet,elteres,atlag);
}

void idojarasMeroD(int min, int max, int elteres) {
	double meresek[24];
	double sum = 0.0;
	for (int i = 0; i < 12; i++)
	{
		double dif = (abs(min)+abs(max)) / 12.0;		
		meresek[i] = (min - elteres) + (dif*i) + (rand() % (elteres * 2));
		sum += meresek[i];
		printf("%.2lf\n", meresek[i]);
		
	}
	for (int i = 11; i >= 0; i--)
	{
		double dif = (abs(min) + abs(max)) / 12.0;
		meresek[i] = (min - elteres) + (dif*i) + (rand() % (elteres * 2));
		sum += meresek[i];
		printf("%.2lf\n", meresek[i]);
		
	}
	double atlag = sum / 24;
	printf("�velt m�r�sek �tlaga: %.2lf\n\n", atlag);
}

void minimum() {
	printf("Sz�mok:  ");
	int szamok[5];
	for (int i = 0; i < 5; i++) {
		szamok[i] = rand() % 1000;
		printf("%d ", szamok[i]);
	}
	int min = szamok[1];
	for (int i = 1; i < 5; i++)
		if (szamok[i] < min)
			min = szamok[i];
	printf("\nMinimum: %d\n\n", min);
}

void minimumRendezesNovekvo() {
	int szamok[10];
	printf("Eredeti:   ");

	for (int i = 0; i < 10; i++) {
		szamok[i] = rand() % 1000;
		printf("%d ", szamok[i]);
	}

	printf("\nRendezett: ");

	for (int j = 0; j < 9; j++)
	{
		int hely = j;
		int min = szamok[j];
		for (int i = j+1; i < 10; i++)
			if (szamok[i] < min) {
				min = szamok[i];
				hely = i;
			}
		int temp = szamok[j];
		szamok[j] = szamok[hely];
		szamok[hely] = temp;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", szamok[i]);
	}

	printf("\n\n");
}

void transzponalas() {
	int size = 10;
	int matrix[10][10];

	//Felt�lt�s, kirajzol�s
	printf("Eredeti m�trix\n");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = rand() % 90 + 10;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	//Transzpon�l�s, kirajzol�s
	printf("\nTranszpon�lt m�trix\n");
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	//Visszatranszpon�l�s, kirajzol�s
	printf("\nVisszatranszpon�lt m�trix\n");
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

void minimumRendezesNovekvoMatrixban() {
	int size = 10;
	int matrix[10][8];

	//Felt�lt�s, kirajzol�s
	printf("Rendezetlen m�trix\n");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 8; j++)
			matrix[i][j] = rand() % 90 + 10;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 8; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	printf("\n");

	int seged[10 * 8];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 8; j++)
			seged[i*8+j] = matrix[i][j];

	for (int j = 0; j < 79; j++)
	{
		int hely = j;
		int min = seged[j];
		for (int i = j + 1; i < 80; i++)
			if (seged[i] < min) {
				min = seged[i];
				hely = i;
			}
		int temp = seged[j];
		seged[j] = seged[hely];
		seged[hely] = temp;
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < 8; j++)
			matrix[i][j] = seged[i*8+j];

	printf("Rendezett m�trix\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 8; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned)time(NULL));
	//idojarasMeroA(25);
	//idojarasMeroB(-15,5);
	//idojarasMeroC(20,2);
	//idojarasMeroD(-15,15,2);
	minimum();
	minimumRendezesNovekvo();
	minimumRendezesNovekvoMatrixban();
	transzponalas();
}