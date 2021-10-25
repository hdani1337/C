#include "pch.h"
#include <math.h>
#include <iostream>

#pragma warning(disable : 4996)

double sum(double a, double b) {
	//Visszaadja a paraméterekben megadott két double összegét, such szum, wow összeg
	return a + b;
}

double sub(double a, double b);//Sima definiálás, így a main már rálát a függvényre

void kiir(double n) {
	//Kiírja a paraméterben átadott kétszeres pontosságú lebegõpontos számot, woooow
	printf("%lf\n", n);
}

double muveletVegzo(double a, double b, char x) {
	//Bekérünk 2 számot és egy mûveleti jelet, elvégezzük a mûveletet és visszaadjuk az eredményt
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

//Különbség függvény késõbbi kifejtése
double sub(double a, double b) {
	return abs(a - b);
}