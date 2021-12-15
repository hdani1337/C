// G3051A_ZH_211005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>

#pragma warning(disable : 4996)

int main()
{
	int magassag = -1;//alacsony-közepes-magas
	int hajszin = -1;//fekete-vörös-szõke
	int nem = -1;//nõ-férfi
	int meret = -1;//kicsi-nagy-felemás
	int labbeli = -1;//bakancs-papucs-cipõ

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

	//Magasság kiírása
	if (magassag == 1) printf("alacsony ");
	else if (magassag == 2) printf("közepes ");
	else if (magassag == 3) printf("magas ");

	//Hajszín kiírása
	if (hajszin == 1) printf("fekete ");
	else if (hajszin == 2) printf("vörös ");
	else if (hajszin == 3) printf("szõke ");

	//Nem kiírása
	if (nem == 1) printf("nõ ");
	else if (nem == 2) printf("férfi ");

	//Cipõméret kiírása
	if (meret == 1) printf("kicsi ");
	else if (meret == 2) printf("nagy ");
	else if (meret == 3) printf("felemás ");

	//Cipõ fajtájának		kiírása
	if (labbeli == 1) printf("bakancsban");
	else if (labbeli == 2) printf("papucsban");
	else if (labbeli == 3) printf("cipõben");
}
