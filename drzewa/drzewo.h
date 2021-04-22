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
void delete_node(BTNode*&, BTNode*); //usuwanie ca³ego wez³a
void in_order(BTNode*);// wypisywanie
BTNode* findBST(BTNode*, int);//znajdz wêze³ z danym czasem l¹dowania
BTNode* nextNodeBST(BTNode*);// znajdz wêze³ nastepny
BTNode* miBST(BTNode*);