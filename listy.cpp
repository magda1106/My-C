#include<iostream>
#include<string>

using namespace std;

struct train 
{
	string name;
	string arrival;
	string departure;
	train* next;// wska¿nik na nastêpny element
};



void show(train* head)//wypisz cala trase
{
	train* pom = new train;
	pom = head;
	while (pom != NULL)
	{
		cout <<"NAZWA POCIAGU:"<<" "<< pom->name << " "  << "PRZYJAZD:" << pom->arrival << " " << "ODJAZD:" << pom->departure << endl;
		pom = pom->next;
	}
}
void show_from_to(train* head, string n)// wypisz od danego przystanku
{
	train* pom = new train;
	pom = head;
//////
	if (head== NULL)
	{
		cout << "TRASA PUSTA" << endl;
		
	}
	else 
	{
		for (int i = 0; pom != NULL; i++)
		{
			if (pom->name == n) break;
			else
				pom = pom->next;
		}
	}

	while (pom != NULL)
	{
		cout << "NAZWA POCIAGU:" << " " << pom->name << " " << "PRZYJAZD:" << pom->arrival << " " << "ODJAZD:" << pom->departure << endl;
	
		pom = pom->next;
	}
}

void add_stop(train* head, string right_name, string name, string a, string d)// dodawanie przystanku 
{
	train* pom = new train;
	train*nowy= new train;

	nowy->name = name;
	nowy->arrival = a;
	nowy->departure = d;
	nowy->next = NULL;

	if (head==NULL)//dodaje na poczatek lsity
	{
		head->name = name;
		head->arrival = a;
		head->departure = d;
		head->next=NULL;
		return;
   }

	pom = head;

	for (int i = 0; pom->next != NULL; i++)///dodaje w srodku listy
	{
		if (pom->name== right_name)
		{
			nowy->next = pom->next;
			pom->next = nowy;
			return;
		}
		pom = pom->next;

	}
	if (pom->next == NULL)//dod na ostani element listy
	{
		if (pom->name == right_name)
		{
			nowy->next = pom->next;
			pom->next = nowy;
			
		}
	}

}
void delete_stop(train*& head, string right_name)// usuwanie przystanku
{
	train* pom = new train;
	train* pom2 = new train;
	pom2= head;
	pom = head->next;

	if (head == NULL)///// usuwanie z pocz¹tku(g³owy)
	{
		cout << "PUSTA TRASA" << endl;
	}
	else
	{
		if (head->name == right_name)
		{
			head = head->next;
			return;
		}
		
	}
	for (int i = 0; pom->next != NULL; i++)//// usuwnaie z œrodka listy
	{
		if (pom->name==right_name)
		{
			pom2->next = pom->next;
			return;	
		}
		pom2 = pom2->next;
		pom = pom->next;
	}
	if (pom->next == NULL)/// usuwanie konca listy(ogona)
	{
		pom2->next = pom->next;
		return;
	}
	cout << "BRAK ELEMENTU" << endl;
}
//////////// edycja przystanku(zmiana czassu/nazwy)/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void edit_time(train* head, string name, string new_a, string new_d)// edycja czasu wybranego przystanku
{
	train* pom = new train;
	pom = head;

	if (head == NULL)
		return;
	else
	{
		for (int i = 0; pom != NULL; i++)
		{
			if (pom->name == name)
			{
				pom->arrival = new_a;
				pom->departure = new_d;
				return;
			}
			else
				pom = pom->next;
		}
	}
	cout << "TAKI PRZSTANEK NIE ISTNIEJE" << endl;
}
void edit_place(train* head, string n, string new_n)// edycja nazwy/miesjca wyranego przystanku
{
	train* pom = new train;
	pom = head;
	if (head == NULL)
		return;
	else
	{
		for (int i = 0; pom != NULL; i++)
		{
			if (pom->name == n)

			{
				pom->name = new_n;
				return;
			}
			else
				pom = pom->next;
		}
	}

	cout << "TAKI PRZSTANEK NIE ISTNIEJE" << endl;
}
int main()
{
	train* head = new train;
	head->name ="Kielce";
	head->arrival = "STARTUJE";
	head->departure = "12:12";
	head->next =NULL;

	train* p1 = new train;
	head->next = p1;
	p1->name = "Jedrzejow";
	p1->arrival = "13:08";
	p1->departure = "13:13";
	p1->next =NULL;


	train* p2 = new train;
	p1->next = p2;
	p2->name = "Miechow";
	p2->arrival = "13:45";
	p2->departure = "13:56";
	p2->next = NULL;

	train* cel = new train;
	p2->next = cel;
	cel->name = "Krakow";
	cel->arrival = "14:52";
	cel->departure = "STOP";
	cel->next = NULL;

	

	cout << "TRASA:" << endl;
	cout << endl;
	show(head);
	cout << endl;

	cout << "TRASA OD JEDRZEJOWA:" << endl;
	cout << endl;
	show_from_to(head, "Jedrzejow");


	edit_place(head, "Krakow", "   Krakow/Plaszow");
	

	edit_time(head, "Jedrzejow", "13:13", " 13:31");
	





	add_stop(head, "Kielce", " Busko-Zdroj", "12:23", "12:32");
	delete_stop(head, "Miechow");


	cout << endl;
	cout << "ZMIANA ROZKLADU JAZDY POCIAGU" << endl;
	
	show(head);



















	return 0;
}