#pragma once
#include"SinhVien.h"

// Node sinh viên
struct Node
{
	CSinhVien Data;
	Node *pNext;
};

// Danh sách sinh viên
struct List
{
	Node *pHead;
	Node *pTail;
};

void CreateList(List &l)
{
	l.pHead = l.pTail = NULL;
}

Node* getNode(CSinhVien x)
{
	Node *p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->Data = x;
	p->pNext = NULL;
	return p;
}

void AddTail(List &l, CSinhVien x)
{
	Node *p = getNode(x);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// Tìm kiếm mã SV trong DSLK nếu có trả về true
Node* TimKiem(List l,int x)
{
	for (Node *p = l.pHead; p; p = p->pNext)
	{
		if (p->Data.Get_MaSV() == x)
		{
			return p;
		}
	}
	return NULL;
}