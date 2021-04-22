#pragma once
#include <iostream>
using namespace std;

struct BTNode {

	BTNode* parent;
	BTNode* left;
	BTNode* right;
	int flight_time;
};
void insert_plane(BTNode*&, int); //dod samolotu
void delete_node(BTNode*&, BTNode*); //usuwanie ca�ego wez�a
void in_order(BTNode*);// wypisywanie
BTNode* findBST(BTNode*, int);//znajdz w�ze� z danym czasem l�dowania
BTNode* nextNodeBST(BTNode*);// znajdz w�ze� nastepny
BTNode* miBST(BTNode*);