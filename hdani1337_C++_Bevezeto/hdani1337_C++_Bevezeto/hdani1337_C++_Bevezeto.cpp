#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

//2 értéket bekér, műveleti jelet, majd elvégzi a műveletet
void muveletiJelek() {
	cout << endl << "-----Számoló program-----" << endl;
	double a, b, eredmeny;
	char muvelet;

	cout << "Kérek egy számot: ";
	cin >> a;
	cout << "Kérek még egy számot: ";
	cin >> b;
	cout << "Kérek egy műveleti jelet (+-*/): ";
	cin >> muvelet;

	eredmeny = (muvelet == '*') ? a * b : (muvelet == '/') ? a / b : (muvelet == '+') ? a + b : (muvelet == '-') ? a - b : false;

	cout << "Az eredmény: " << eredmeny;
	cout << endl << "---------------------------" << endl;
}

//Ugyanaz, mint a muveletiJelek(), csak ez kiírja az eredményeket egy fájlba
void fajlkezelesesMuveletiJelek() {
	cout << endl << "-----Számolás kiírása fájlba-----" << endl;
	double a, b, eredmeny;
	char muvelet;
	
	ofstream kimenet("szamolasok.txt");

	cout << "Kérek egy számot: ";
	cin >> a;
	cout << "Kérek még egy számot: ";
	cin >> b;
	cout << "Kérek egy műveleti jelet (+-*/): ";
	cin >> muvelet;

	eredmeny = (muvelet == '*') ? a * b : (muvelet == '/') ? a / b : (muvelet == '+') ? a + b : (muvelet == '-') ? a - b : throw runtime_error("");

	cout << "Az eredmény (" << a << " " << muvelet << " " << b << "): " << eredmeny << endl;

	kimenet << "Az eredmény (" << a << " " << muvelet << " " << b << "): " << eredmeny;
	kimenet.close();
	cout << endl << "---------------------------" << endl;
}

//Ugyanaz, mint a fajlkezelesesMuveletiJelek(), csak ez beolvassa az eredményt egy fájlból
void fajlkezelesesMuveletiJelekBeolvasas() {
	cout << endl << "-----Beolvasás fájlból-----" << endl;
	double a, b, eredmeny;
	char muvelet;
	
	ifstream bemenet("szamolasok.txt");

	string beolvasott;
	while (!bemenet.eof()) {
		bemenet >> beolvasott;
		cout << beolvasott.data() << " ";
	}

	cout << endl << "---------------------------" << endl;
	bemenet.close();
}

//Fájlból beolvassuk a piramis szerkezetét, az első szám mindig a telített helyek kezdetét jelenti, a második pedig a végét
void piramis() {
	ifstream szamok("piramis.txt");

	int kezd;
	int veg;
	while (!szamok.eof()) {
		szamok >> kezd;
		szamok >> veg;
		for (int oszlop = 1; oszlop <= veg; oszlop++)
			(oszlop >= kezd) ? cout << (char)178 : cout << (char)255;
		cout << endl;
	}
	szamok.close();
}

//Fájlból beolvassuk a pálya szerkezetét, a két számpár a telített helyek kezdeteit és végeit jelenti
void palya() {
	ifstream szamok("palya.txt");

	int kezdElso;
	int vegElso;
	int kezdMasodik;
	int vegMasodik;

	while (!szamok.eof()) {
		szamok >> kezdElso;
		szamok >> vegElso;
		szamok >> kezdMasodik;
		szamok >> vegMasodik;
		for (int oszlop = 1; oszlop <= vegElso; oszlop++)
			(oszlop >= kezdElso) ? cout << (char)178 : cout << (char)255;
		for (int oszlop = vegElso+1; oszlop <= vegMasodik; oszlop++)
			(oszlop >= kezdMasodik) ? cout << (char)178 : cout << (char)255;
		cout << endl;
	}
	szamok.close();
}

void palyaOlvas(ifstream& szamok, char** map, int oszlop = 5) {
	int kezdElso;
	int vegElso;
	int kezdMasodik;
	int vegMasodik;

	int sorok = 0;

	while (!szamok.eof()) {
		szamok >> kezdElso;
		szamok >> vegElso;
		szamok >> kezdMasodik;
		szamok >> vegMasodik;
		for (int oszlop = 1; oszlop <= vegElso; oszlop++)
			map[sorok][oszlop - 1] = (oszlop >= kezdElso) ? (char)178 : (char)255;
		for (int oszlop = vegElso + 1; oszlop <= vegMasodik; oszlop++)
			map[sorok][oszlop - 1] = (oszlop >= kezdMasodik) ? (char)178 : (char)255;
		sorok++;
	}
}

void palyaKirajzol(char** map, int sor=3, int oszlop=5) {
	for (int i = 0; i < sor; i++)
	{
		for (int j = 0; j < oszlop; j++)
			cout << map[i][j];
		cout << endl;
	}
}

//Térkép kimentése mátrixba
void palyaMatrixba() {
	ifstream szamok("palya.txt");

	char** map;
	map = new char*[3];//3 sor
	for (int i = 0; i < 3; i++)
		map[i] = new char[5];//5 oszlop

	palyaOlvas(szamok, map);
	palyaKirajzol(map);

	for (int i = 0; i < 3; i++)
		delete [] map[i];
	delete map;
	szamok.close();
}

int main()
{
	//setlocale(LC_ALL, "");
	//muveletiJelek();
	//fajlkezelesesMuveletiJelek();
	//fajlkezelesesMuveletiJelekBeolvasas();
	//piramis();
	palya();
}