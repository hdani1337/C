#include "pch.h"
#include <math.h>
#include <iostream>

#pragma warning(disable : 4996)

double sum(double a, double b) {
	//Visszaadja a param�terekben megadott k�t double �sszeg�t, such szum, wow �sszeg
	return a + b;
}

double sub(double a, double b);//Sima defini�l�s, �gy a main m�r r�l�t a f�ggv�nyre

void kiir(double n) {
	//Ki�rja a param�terben �tadott k�tszeres pontoss�g� lebeg�pontos sz�mot, woooow
	printf("%lf\n", n);
}

double muveletVegzo(double a, double b, char x) {
	//Bek�r�nk 2 sz�mot �s egy m�veleti jelet, elv�gezz�k a m�veletet �s visszaadjuk az eredm�nyt
	double answer = 0;
	(x == '+') ? answer = a + b : (x == '-') ? answer = a - b : (x == '*') ? answer = a * b : answer = a / b;
	return answer;
}

int elojel(double a) {
	int ans = 0;
	(a > 0) ? ans = 1 : (a < 0) ? ans = -1 : ans = 0;
	return ans;
}

void elojelKiertekelo(double a) {
	(elojel(a) == 1) ? printf("Pozitiv\n") : (elojel(a) == 0) ? printf("Nulla\n") : printf("Negativ\n");
}

int main()
{
	/*double a = sum(3.141592, 5);
	kiir(a);*/

	/*double a = sub(3.141592, 5);
	kiir(a);*/

	/*double a = muveletVegzo(3.141592, 5, '*');
	kiir(a);*/

	elojelKiertekelo(4);
	elojelKiertekelo(-4);
	elojelKiertekelo(0);
	elojelKiertekelo(4);
	elojelKiertekelo(4);
	elojelKiertekelo(-4);
	elojelKiertekelo(4*0);
}

//K�l�nbs�g f�ggv�ny k�s�bbi kifejt�se
double sub(double a, double b) {
	return abs(a - b);
}