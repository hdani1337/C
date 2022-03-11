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
		cout << "Az átlag: " << atlag;
	}
	else {
		cout << "Nem sikerült megnyitni a fájlt!";
	}
}

//Ki hány éves
//Átlagéletkor
//Ki a legidõsebb?
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
		cout << "Átlag életkor: " << (atlag / 10) << endl;
		cout << legidosebbNev << " a legidõsebb, aki " << legidosebbKor << " éves." << endl;
	}
	else {
		cout << "Nem sikerült megnyitni a fájlt!";
	}
}

double ttindex(int magassag, int testsuly) {
	return testsuly / ((magassag / 100.0)*(magassag / 100.0));
}

//Fájlból olvassuk be az adatokat, és írassuk ki a testtömeg indexeket
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

			cout << nev << "\t" << magassag << " cm magas és " << suly << " kg nehéz. \tTesttömegindexe: " << ttindex(magassag, suly) << endl;
		}
		cout << legkisebbNev << " a legsoványabb, akinek " << legkisebbSuly << " a testtömegindexe." << endl;
	}
	else {
		cout << "Nem sikerült megnyitni a fájlt!";
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
	18-30 között 20 nap		1 gyerek 2 nap
	31-40 között 22 nap		2 gyerek 4 nap
	41-50 között 25 nap		3 gyerek 7 nap
	51-65 között 30 nap
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

			cout << nev << "\t" << kor << " éves és " << gyerekek << " gyereke van. " << (napokGyerekekAlapjan(gyerekek)+napokKorAlapjan(kor)) << " nap szabadsága van." << endl;
		}
	}
	else {
		cout << "Nem sikerült megnyitni a fájlt!";
	}
}

int main()
{
	//beolvasottAtlag();
	//baratok();
	//bmi();
	szabadsag();
}
