#include <iostream>
#include<fstream>
#include<string>

using namespace std;

struct president
{
	string first_name;
	string last_name;
	int year_beginning;
	int year_end;
	int control;
	string party;
};

struct authority 
{
	president inf;
	authority* next;
};

void add(authority*& head, president inf)
{
	authority* add_data = new authority;
	add_data->inf = inf;
	add_data->next = head;
	head = add_data;
}
void show(authority* head)
{
	while (head != NULL)
	{
		cout << "Typo:" << "\t" << head->inf.first_name << " " << head->inf.last_name << "\t" << head->inf.year_beginning << "\t" << head->inf.year_end << "\t" << head->inf.party << "\t" << head->inf.control << endl;
		head = head->next;
	}
}
authority* this_time(authority* head)
{
	authority* pom = new authority;
	authority* lista = NULL;
	president pom1;
	pom = head;
	int min;
	min = head->inf.control;


	while (pom != NULL)
	{
		for (int i = 0; pom != NULL;)
		{
			pom->inf.control = pom->inf.year_end - pom->inf.year_beginning;
			pom = pom->next;
		}
	}
	pom = head;

	for (int i = 0; pom != NULL; i++)
	{
		if (pom->inf.control > min)
		{
			min = pom->inf.control;
		}
		pom = pom->next;
	}
		pom = head;

	while (pom != NULL)
	{
		if (pom->inf.control == min)
		{	
			pom1 = pom->inf;
			add(lista, pom1);
		}
		pom = pom->next; 
	}
	return lista;
}

authority* this_party(authority* head, string party)
{
	president pom1;
	authority* pom2 = NULL;

	while (head != NULL) {
		if (head->inf.party == party) {
			pom1 = head->inf;
			add(pom2, pom1);
		}
		head = head->next;
	}
	return pom2;
}

int main()
{
	authority* presidents = NULL;
	ifstream data("presidents.txt");
	president pom;
	while (!data.eof()) {

		data >> pom.first_name >> pom.last_name >> pom.year_beginning >> pom.year_end >> pom.party;
		add(presidents, pom);
	}
	//1
	cout << "PREZYDENCI O NAJKROTSZYM CZASIE PANOWANIA:" << endl;
	authority* short_time = this_time(presidents);
	cout << endl << endl;
	show(short_time);

	//2
	string party = "Democratic";
	authority* party_member = this_party(presidents, party);
	cout << endl << "PREZYDENCI Z DANEJ PARTII:" << endl;
	show(party_member);
	return 0;

}
