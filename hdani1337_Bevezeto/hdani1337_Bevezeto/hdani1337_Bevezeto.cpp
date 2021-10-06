#include "pch.h"
#include <stdio.h>
#include <math.h>

#pragma warning(disable : 4996) //<-- C-be kell

void masodfoku() {
	//Másodfokú megoldóképlet
	double a, b, c;

	printf("Adja meg az a erteket: ");
	scanf("%lf", &a);

	printf("Adja meg az b erteket: ");
	scanf("%lf", &b);

	printf("Adja meg az c erteket: ");
	scanf("%lf", &c);

	double d = (b*b) - 4 * a*c;
	printf("A diszkriminans erteke: %lf\n", d);

	if (d >= 0) {
		double x1 = (-b + sqrt(d)) / (2 * a);
		double x2 = (-b - sqrt(d)) / (2 * a);

		if (x1 == x2) printf("x: %lf", x1);
		else {
			printf("x1: %lf\n", x1);
			printf("x2: %lf\n", x2);
		}
	}
	else printf("Nincs valos megoldas!\n");
}

void ciklusokPelda() {
	//Ciklusok

	//Elõltesztelõs ciklus
	printf("Eloltesztelos ciklus\n");
	int i = 1;
	while (i <= 10)
	{
		printf("%d\n", i);
		i++;
	}

	printf("\n");

	//Hátultesztelõs ciklus
	printf("Hatultesztelos ciklus\n");
	i = 1;
	do
	{
		printf("%d\n", i);
		i++;
	} while (i<=10);

	printf("\n");

	//Számlálásos ciklus
	printf("Szamlalasos ciklus\n");
	for (int i = 1; i <= 10; i++)
		printf("%d\n", i);
}

void harmasaval() {
	//Számok kiírása 1-tõl 10-ig 3-asával
	//Elõltesztelõs ciklus
	printf("Eloltesztelos ciklus\n");
	int i = 1;
	while (i<=10)
	{
		printf("%d\n", i);
		i+=3;
	}

	printf("\n");

	//Hátultesztelõs ciklus
	printf("Hatultesztelos ciklus\n");
	i = 1;
	do
	{
		printf("%d\n", i);
		i+=3;
	} while (i <= 10);

	printf("\n");

	//Számlálásos ciklus
	printf("Szamlalasos ciklus\n");
	for (int i = 1; i <= 10; i+=3)
		printf("%d\n", i);
}

void parosSzamok() {
	//Páros számok kiírása 0-tól a felhasználó által megadott határértékig
	int max = 0;

	printf("Adjon meg egy felso hatarerteket: ");
	scanf("%d", &max);

	for (int i = 0; i <= max; i += 2)
		printf("%d\n", i);
}

void kicsiVagyNagy() {
	//Megmondja, hogy az adott karakter kisbetû, nagybetû vagy egyik sem
	char a;

	printf("Adjon meg egy karaktert: ");
	scanf("%c", &a);

	(a >= 'a' && a <= 'z') ? printf("Kicsi") : (a >= 'A' && a <= 'Z') ? printf("Nagy") : printf("Egyik sem");
}

void kicsiVagyNagyCiklusban() {
	//Megmondja, hogy az adott karakter kisbetû, nagybetû vagy egyik sem, 10-szer
	for (int i = 0; i < 10; i++)
	{
		char a;

		printf("Adjon meg egy karaktert: ");
		scanf(" %c", &a);//Szóköz a % elé, billentyûzet puffer bug miatt

		(a >= 'a' && a <= 'z') ? printf("Kicsi") : (a >= 'A' && a <= 'Z') ? printf("Nagy") : printf("Egyik sem");

		printf("\n");

	}
}

void jelszoEllenorzo() {
	//Minimum 8 karakternek, egy kisbetûnek, egy nagybetûnek, egy számnak kell lennie a jelszóban
	int counter = 0, kisb = 0, nagyb = 0, szam = 0;
	char a = ' ';
	while (a!=10) {
		scanf("%c", &a);
		counter++;
		(a >= 'a' && a <= 'z') ? kisb = 1 : (a >= 'A' && a <= 'Z') ? nagyb = 1 : (a >= '0' && a <= '9') ? szam = 1 : counter = counter;
	}
	(counter > 8 && kisb == 1 && nagyb == 1 && szam == 1) ? printf("Eros jelszó!") : printf("Gyenge jelszo!");
}

void pinkodEllenorzo() {
	//Minimum 4 karakter, 3 próba
	int pin = 1234;
	int bePin = 0000;
	int probaSzam = 0;
	while (probaSzam < 3)
	{
		probaSzam++;
		printf("Adjon meg a PIN-kodjat: ");
		scanf("%d", &bePin);
		if (bePin == pin) {
			probaSzam = 9;
			break;
		}
		else (3-probaSzam==0) ? printf("A megadott kod helytelen! Nincs tobb kiserlet."): printf("A megadott kod helytelen! %d kiserlet maradt.", (3-probaSzam));
	}
	(probaSzam == 9) ? printf("\nBelepes engedelyezve!") : printf("\nA rendszer lezart!");
}

void euklidesz() {
	//Két szám legnagyobb közös osztóját számolja ki
	int a = 0;
	int b = 0;
	int m = -1;

	printf("Adjon meg az elso szamot: ");
	scanf("%d", &a);

	printf("Adjon meg az masodik szamot: ");
	scanf("%d", &b);

	while (m != 0) {
		m = a % b;
		if (m != 0) {
			a = b;
			b = m;
		}
	}

	printf("A ket szam legnagyobb kozos osztoja: %d", b);
}

