#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int dodawanie(int x, int y) {
	int sum;
	__asm {
		mov eax, x
		mov ebx, y
		add eax, ebx
		mov sum, eax
	}
	return sum;
}

int odejmowanie(int x, int y) {
	int dif;
	__asm {
		mov eax, x
		mov ebx, y
		sub eax, ebx
		mov dif, eax
	}
	return dif;
}

int main()
{
	int  a1, b1, wybor, wynik = 1;
	float a, b;
	int podziel;


	cout << "1. Dodawanie " << endl << "2. Odejmowanie " << endl;
	cin >> wybor;

	cout << "Wpisz 1 liczbe : "; cin >> a;
	cout << endl;
	cout << "Wpisz 2 liczbe : "; cin >> b;
	cout << endl;

	float szczfany1, szczfany2;
	int poka1, poka2, tutej1 = 0, tutej2 = 0, doasm1, doasm2, tylemnoz1, tylemnoz2;
	string pomocniczaa, pomocniczab;
	stringstream sstreama, sstreamb;

	sstreama << a;
	sstreamb << b;

	pomocniczaa = sstreama.str();
	pomocniczab = sstreamb.str();

	poka1 = pomocniczaa.length();
	poka2 = pomocniczab.length();
	cout << poka1 << endl;
	cout << poka2 << endl;

	for (int i = 0; i < poka1; i++) {
		if (pomocniczaa[i] == ',' || pomocniczaa[i] == '.') {
			tutej1 = i;
		}
	}
	tylemnoz1 = poka1 - tutej1 - 1;
	cout << tylemnoz1 << endl;

	for (int i = 0; i < poka2; i++) {
		if (pomocniczab[i] == ',' || pomocniczab[i] == '.') {
			tutej2 = i;
		}
	}
	tylemnoz2 = poka2 - tutej2 - 1;
	cout << tylemnoz2 << endl;

	szczfany1 = a;
	szczfany2 = b;
	cout << szczfany1 << endl;
	cout << szczfany2 << endl;

	if (tylemnoz1 >= tylemnoz2) {
		podziel = tylemnoz1;
		for (int j = 0; j < tylemnoz1; j++) {
			szczfany1 *= 10;
			szczfany2 *= 10;
		}
	}
	else
	{
		podziel = tylemnoz2;
		for (int j = 0; j < tylemnoz2; j++) {
			szczfany1 *= 10;
			szczfany2 *= 10;
		}
	}

	doasm1 = szczfany1;
	doasm2 = szczfany2;
	cout << doasm1 << endl;
	cout << doasm2 << endl;

	switch (wybor) {
	case 1:
		wynik = dodawanie(doasm1, doasm2);
		break;
	case 2:
		wynik = odejmowanie(doasm1, doasm2);
		break;
	}
	float koniec = float(wynik);
	for (int i = 0; i < podziel; i++) {
		koniec /= 10;
	}
	cout << koniec;
	return 0;
}