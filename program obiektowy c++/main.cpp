#include "pracownicy.h"
#include <iostream>

using namespace std;

int main()
{
	int id;
	string imie;
	string nazwisko;
	cout << "Wprowadz dane pracownika" << endl;
	cout << "ID: ";
	cin >> id;
	cout << "IMIE: ";
	cin >> imie;
	cout << "NAZWISKO:";
	cin >> nazwisko;

	Pracownik pr1(id, imie, nazwisko);
	Pracownik pr2;
	cout << endl;
	cout << pr1 << pr2;

	IT it1;
	IT it2(it1);
	cout << it1 << endl;
	cout << it2 << endl;

	Kierownik kr1(13, "Stefan", "Karp");
	cout << kr1 << endl;

	cout << endl;
	Pracownik zespol[3] = { pr1,it1,kr1 };
	for (int i = 0; i < 3; i++)
	{
		cout << zespol[i];
	}

		




















	return 0;
}