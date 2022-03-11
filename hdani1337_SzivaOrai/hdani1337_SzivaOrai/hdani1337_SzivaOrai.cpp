#include "pch.h"
#include "locale.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void beolvasottAtlag() {
	setlocale(LC_ALL, "");
	ifstream adatok("adatok.txt");

	double atlag = 0.0;
	int szam = 0;
	int darab = 0;

	if (adatok.is_open()) {
		adatok >> darab;
		while (adatok >> szam) {
			atlag += szam;
		}
		atlag /= darab;
		cout << "Az �tlag: " << atlag;
	}
	else {
		cout << "Nem siker�lt megnyitni a f�jlt!";
	}
}

//Ki h�ny �ves
//�tlag�letkor
//Ki a legid�sebb?
void baratok() {
	setlocale(LC_ALL, "");
	ifstream adatok("baratok.txt");

	if (adatok.is_open()) {
		double atlag = 0.0;
		int legidosebbKor = 0;
		string legidosebbNev = "";
		for (int i = 0; i < 10; i++)
		{
			int kor = 0;
			string nev = "";
			adatok >> nev >> kor;
			kor = 2022 - kor;

			atlag += kor;

			if (kor > legidosebbKor) {
				legidosebbKor = kor;
				legidosebbNev = nev;
			}

			cout << nev << "\t" << kor << endl;
			
		}
		cout << "�tlag �letkor: " << (atlag / 10) << endl;
		cout << legidosebbNev << " a legid�sebb, aki " << legidosebbKor << " �ves." << endl;
	}
	else {
		cout << "Nem siker�lt megnyitni a f�jlt!";
	}
}

double ttindex(int magassag, int testsuly) {
	return testsuly / ((magassag / 100.0)*(magassag / 100.0));
}

//F�jlb�l olvassuk be az adatokat, �s �rassuk ki a testt�meg indexeket
void bmi() {
	setlocale(LC_ALL, "");
	ifstream adatok("bmi.txt");

	float legkisebbSuly = 100.0;
	string legkisebbNev = "";

	if (adatok.is_open()) {
		for (int i = 0; i < 10; i++)
		{
			string nev = "";
			int magassag = 0;
			int suly = 0;
			adatok >> nev >> magassag >> suly;

			if (legkisebbSuly > ttindex(magassag,suly)) {
				legkisebbSuly = ttindex(magassag, suly);
				legkisebbNev = nev;
			}

			cout << nev << "\t" << magassag << " cm magas �s " << suly << " kg neh�z. \tTestt�megindexe: " << ttindex(magassag, suly) << endl;
		}
		cout << legkisebbNev << " a legsov�nyabb, akinek " << legkisebbSuly << " a testt�megindexe." << endl;
	}
	else {
		cout << "Nem siker�lt megnyitni a f�jlt!";
	}
}

int napokKorAlapjan(int kor) {
	if (kor >= 18 && kor <= 30) {
		return 20;
	}
	else if (kor >= 31 && kor <= 40) {
		return 22;
	}
	else if (kor >= 41 && kor <= 50) {
		return 25;
	}
	else if (kor >= 51 && kor <= 65) {
		return 30;
	}
	else return 0;
}

int napokGyerekekAlapjan(int gyerekek) {
	switch (gyerekek)
	{
		case 1: return 2;
		case 2: return 4;
		case 3: return 7;
		default:return 0;
	}
}

void szabadsag() {
	/*
	18-30 k�z�tt 20 nap		1 gyerek 2 nap
	31-40 k�z�tt 22 nap		2 gyerek 4 nap
	41-50 k�z�tt 25 nap		3 gyerek 7 nap
	51-65 k�z�tt 30 nap
	*/

	setlocale(LC_ALL, "");
	ifstream adatok("szabadsag.txt");

	if (adatok.is_open()) {
		for (int i = 0; i < 10; i++)
		{
			string nev = "";
			int ev = 0;
			int gyerekek = 0;
			adatok >> nev >> ev >> gyerekek;

			int kor = 2022 - ev;

			cout << nev << "\t" << kor << " �ves �s " << gyerekek << " gyereke van. " << (napokGyerekekAlapjan(gyerekek)+napokKorAlapjan(kor)) << " nap szabads�ga van." << endl;
		}
	}
	else {
		cout << "Nem siker�lt megnyitni a f�jlt!";
	}
}

int main()
{
	//beolvasottAtlag();
	//baratok();
	//bmi();
	szabadsag();
}
