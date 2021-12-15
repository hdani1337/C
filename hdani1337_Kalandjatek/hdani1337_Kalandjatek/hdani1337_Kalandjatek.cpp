#include "pch.h"
#include <iostream>
#include <conio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#pragma warning(disable : 4996)

/*
	|e|e|m|
	|e|v|m|
	|m|m|m|

	e: erd�
	m: mez�
	v: v�z
*/

char terkep[6][6] = { 'e', 'e', 'm', 'e', 'e', 'm',
							'e', 'v', 'm', 'e', 'v', 'm',
							'm', 'm', 'm' , 'm', 'm', 'm',
							'e', 'e', 'm', 'e', 'e', 'm',
							'e', 'v', 'm', 'e', 'v', 'm',
							'm', 'm', 'm' , 'm', 'm', 'm' };
int megy = 1;
int gyogyx = 2;
int gyogyy = 3;

struct eloleny {
	int x;
	int y;
	int hp;
	int tam;
	int seb;
	int ved;
	int talalkozas;
};

struct tarolo {
	char nev[10];
	int db;
	tarolo* kovetkezo;
};

eloleny jatekos;
eloleny szorny;
eloleny varazslo;
tarolo *hatizsak;

void init() {
	jatekos.x = 1;
	jatekos.y = 1;
	jatekos.hp = 100;
	jatekos.tam = 5;
	jatekos.seb = 10;
	jatekos.ved = 10;

	szorny.x = 2;
	szorny.y = 1;
	szorny.hp = 100;
	szorny.tam = 8;
	szorny.seb = 12;
	szorny.ved = 7;

	varazslo.x = 5;
	varazslo.y = 5;
	varazslo.talalkozas = -1;

	hatizsak = (tarolo*)(malloc(sizeof(tarolo)));
	strcpy(hatizsak->nev,"");
	hatizsak->db = 0;
	hatizsak->kovetkezo = NULL;
}

void hatizsakKiir() {
	tarolo *aktualis;
	aktualis = hatizsak;
	if (aktualis->kovetkezo == NULL)
		printf("\x1b[33mA h�tizs�k �res.\x1b[0m\n");
	else
	{
		while (aktualis->kovetkezo != NULL)
		{
			printf("\x1b[33m%d darab %s\x1b[0m\n", aktualis->db, aktualis->nev);
			aktualis = aktualis->kovetkezo;
		}
	}
	_sleep(1000);
}

void mozog(char c, eloleny *jatekos, eloleny *szorny) {
	('a' == c) ? (*jatekos).x-- : ('s' == c) ? (*jatekos).y++ : ('w' == c) ? (*jatekos).y-- : ('d' == c) ? (*jatekos).x++ : ('q' == c) ? megy = 0 : true;
	((*jatekos).x < 0) ? (*jatekos).x = 0 : ((*jatekos).x > 5) ? (*jatekos).x = 5 : true;
	((*jatekos).y < 0) ? (*jatekos).y = 0 : ((*jatekos).y > 5) ? (*jatekos).y = 5 : true;
	
	(*szorny).y = rand() % 6;

	int temp = rand() % 101;

	if (temp >= 33) {
		temp = rand() % 4;
		(0 == temp) ? (*szorny).x-- : (1 == temp) ? (*szorny).y++ : (3 == temp) ? (*szorny).y-- : (2 == temp) ? (*szorny).x++ : true;
	}
	((*szorny).x < 0) ? (*szorny).x = 0 : ((*szorny).x > 5) ? (*szorny).x = 5 : true;
	((*szorny).y < 0) ? (*szorny).y = 0 : ((*szorny).y > 5) ? (*szorny).y = 5 : true;

	if ('h' == c) hatizsakKiir();
}

void helyszinKiir(eloleny *jatekos) {
	('e' == terkep[(*jatekos).x][(*jatekos).y]) ? printf("\x1b[32mErd�\x1b[0m") : ('v' == terkep[(*jatekos).x][(*jatekos).y]) ? printf("\x1b[36mV�z\x1b[0m") : ('m' == terkep[(*jatekos).x][(*jatekos).y]) ? printf("\x1b[33mMez�\x1b[0m") : true;
}

void hpKiir(){
    (jatekos.hp > 50) ? printf("\x1b[32mHP: %d\x1b[0m",jatekos.hp) : (jatekos.hp >= 25) ? printf("\x1b[33mHP: %d\x1b[0m",jatekos.hp) : (jatekos.hp < 25) ? printf("\x1b[31mHP: %d\x1b[0m",jatekos.hp) : true;
}

void terkepKirajzol(eloleny *jatekos, eloleny *szorny) {
	system("cls");
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("|");
		for (int j = 0; j < 6; j++)
		{
			(i == (*jatekos).y && j == (*jatekos).x) ? printf("\x1b[31m%c\x1b[0m|",terkep[i][j]) : (i == (*szorny).y && j == (*szorny).x) ? printf("|S") : printf("%c|", terkep[i][j]);
		}
		printf("\n");
	}
	helyszinKiir(jatekos);
	printf("\n");
	hpKiir();
	printf("\n");
}

