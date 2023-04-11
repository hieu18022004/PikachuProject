#include "Functions.h"
using namespace std;
//create a node
Node* nodeCreate(int x, int y)
{
	Node* pNew = new Node;
	pNew->n.X = x;
	pNew->n.Y = y;
	pNew->pNext = NULL;
	return pNew;
}
//get the size of a list
int getSize(List list)
{
	if (emptyCheck(list))
	{
		return 0;
	}
	int n = 0;
	Node* pCur = list.pHead;
	while (pCur->pNext != NULL)
	{
		pCur = pCur->pNext;
		n++;
	}
	return n;
}
//remove list
void removeAll(List& list)
{
	if (list.pHead == NULL)
	{
		return;
	}
	if (list.pHead->pNext == NULL)
	{
		delete list.pHead;
		list.pHead = NULL;
		return;
	}
	Node* pPrev = list.pHead;
	Node* pCurrent = list.pHead;
	while (pPrev != NULL)
	{
		pCurrent = pCurrent->pNext;
		pPrev->pNext = NULL;
		delete pPrev;
		pPrev = pCurrent;
	}
	list.pHead = NULL;
}
//check if the list is empty
bool emptyCheck(List list)
{
	if (list.pHead == NULL)
	{
		return true;
	}
	return false;
}
//push to the head of a linked list
void headPush(List& list, int x, int y)
{
	if (list.pHead == NULL)
	{
		list.pHead = nodeCreate(x, y);
		return;
	}
	Node* pCur = list.pHead;
	Node* pNew = nodeCreate(x,y);
	pNew->pNext = pCur;
	list.pHead = pNew;
	return;
}
//push to the tail
void tailPush(List& list, int x, int y)
{
	if (list.pHead == NULL)
	{
		list.pHead = nodeCreate(x, y);
		return;
	}
	Node* pCur = list.pHead;
	while (pCur->pNext != NULL)
		pCur = pCur->pNext;
	pCur->pNext = nodeCreate(x, y);
}
//pop the head of teh linked list
COORD headPop(List& list)
{
	COORD data;
	if (list.pHead == NULL)
	{
		data.X = -1;
		data.Y = -1;
		return data;
	}
	Node* pCur = list.pHead;
	data.X = pCur->n.X;
	data.Y = pCur->n.Y;
	pCur = pCur->pNext;
	delete list.pHead;
	list.pHead = pCur;
	return data;
}
//get the head of a linked list
COORD headGet(List list)
{
	COORD data;
	if (list.pHead == NULL)
	{
		data.X = -1;
		data.Y = -1;
		return data;
	}
	Node* pCur = list.pHead;
	data.X = pCur->n.X;
	data.Y = pCur->n.Y;
	return data;
}
//get the tail of a linked list
COORD tailGet(List list)
{
	COORD data;
	if (list.pHead == NULL)
	{
		data.X = -1;
		data.Y = -1;
		return data;
	}
	Node* pCur = list.pHead;
	while (pCur->pNext != NULL)
	{
		pCur = pCur->pNext;
	}
	data.X = pCur->n.X;
	data.Y = pCur->n.Y;
	return data;
}