void osszegzo(int n) {
	//Összeadja a felhasználó által megadott számokat
	//@param n: ennyi számot kér be a program
	int sum = 0;
	int temp = 0;
	for  (int i = 0; i < n; i++)
	{
		printf("Adjon meg egy szamot (%d darab kell meg): ",(n-i));
		scanf("%d", &temp);
		sum += temp;
	}
	printf("A szamok osszege: %d", sum);
}

void minimumKivalaszto(int n) {
	//Meghatározza a legkisebb számot a felhasználó által megadottak közül
	//@param n: ennyi számot kér be a program
	int min = 0;
	int temp = 0;
	printf("Adjon meg egy szamot (%d darab kell meg): ", n);
	scanf("%d", &min);
	for (int i = 1; i < n; i++)
	{
		printf("Adjon meg egy szamot (%d darab kell meg): ", (n - i));
		scanf("%d", &temp);
		if (temp < min) min = temp;
	}
	printf("A legkisebb szam: %d", min);
}

void anyagszuksegletSzamolo() {
	//Anyagszükséglet számoló
	//Bekérjük a felületet, és a dobozonkénti négyzetmétert
	//Kiírjuk, hogy hány doboz csempét kell venni 10% hulladékkal számolva
	double area = 0.0;
	double packageContent = 0.0;
	int doboz = 0;
	
	printf("Adja meg a szoba teruletet: ");
	scanf("%lf", &area);

	printf("Adja meg a dobozonkenti mennyiseget: ");
	scanf("%lf", &packageContent);

	area *= 1.1f;//10% hulladék

	doboz = ceil(area / packageContent);//ceil() függvény mindig felfele kerekít

	printf("%d doboz csempere van szuksegunk.", doboz);
}

void hitelKalkulatorAlpha() {
	//Tõke és futamidõ
	int toke = 0;
	int futamido = 0;

	printf("Adja meg a toket: ");
	scanf("%d", &toke);

	printf("Adja meg a futamidot honapokban: ");
	scanf("%d", &futamido);

	int torlesztoReszlet = toke / futamido;

	printf("%d forint a havi torlesztoreszletunk.", torlesztoReszlet);
}

void hitelKalkulatorSigma() {
	//Tõke, éves kamat, futamidõ (év)
	//Minden év végén kamatszámítás
	//törlesztõ = aktuális tõke / 12

	double toke = 0;
	int futamido = 0;
	int futamidoTemp = 0;
	double torleszto = 0.0;
	double kamat = 0.0;

	printf("Adja meg a toket: ");
	scanf("%lf", &toke);

	printf("Adja meg a futamidot honapokban: ");
	scanf("%d", &futamido);

	printf("Adja meg a kamatot szazalekban: ");
	scanf("%lf", &kamat);

	futamidoTemp = futamido;

	for (int i = 0; i < futamido/12; i++)
	{
		torleszto = toke / futamidoTemp;//havi törlesztõrészlet
		printf("%d. evi havi torlesztoreszlet: %lf\n", i+1, torleszto);
		toke -= torleszto * 12;//befizetett számlák levonása a tartozásból
		toke *= (1 + (kamat/100.0f));//éves kamat
		futamidoTemp -= 12;//csökken a hátramaradt hónapok száma
	}
}

void muveletVegzo() {
	//Bekérünk 2 számot és egy mûveleti jelet, elvégezzük a mûveletet és kiírjuk
	double a = 0;
	double b = 0;
	char x = 'N';

	printf("Adja meg az elso szamot: ");
	scanf("%lf", &a);

	printf("Adja meg a muveleti jelet: ");
	scanf(" %c", &x);

	printf("Adja meg a masodik szamot: ");
	scanf("%lf", &b);

	switch (x)
	{
		case '+':
			printf("%.lf + %.lf = %.1lf", a, b, a + b);
			break;

		case '-':
			printf("%.lf - %.lf = %.1lf", a, b, a - b);
			break;

		case '*':
			printf("%.lf * %.lf = %.1lf", a, b, a*b);
			break;

		case '/':
			printf("%.lf / %.lf = %.1lf", a, b, a / b);
			break;

		default:
			printf("Hibas muveleti jel!");
	}
}

void menu() {
	//Egyszerû menürendszer
	printf("1. menupont\n");
	printf("2. menupont\n");
	printf("3. Kilepes\n");

	int input = 0;
	int kilepes = -1;

	while (kilepes == -1) {
		printf("Adjon meg egy menupontot: ");
		scanf("%d", &input);

		switch (input)
		{
		case 1: printf("1.es menupont kivalasztva\n"); break;
		case 2: printf("2.es menupont kivalasztva\n"); break;
		case 3: kilepes = 1; break;
		default: printf("Hibas menupont"); break;
		}
	}
}

int main()
{
	//masodfoku();
	//ciklusokPelda();
	//harmasaval();
	//parosSzamok();
	//kicsiVagyNagy();
	//kicsiVagyNagyCiklusban();
	//jelszoEllenorzo();
	//pinkodEllenorzo();
	//euklidesz();
	//osszegzo(5);
	//minimumKivalaszto(5);
	//anyagszuksegletSzamolo();
	//hitelKalkulatorSigma();
	//muveletVegzo();
	menu();
	return 0;
}