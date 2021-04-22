#include <iostream>
#include"drzewo.h"
#include<ctime>

using namespace std;

void in_order(BTNode* k) {

	if (k) {
		in_order(k->left);
		cout <<" "<< k->flight_time;
		in_order(k->right);
	}
}
void insert_plane(BTNode*& root, int flight_time )
{
	BTNode* pom;
	BTNode* nodeToAdd = new BTNode;
	nodeToAdd->flight_time =flight_time;
	nodeToAdd->left = NULL;
	nodeToAdd->right = NULL;
	nodeToAdd->parent = NULL;

	if (root == NULL)
	{
		root = nodeToAdd;
	}
	else
	{
		pom = root;
		while (1)
		{
			if (nodeToAdd->flight_time < pom->flight_time)
				if (pom->left == NULL)
				{
					pom->left = nodeToAdd;
					break;
				}
				else
					pom = pom->left;
			else
			{
				if (pom->right == NULL)
				{
					pom->right = nodeToAdd;
					break;
				}
				else
					pom = pom->right;
			}
		}
		nodeToAdd->parent = pom;
	}
}
BTNode* findBST(BTNode* root, int t) 
{

	if (root == NULL) {
		return NULL;
	}

	BTNode* pom = root;
	while (pom && (pom->flight_time != t))
	{
		if (pom->flight_time< t) 
			pom = pom->right;
		else pom = pom->left;
	}
	return pom;
}
BTNode* minBST(BTNode* root)
{
	BTNode* pom = root;
	if (pom)
		while (pom->left) pom = pom->left;
	return pom;
}
BTNode* nextNodeBST(BTNode* p)
{
	BTNode* pom;

	if (p != NULL)
		if (p->right) return minBST(p->right);
		else
		{
			pom = p->parent;
			while (pom && pom->right == p)
			{
				p = pom;
				pom = pom->parent;
			}
			return pom;
		}
	return p;
}
void delete_node(BTNode*& root, BTNode* usun) {

	BTNode* pom = NULL;

	//lisc
	if (usun->left == NULL && usun->right == NULL) 
	{
		pom = usun->parent;
		if (pom->left == usun) pom->left = NULL;
		else pom->right = NULL;
	}

	//1 dziecko
	else if (usun->left == NULL || usun->right == NULL)
	{
		if (usun->left == NULL) pom = usun->right;
		else pom = usun->left;
		usun->flight_time = pom->flight_time;
		usun->left = pom->left;
		usun->right = pom->right;
	}

	//2dzieci
	else
	{
		pom = next(usun);
		usun->flight_time = pom->flight_time;
		usun->right = pom->right;
		usun->left = pom->left;
		pom = pom->right;
	}
	delete pom;

}