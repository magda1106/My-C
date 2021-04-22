#include <iostream>

using namespace std;


struct stos
{
	int liczba;
	stos* next;
};

void dod_stos(int l, stos*& head)// przez referencje bo bd zmieniac wartosc head
{
	stos* pom = new stos;
	pom->liczba = l;
	pom->next = head;
	head = pom;
}
int zdejmij(stos*& head)
{
	stos* pom = new stos;
	pom->liczba = head->liczba;
	head = head->next;

	return pom->liczba;
}




void wypisz(stos* &head)
{
	stos* pom = new stos;
	pom = head;

	for (; pom != NULL;pom=pom->next) {
		cout << pom->liczba << " ";
	}
}

int main()
{
	stos* s1 = new stos;
	s1 = NULL;
	int liczba = 10;
	int system = 2;
	int modulo;
	int j;
	
	while (liczba != 0)
	{
		modulo = liczba % system;
		dod_stos(modulo, s1);
		liczba = liczba / system;
	}
	cout << "Liczba po przeliczeniu:" << endl;
	while (s1 != NULL)
	{
		j = zdejmij(s1);
		cout << " " << j;

	}

	return 0;
}

