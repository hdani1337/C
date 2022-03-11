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

	//hozz�val�k mennyis�g�nek �sszegz�se
	for (int sor = 0; sor < 3; sor++)
	{
		liszt += hozzavalok[sor][0];
		so += hozzavalok[sor][1];
		cukor += hozzavalok[sor][2];
		tej += hozzavalok[sor][3];
		tojas += hozzavalok[sor][4];
	}

	//sz�veges ki�r�s
	setlocale(0, "");
	cout << "Az �telek elk�sz�t�s�hez �sszesen " << liszt << " kg lisztre, " << so << " kg s�ra, " << cukor << " kg cukorra, " << tej << " liter tejre �s " << tojas << " darab toj�sra van sz�ks�g.";
}

int main()
{
	ifstream szamok("menu.txt");

	//3x5�s dinamikus helyfoglal�s� t�mb
	double** hozzavalok;
	hozzavalok = new double* [3];
	for (int i = 0; i < 3; i++)
		hozzavalok[i] = new double[5];

	setlocale(0, "");
	
	//hibakezel�s
	if (szamok.is_open()) {
		int sorIndex = 0;
		int oszlopIndex = 0;

		//hozz�val�k neveinek ki�r�sa
		cout << setw(15) << " " << "liszt" << setw(8) << "s�" << setw(12) << "cukor" << setw(10) << "tej" << setw(10) << "toj�s" << endl;
		
		while (!szamok.eof()) {
			//beolvas�s
			string beolvasott;
			szamok >> beolvasott;

			//jobbra igaz�tott ki�r�s
			cout << setw(10) << right << beolvasott.data();

			//dinamikus t�mb felt�lt�se adatokkal
			//az els� oszlopot nem n�zz�k, mert az az �tel neve
			if (oszlopIndex >= 1 && sorIndex < 3) {			
				
				stringstream ss(beolvasott);
				float temp = 0.0;
				ss >> temp;
				hozzavalok[sorIndex][oszlopIndex - 1] = temp;
			}

			//indexek l�ptet�se
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
	else cout << "Nem siker�lt megnyitni a f�jlt!";
}
