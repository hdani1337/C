#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

#pragma warning (disable : 4996)

using namespace std;

int jelenlegiEv() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return 1900 + ltm->tm_year;
}

void oregebbMintHarminc(ifstream &kocsik) {
	while (!(kocsik.eof())) {
		string nev = "";
		int kocsiev = 0;
		kocsik >> nev >> kocsiev;
		if (jelenlegiEv() - kocsiev >= 30)
			cout << nev << ", " << (jelenlegiEv() - kocsiev) << " éves" << endl;
	}
}

void hosszabbNevekKiirasa(ifstream &kocsik) {
	while (!(kocsik.eof())) {
		string sor;
		getline(kocsik, sor);
		int ev = stoi(sor.substr(sor.length() - 4, 4));
		if(jelenlegiEv()-ev >= 30)
			cout << sor.substr(0,sor.length()-4) << endl;
	}
}

void feladatok(ifstream& kocsik) {
	//oregebbMintHarminc(kocsik);
	hosszabbNevekKiirasa(kocsik);
}

int main()
{
	setlocale(0, "");
	ifstream kocsik("autok.txt");
	feladatok(kocsik);
	kocsik.close();
}