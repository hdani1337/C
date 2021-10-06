#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void egydimenzios() {
	int v[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < 5; i++)
		printf("%d\n", v[i]);
}

void ketdimenzios() {
	int v[2][3];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &v[i][j]);

	printf("\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}

	printf("%d",v[1][3]);
}

void randomSzam() {
	srand(time(0));

	char v[10];
	v[0] = 65 + rand() % 26;//nagy
	for (int i = 1; i < 10; i++) {
		v[i] = 97 + rand() % 26;//kicsi
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%c",v[i]);
	}

	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "");
	//ketdimenzios();
	for (int i = 0; i < 50; i++) randomSzam();
}