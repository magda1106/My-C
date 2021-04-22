#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void quicksort(int* tab, int lewy, int prawy)
{
	int i, j;
	int v = (lewy + prawy) / 2;
	int pivot = tab[v];
	i = lewy;
	j = prawy;
	while (i <= j)
	{
		while (tab[i] < pivot) i++;
		while (tab[j] > pivot) j--;
		if (i <= j)
		{
			swap(tab[i], tab[j]);
			i++;
			j--;
		}
	}
	if (lewy < j)
		quicksort(tab, lewy, j);
	if (i < prawy)
		quicksort(tab, i, prawy);

}
int main()
{
	srand(time(NULL));
	 const int paczka = 10;
	int tablica_paczek[paczka];
	int dzieci;
	
	int l_dzieci = 5;
	for (int i = 0; i < paczka; i++)
	{
		tablica_paczek[i] = rand() % 20 + 1;

	}
	cout << "Posortowane paczki" << endl;
	quicksort(tablica_paczek, 0, paczka - 1);
	for (int i = 0; i < paczka; i++)
	{
		cout << tablica_paczek[i];
		cout << endl;
	}
	cout << "Ile jest dzieci? " << endl;
	cin >>dzieci;
	cout << endl;
	if (dzieci > paczka)
	{
		return 0;
	}
	if (dzieci <= paczka)
	{
		int v = paczka - dzieci;
		int i = 1;
		int j = v/2;
		while (i <= dzieci)
		{
			cout << "Dziecko" << " " <<i<<" "<<"dostanie"<<" "<<tablica_paczek[j]<< endl;
			i++;
			j++;
		}

	}




	









	return 0;
}