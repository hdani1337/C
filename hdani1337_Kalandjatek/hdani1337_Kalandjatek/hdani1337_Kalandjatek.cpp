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

void mozog(char c) {
	('a' == c) ? x-- : ('s' == c) ? y++ : ('w' == c) ? y-- : ('d' == c) ? x++ : ('q' == c) ? megy = 0 : true;
	(x < 0) ? x = 0 : (x > 2) ? x = 2 : true;
	(y < 0) ? y = 0 : (y > 2) ? y = 2 : true;
}

void helyszinKiir() {
	('e' == terkep[x][y]) ? printf("\x1b[32mErdõ\x1b[0m") : ('v' == terkep[x][y]) ? printf("\x1b[36mVíz\x1b[0m") : ('m' == terkep[x][y]) ? printf("\x1b[33mMezõ\x1b[0m") : true;
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
}

void step() {
	char irany;
	/*printf("\n\x1b[35mMozgás: \x1b[0m");
	scanf(" %c", &irany);*/
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