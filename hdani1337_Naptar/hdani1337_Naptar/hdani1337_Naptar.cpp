#include "pch.h"
#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)

int main()
{
	setlocale(LC_ALL, "");

	int napNevSzama = 0;
	int megadottNapSzam = 0;
	char megadottNapNev = ' ';

	printf("K�rek egy napsz�mot: ");
	scanf(" %d", &megadottNapSzam);
	printf("K�rem a h�nap els� napj�nak nev�t: ");
	scanf(" %c", &megadottNapNev);

	megadottNapSzam--;

	switch (megadottNapNev) {
	case 'h:': napNevSzama = 1; break;
	case 'k:': napNevSzama = 2; break;
	case 's:': napNevSzama = 3; break;
	case 'c:': napNevSzama = 4; break;
	case 'p:': napNevSzama = 5; break;
	case 'z:': napNevSzama = 6; break;
	case 'v:': napNevSzama = 7; break;
	}

	int kapottNap = (megadottNapSzam % 7) + napNevSzama;
	
	if (kapottNap > 7)
		kapottNap -= 7;
	printf("%d",kapottNap);

	switch (kapottNap) {
	case 1: printf("h�tf�"); break;
	case 2: printf("kedd"); break;
	case 3: printf("szerda"); break;
	case 4: printf("cs�t�rt�k"); break;
	case 5: printf("p�ntek"); break;
	case 6: printf("szombat"); break;
	case 7: printf("vas�rnap"); break;
	}
}