void harc(eloleny *jatekos, eloleny *szorny)
{
	if ((*jatekos).x == (*szorny).x && (*jatekos).y == (*szorny).y) {
		int szamlalo = 0;
		while ((*jatekos).hp > 0 && (*szorny).hp > 0)
		{
			//(*jatekos).tam <==> jatekos->tam
			szamlalo++;

			//karakter kezd
			printf("\x1b[33m%d.k�r, te t�madsz:\t\x1b[0m", szamlalo);
			if ((*jatekos).tam + rand() % 10 + 1 > (*szorny).ved)
			{
				(*szorny).hp -= (*jatekos).seb;
				printf("Karakter HP: %d\t\tSzorny HP: %d\n", (*jatekos).hp, (*szorny).hp);
			}
			else
				printf("\x1b[31mNem talaltad el a szornyet.\x1b[0m\n");

			//sz�rny vissza�t
			printf("\x1b[33m%d.k�r, sz�rny t�mad:\t\x1b[0m", szamlalo);
			if ((*szorny).tam + rand() % 10 + 1 > (*jatekos).ved)
			{
				(*jatekos).hp -= (*szorny).seb;
				printf("Karakter HP: %d\t\tSzorny HP: %d\n", (*jatekos).hp, (*szorny).hp);
			}
			else
				printf("\x1b[32mA szorny nem talalt el.\x1b[0m\n");
			_sleep(200);
		}
	}
}

int meglepi(eloleny jatekos)
{
	if (jatekos.x == 0 && jatekos.y == 0)
	{
		printf("\x1b[31mCsapda. Sebz�dt�l.\n");
		jatekos.hp -= 50;
		printf("HP: %d\n\x1b[0m", jatekos.hp);
	}
	if (jatekos.x == 0 && jatekos.y == 2)
	{
		printf("\x1b[32mKincs. Gy�gyult�l.\n");
		jatekos.hp += 25;
		printf("HP: %d\n\x1b[0m", jatekos.hp);
	}
	return jatekos.hp;
}

void odaad() {
	//Ha param�terben adom �t a h�tizs�k pointert, akkor pointerre mutat� pointerrel kell kezelni
	tarolo* aktualis;
	int N = 1, i = 1;
	aktualis = hatizsak;
	while (aktualis->kovetkezo != NULL) {
		aktualis = aktualis->kovetkezo;
		N++;
	}

	while (strcmp(aktualis->nev, "gy�gyn�v�ny") != 0 && aktualis->kovetkezo != NULL) {
		aktualis = aktualis->kovetkezo;
		i++;
	}

	if(aktualis->db > 1) aktualis->db--;
	else
	{//T�r�lj�k a list�b�l
		if (i == 1) {
			//Lista elej�n
			hatizsak = hatizsak->kovetkezo;
			free(aktualis);	
		}
		if (i > 1 && i < N) {
			//Lista k�zep�n
			

		}
	}
}

void medzsik(eloleny *jatekos, eloleny *varazslo)
{
	if ((*jatekos).x == (*varazslo).x && (*jatekos).y == (*varazslo).y) {
		if ((*varazslo).talalkozas == -1) {
			//El�sz�r tal�lkozunk a var�zsl�val
			printf("\x1b[33mTal�lkozt�l egy �reg var�zsl�val. Megk�r, hogy hozz el neki egy gy�gyn�v�nyt. Cser�be jutalomban r�szes�lsz.\x1b[0m");
			(*varazslo).talalkozas = 1;
		}
		else if ((*varazslo).talalkozas == 2) {
			//M�r voltunk a var�zsl�n�l, �s megszerezt�k a gy�gyf�vet
			char answer = '\0';
			printf("\x1b[33mVisszat�rt�l az �reg var�zsl�hoz. Megk�sz�ni, hogy elhoztad a gy�gyn�v�nyt, cser�be aj�nl neked egy pajzsot �s egy kardot. Melyiket v�lasztod? (k/p): \x1b[35m");
			scanf(" %c", &answer);
			if (answer == 'p') {
				(*jatekos).ved += 5;
			}
			else if (answer == 'k') {
				(*jatekos).seb += 5;
			}
			odaad();
			printf("\x1b[0m");
		}
		else {
			//M�r voltunk a var�zsl�n�l, de m�g nincs n�lunk a gy�gyf�
			printf("\x1b[33mA var�zsl� morcosan n�z r�d. Mi�rt j�tt�l vissza? Menj, keresd tov�bb!\x1b[0m");
			(*varazslo).talalkozas = 1;
		}
	}
}

void gyogynoveny(eloleny* jatekos, eloleny* varazslo, tarolo* hatizsak) {
	if ((*jatekos).x == gyogyx && (*jatekos).y == gyogyy && (*varazslo).talalkozas != -1) {
		(*varazslo).talalkozas = 2;
		printf("\x1b[32mGy�gyf�vet tal�lt�l! Be is teszel egyet gyorsan a zs�kodba!\x1b[0m\n");
		tarolo *elozo, *aktualis;
		elozo = hatizsak;
		while (strcmp(elozo->nev, "gy�gyn�v�ny") != 0 && elozo->kovetkezo != NULL)
			elozo = elozo->kovetkezo;
		if (elozo->kovetkezo == NULL){
			strcpy(elozo->nev, "gy�gyn�v�ny");
			elozo->db = 1;
		}else (elozo->db)++;
		
		aktualis = (tarolo*)malloc(sizeof(tarolo));
		strcpy(aktualis->nev, "");
		aktualis->db = 0;
		aktualis->kovetkezo = NULL;
		elozo->kovetkezo = aktualis;
	}
}

void step() {
	char irany;
	/*printf("\n\x1b[35mMozg�s: \x1b[0m");
	scanf(" %c", &irany);*/

	//Dinamikus v�ltoz�: h�tizs�k
	jatekos.hp = meglepi(jatekos);
	harc(&jatekos,&szorny);
	gyogynoveny(&jatekos, &varazslo, hatizsak);
	medzsik(&jatekos, &varazslo);
	mozog(getch(),&jatekos,&szorny);
	terkepKirajzol(&jatekos, &szorny);
}

int main()
{
	setlocale(LC_ALL, "");
	init();
	terkepKirajzol(&jatekos, &szorny);
	while(megy == 1)
		step();
}