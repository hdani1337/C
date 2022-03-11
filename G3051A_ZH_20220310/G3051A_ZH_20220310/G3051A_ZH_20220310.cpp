#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

void bevasarloLista(double** hozzavalok) {
	double liszt = 0.0;
	double so = 0.0;
	double cukor = 0.0;
	int tej = 0;
	int tojas = 0;

	//hozzávalók mennyiségének összegzése
	for (int sor = 0; sor < 3; sor++)
	{
		liszt += hozzavalok[sor][0];
		so += hozzavalok[sor][1];
		cukor += hozzavalok[sor][2];
		tej += hozzavalok[sor][3];
		tojas += hozzavalok[sor][4];
	}

	//szöveges kiírás
	setlocale(0, "");
	cout << "Az ételek elkészítéséhez összesen " << liszt << " kg lisztre, " << so << " kg sóra, " << cukor << " kg cukorra, " << tej << " liter tejre és " << tojas << " darab tojásra van szükség.";
}

int main()
{
	ifstream szamok("menu.txt");

	//3x5ös dinamikus helyfoglalású tömb
	double** hozzavalok;
	hozzavalok = new double* [3];
	for (int i = 0; i < 3; i++)
		hozzavalok[i] = new double[5];

	setlocale(0, "");
	
	//hibakezelés
	if (szamok.is_open()) {
		int sorIndex = 0;
		int oszlopIndex = 0;

		//hozzávalók neveinek kiírása
		cout << setw(15) << " " << "liszt" << setw(8) << "só" << setw(12) << "cukor" << setw(10) << "tej" << setw(10) << "tojás" << endl;
		
		while (!szamok.eof()) {
			//beolvasás
			string beolvasott;
			szamok >> beolvasott;

			//jobbra igazított kiírás
			cout << setw(10) << right << beolvasott.data();

			//dinamikus tömb feltöltése adatokkal
			//az elsõ oszlopot nem nézzük, mert az az étel neve
			if (oszlopIndex >= 1 && sorIndex < 3) {			
				
				stringstream ss(beolvasott);
				float temp = 0.0;
				ss >> temp;
				hozzavalok[sorIndex][oszlopIndex - 1] = temp;
			}

			//indexek léptetése
			oszlopIndex++;	
			if (oszlopIndex > 5) {
				cout << endl;
				oszlopIndex = 0;
				sorIndex++;
			}
		}
		cout << endl;
		bevasarloLista(hozzavalok);
		szamok.close();
	}
	else cout << "Nem sikerült megnyitni a fájlt!";
}
