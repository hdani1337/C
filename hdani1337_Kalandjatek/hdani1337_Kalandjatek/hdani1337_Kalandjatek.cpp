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

	e: erdõ
	m: mezõ
	v: víz
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
		printf("\x1b[33mA hátizsák üres.\x1b[0m\n");
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
	('e' == terkep[(*jatekos).x][(*jatekos).y]) ? printf("\x1b[32mErdõ\x1b[0m") : ('v' == terkep[(*jatekos).x][(*jatekos).y]) ? printf("\x1b[36mVíz\x1b[0m") : ('m' == terkep[(*jatekos).x][(*jatekos).y]) ? printf("\x1b[33mMezõ\x1b[0m") : true;
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
			printf("\x1b[33m%d.kör, te támadsz:\t\x1b[0m", szamlalo);
			if ((*jatekos).tam + rand() % 10 + 1 > (*szorny).ved)
			{
				(*szorny).hp -= (*jatekos).seb;
				printf("Karakter HP: %d\t\tSzorny HP: %d\n", (*jatekos).hp, (*szorny).hp);
			}
			else
				printf("\x1b[31mNem talaltad el a szornyet.\x1b[0m\n");

			//szörny visszaüt
			printf("\x1b[33m%d.kör, szörny támad:\t\x1b[0m", szamlalo);
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
		printf("\x1b[31mCsapda. Sebzõdtél.\n");
		jatekos.hp -= 50;
		printf("HP: %d\n\x1b[0m", jatekos.hp);
	}
	if (jatekos.x == 0 && jatekos.y == 2)
	{
		printf("\x1b[32mKincs. Gyógyultál.\n");
		jatekos.hp += 25;
		printf("HP: %d\n\x1b[0m", jatekos.hp);
	}
	return jatekos.hp;
}

void odaad() {
	//Ha paraméterben adom át a hátizsák pointert, akkor pointerre mutató pointerrel kell kezelni
	tarolo* aktualis;
	int N = 1, i = 1;
	aktualis = hatizsak;
	while (aktualis->kovetkezo != NULL) {
		aktualis = aktualis->kovetkezo;
		N++;
	}

	while (strcmp(aktualis->nev, "gyógynövény") != 0 && aktualis->kovetkezo != NULL) {
		aktualis = aktualis->kovetkezo;
		i++;
	}

	if(aktualis->db > 1) aktualis->db--;
	else
	{//Töröljük a listából
		if (i == 1) {
			//Lista elején
			hatizsak = hatizsak->kovetkezo;
			free(aktualis);	
		}
		if (i > 1 && i < N) {
			//Lista közepén
			

		}
	}
}

void medzsik(eloleny *jatekos, eloleny *varazslo)
{
	if ((*jatekos).x == (*varazslo).x && (*jatekos).y == (*varazslo).y) {
		if ((*varazslo).talalkozas == -1) {
			//Elõször találkozunk a varázslóval
			printf("\x1b[33mTalálkoztál egy öreg varázslóval. Megkér, hogy hozz el neki egy gyógynövényt. Cserébe jutalomban részesülsz.\x1b[0m");
			(*varazslo).talalkozas = 1;
		}
		else if ((*varazslo).talalkozas == 2) {
			//Már voltunk a varázslónál, és megszereztük a gyógyfüvet
			char answer = '\0';
			printf("\x1b[33mVisszatértél az öreg varázslóhoz. Megköszöni, hogy elhoztad a gyógynövényt, cserébe ajánl neked egy pajzsot és egy kardot. Melyiket választod? (k/p): \x1b[35m");
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
			//Már voltunk a varázslónál, de még nincs nálunk a gyógyfû
			printf("\x1b[33mA varázsló morcosan néz rád. Miért jöttél vissza? Menj, keresd tovább!\x1b[0m");
			(*varazslo).talalkozas = 1;
		}
	}
}

void gyogynoveny(eloleny* jatekos, eloleny* varazslo, tarolo* hatizsak) {
	if ((*jatekos).x == gyogyx && (*jatekos).y == gyogyy && (*varazslo).talalkozas != -1) {
		(*varazslo).talalkozas = 2;
		printf("\x1b[32mGyógyfüvet találtál! Be is teszel egyet gyorsan a zsákodba!\x1b[0m\n");
		tarolo *elozo, *aktualis;
		elozo = hatizsak;
		while (strcmp(elozo->nev, "gyógynövény") != 0 && elozo->kovetkezo != NULL)
			elozo = elozo->kovetkezo;
		if (elozo->kovetkezo == NULL){
			strcpy(elozo->nev, "gyógynövény");
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
	/*printf("\n\x1b[35mMozgás: \x1b[0m");
	scanf(" %c", &irany);*/

	//Dinamikus változó: hátizsák
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