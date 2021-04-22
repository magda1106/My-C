#include "pracownicy.h"
#include <iostream>
using namespace std;

Pracownik::Pracownik() {
	this->id = 1;
	this->imie = "JAN";
	this->nazwisko = "KOWALSKI";
	this->zawod = "-";
	this->zarobki = stawka;
}
Pracownik::Pracownik(int id, string imie, string nazwisko) {
	this->id = id;
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->zawod = "-";
	this->zarobki = stawka;

}
Pracownik::~Pracownik()
{
	cout << "Usuwanie obiektu" << endl;
}
ostream& operator<<(ostream& wyjscie, Pracownik& pracownik)
{
	cout << "DANE PRACOWNIKA: " << pracownik.id << "\t" << pracownik.imie << " " << pracownik.nazwisko << endl;
	cout << "ZAWOD : " << pracownik.zawod << endl;
	cout << "PENSJA :" << pracownik.zarobki << endl;
	return wyjscie;
}
Kierownik::Kierownik(int id, string imie, string nazwisko)
{
	this->id = id;
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->zawod = "Kierownik";
	this->zarobki = 5 * stawka;
}
IT::IT() {
	this->id = 2;
	this->imie = "Czeslaw";
	this->nazwisko = "Bar";
	this->zawod = "Informatyk";
	this->zarobki = 3.5 * stawka;
}
IT::IT(const IT& it)
{
	this->id = it.id;
	this->imie = it.imie;
	this->nazwisko = it.nazwisko;
	this->zawod = it.zawod;
	this->zarobki = it.zarobki;
}