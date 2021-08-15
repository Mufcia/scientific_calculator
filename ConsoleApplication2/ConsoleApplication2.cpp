#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

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

float count(string expression) {
	char poprawne_znaki[] = { '+', '-', '=', '.', ',', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	return 0.1;
}

int main()
{
	//string expression;
	//cin >> expression;
	int  a1, b1, wybor, wynik = 1;
	float a, b;
	string pomocniczaa, pomocniczab;
	int podziel;

	cout << "1. Dodawanie " << endl << "2. Odejmowanie " << endl;
	cin >> wybor;

	cout << "Wpisz 1 liczbe : "; cin >> pomocniczaa;
	cout << endl;
	cout << "Wpisz 2 liczbe : "; cin >> pomocniczab;
	cout << endl;

	int szczfany1, szczfany2;
	int poka1, poka2, tutej1 = 0, tutej2 = 0, doasm1, doasm2, tylemnoz1, tylemnoz2;

	//floaty do stringstream

	//stringstream do stringa

	//ilość znaków (cyfry + separator) w danej liczbie 
	poka1 = pomocniczaa.length();
	poka2 = pomocniczab.length();
	cout << poka1 << endl;
	cout << poka2 << endl;

	//długość części ułamkowej
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

	pomocniczaa.erase(remove(pomocniczaa.begin(), pomocniczaa.end(), '.'), pomocniczaa.end());
	pomocniczab.erase(remove(pomocniczab.begin(), pomocniczab.end(), '.'), pomocniczab.end());
	pomocniczaa.erase(remove(pomocniczaa.begin(), pomocniczaa.end(), ','), pomocniczaa.end());
	pomocniczab.erase(remove(pomocniczab.begin(), pomocniczab.end(), ','), pomocniczab.end());

	szczfany1 = stoi(pomocniczaa);
	szczfany2 = stoi(pomocniczab);
	cout << szczfany1 << endl;
	cout << szczfany2 << endl;

	//wyrównywanei długości części ułamkowej
	if (tylemnoz1 >= tylemnoz2) {
		podziel = tylemnoz1;
		for (int j = 0; j < tylemnoz1 - tylemnoz2; j++) {
			//szczfany1 *= 10;
			szczfany2 *= 10;
		}
	}
	else
	{
		podziel = tylemnoz2;
		for (int j = 0; j < tylemnoz2 - tylemnoz1; j++) {
			szczfany1 *= 10;
			//szczfany2 *= 10;
		}
	}

	switch (wybor) {
	case 1:
		wynik = dodawanie(szczfany1, szczfany2);
		break;
	case 2:
		wynik = odejmowanie(szczfany1, szczfany2);
		break;
	}
	string swynik = to_string(wynik);
	int poka;
	if (poka1 > poka2)
		poka = poka1;
	else poka = poka2; 
	swynik.insert(poka-podziel-1, ".");

	cout << swynik << endl; 
	return 0;
}