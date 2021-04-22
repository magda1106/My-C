#ifndef PRACOWNICY_H
#define PRACOWNICY_H
#include<iostream>
#include <string>
using namespace std;
class Pracownik{
	friend ostream& operator<<(ostream&, Pracownik&);

protected:
	int id;
	static int licznik;
	string imie;
	string nazwisko;
	string zawod;
	const float stawka=10;
	float zarobki;
public:
	Pracownik();
	Pracownik(int, string, string);
	~Pracownik();
};
ostream& operator<<(ostream&, Pracownik&);

class Kierownik : public Pracownik {
public:
	Kierownik(int, string, string);
};
class IT : public Pracownik {
public:
	IT();
	IT(const IT&);

};

#endif