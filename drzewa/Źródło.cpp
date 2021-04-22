
#include<iostream>
#include<ctime>
#include"drzewo.h"
#include<cstdlib>


using namespace std;

int main()
{
	BTNode* airport = NULL;;
	int plane_time;
	int actual_time;
	BTNode* pom = NULL;
	srand(time(NULL));
	actual_time = rand() % 10 + 10;

	
	 while (1)
	 {
		 cout << "Aktualny czas:" << endl << actual_time << endl;
		 cout << "Loty:" << endl;
		 in_order(airport);
		 cout <<endl<< "O ktorej chcesz wyladowac??" << endl;
		 cin >> plane_time;
		 if (plane_time >actual_time)
		 {
			 for (int i = plane_time - 3; i < plane_time + 3; i++)
			 {
				 
				 pom = findBST(airport, i);
				 if (pom != NULL)
				 {
					 cout << "Nie masz zgody na ladowanie!" << endl;
					 break;
				 } 
			}

			 if (pom == NULL)
			 {
				 insert_plane(airport, plane_time);
			 }
		 }
		 else
			 cout << "Nieaktualne!" << endl;

		 actual_time = actual_time + rand() % 5 + 1;
	 }

	return 0;
}