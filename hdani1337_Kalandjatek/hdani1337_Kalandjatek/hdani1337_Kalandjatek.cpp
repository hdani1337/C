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

char terkep[3][3] = { 'e', 'e', 'm',
							'e', 'v', 'm',
							'm', 'm', 'm' };
int x = 1;
int y = 1;
int megy = 1;
int hp = 100;
int attack = 5;
int def = 10;
int seb = 10;
int enHp = 100;
int enAttack = 8;
int enDef = 7;
int enSeb = 12;

void mozog(char c) {
	('a' == c) ? x-- : ('s' == c) ? y++ : ('w' == c) ? y-- : ('d' == c) ? x++ : ('q' == c) ? megy = 0 : true;
	(x < 0) ? x = 0 : (x > 2) ? x = 2 : true;
	(y < 0) ? y = 0 : (y > 2) ? y = 2 : true;
}

void helyszinKiir() {
	('e' == terkep[x][y]) ? printf("\x1b[32mErdõ\x1b[0m") : ('v' == terkep[x][y]) ? printf("\x1b[36mVíz\x1b[0m") : ('m' == terkep[x][y]) ? printf("\x1b[33mMezõ\x1b[0m") : true;
}

void hpKiir(){
    (hp > 50) ? printf("\x1b[32mHP: %d\x1b[0m",hp) : (hp >= 25) ? printf("\x1b[33mHP: %d\x1b[0m",hp) : (hp < 25) ? printf("\x1b[31mHP: %d\x1b[0m",hp) : true;
}

void terkepKirajzol() {
	system("cls");
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("|");
		for (int j = 0; j < 3; j++)
		{
			(i == y && j == x) ? printf("\x1b[31m%c\x1b[0m|",terkep[i][j]) : printf("%c|", terkep[i][j]);
		}
		printf("\n");
	}
	helyszinKiir();
	printf("\n");
	hpKiir();
	printf("\n");
}

void harc(int HP, int tam, int ved, int seb, int szHP, int szTam, int szVed, int szSeb)
{
	do
	{
		//karakter kezd
		if (tam + rand() % 10 + 1 > szVed)
		{
			szHP -= seb;
			printf("Karakter HP: %d\nSzorny HP: %d\n",HP,szHP);
		}
		else
			printf("Nem talaltad el a szornyet.\n");
		//szörny visszaüt
		if (szTam + rand() % 10 + 1 > ved)
		{
			HP -= szSeb;
			printf("Karakter HP: %d\nSzorny HP: %d\n", HP, szHP);
		}
		else
			printf("A szorny nem talalt el.\n");
	} while (HP>0 && szHP>0);
}

int meglepi(int kx, int ky, int HP)
{
	if (kx == 0 && ky == 0)
	{
		printf("Csapda. Sebzodtel.\n");
		HP -= 50;
		printf("HP: %d\n", HP);
	}
	if (kx == 0 && ky == 2)
	{
		printf("Kincs. Gyogyultal.\n");
		HP += 25;
		printf("HP: %d\n", HP);
	}
	return HP;
}

void step() {
	char irany;
	/*printf("\n\x1b[35mMozgás: \x1b[0m");
	scanf(" %c", &irany);*/
    hp = meglepi(x, y, hp);
    
    if (x == 2 && y == 1)
        harc(hp, attack, def, seb, enHp, enAttack, enDef, enSeb);

	mozog(getch());
	terkepKirajzol();
}

int main()
{
	setlocale(LC_ALL, "");
	terkepKirajzol();
	while(megy == 1)
		step();
}