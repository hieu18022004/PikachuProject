#include <iostream>
#include "Funcs.h"
#include <stdio.h>
#include <Windows.h>
using namespace std;

Node* nodeCreate(int x, int y)
{
	Node* pNew = new Node;
	pNew->n.X = x;
	pNew->n.Y = y;
	pNew->pNext = NULL;
	return pNew;
}

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

bool emptyCheck(List list)
{
	if (list.pHead == NULL)
	{
		return true;
	}
	return false;
}

void headPush(List& list, int x, int y)
{
	if (list.pHead == NULL)
	{
		list.pHead = nodeCreate(x, y);
		return;
	}
	Node* pCur = nodeCreate(x,y);
	pCur->pNext = list.pHead;
	list.pHead = pCur;
}

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