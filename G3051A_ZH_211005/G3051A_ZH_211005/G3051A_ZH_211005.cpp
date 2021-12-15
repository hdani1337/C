// G3051A_ZH_211005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>

#pragma warning(disable : 4996)

int main()
{
	int magassag = -1;//alacsony-k�zepes-magas
	int hajszin = -1;//fekete-v�r�s-sz�ke
	int nem = -1;//n�-f�rfi
	int meret = -1;//kicsi-nagy-felem�s
	int labbeli = -1;//bakancs-papucs-cip�

	setlocale(LC_ALL, "");

	printf("Kerek egy magassagot: ");
	scanf(" %d", &magassag);

	while (!(magassag >= 1 && magassag <= 3)) {
		printf("Hibas ertek! Kerek egy magassagot: ");
		scanf(" %d", &magassag);
	}

	printf("Kerek egy hajszint: ");
	scanf(" %d", &hajszin);

	while (!(hajszin >= 1 && hajszin <= 3)) {
		printf("Hibas ertek! Kerek egy hajszint: ");
		scanf(" %d", &hajszin);
	}

	printf("Kerek egy nemet: ");
	scanf(" %d", &nem);

	while (!(nem >= 1 && nem <= 2)) {
		printf("Hibas ertek! Kerek egy nemet: ");
		scanf(" %d", &nem);
	}

	printf("Kerek egy meretet: ");
	scanf(" %d", &meret);

	while (!(meret >= 1 && meret <= 3)) {
		printf("Hibas ertek! Kerek egy meretet: ");
		scanf(" %d", &meret);
	}

	printf("Kerek egy labbelit: ");
	scanf(" %d", &labbeli);

	while (!(labbeli >= 1 && labbeli <= 3)) {
		printf("Hibas ertek! Kerek egy labbelit: ");
		scanf(" %d", &labbeli);
	}

	//Magass�g ki�r�sa
	if (magassag == 1) printf("alacsony ");
	else if (magassag == 2) printf("k�zepes ");
	else if (magassag == 3) printf("magas ");

	//Hajsz�n ki�r�sa
	if (hajszin == 1) printf("fekete ");
	else if (hajszin == 2) printf("v�r�s ");
	else if (hajszin == 3) printf("sz�ke ");

	//Nem ki�r�sa
	if (nem == 1) printf("n� ");
	else if (nem == 2) printf("f�rfi ");

	//Cip�m�ret ki�r�sa
	if (meret == 1) printf("kicsi ");
	else if (meret == 2) printf("nagy ");
	else if (meret == 3) printf("felem�s ");

	//Cip� fajt�j�nak		ki�r�sa
	if (labbeli == 1) printf("bakancsban");
	else if (labbeli == 2) printf("papucsban");
	else if (labbeli == 3) printf("cip�ben");
}
