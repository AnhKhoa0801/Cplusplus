#pragma once
#include<iostream>
using namespace std;
struct Node
{
	int Data;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void CreateList(List &l)
{
	l.pHead = l.pTail = NULL;
}

Node* getNode(int x)
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

int SoPtu(List &l)
{
	int n = 0;
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		n++;
	}
	return n;
}
void AddHead(List &l, int x)
{
	Node *p = getNode(x);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(List &l, int x)
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

void Nhap(List &l)
{
	CreateList(l);
	int x;
	do
	{
		cout << "Nhap gia tri: ";
		cin >> x;
		if (x != 0)
		{
			AddTail(l, x);
		}
	} while (x != 0);
}

void Xuat(List l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->Data << " ";
	}
}

void GiaiPhong(List &l)
{
	for (Node *p = l.pHead; p != NULL; )
	{
		l.pHead = l.pHead->pNext;
		delete p;
		p = l.pHead;
	}
}

int TimKiem(List &l,int x)
{
	int n = SoPtu(l);
	Node *p = l.pHead;
	for (int i = 0; i < n; i++)
	{
		if (p->Data == x)
		{
			return i;
		}
		p = p->pNext;
	}
	return -1;
}

// Xóa vi tri
void Xoa1(List &l, int vitrixoa)	
{
	Node *p = l.pHead;
	if (vitrixoa == 0)
	{
		l.pHead = l.pHead->pNext;
		delete p;
		return;
	}
	for (int j = 0; j < vitrixoa - 1; j++)
	{
		p = p->pNext;
	}
	Node *q = p;
	p = p->pNext;
	q->pNext = p->pNext;
	delete p;
}

// Xóa phần tử 
void Xoa2(List &l, int phantuxoa)
{
	int vitrixoa = TimKiem(l, phantuxoa);
	Xoa1(l, vitrixoa);
}
void Xoa(List &l)
{
	int n = SoPtu(l);
	int i, Luachon;
	do
	{
		cout << "Nhap lua chon (1:Xoa vi tri/2:Xoa gia tri): ";
		cin >> Luachon;
		if (!(Luachon >= 1 && Luachon <= 2))
		{
			cout << "Loi! Xin kiem tra lai! " << endl;
		}
	} while (!(Luachon >= 1 && Luachon <= 2));
	if (Luachon == 1)
	{
	Anhkhoa1:
		cout << "Xoa phan tu thu: ";
		cin >> i;
		if (i<0 || i>n - 1)
		{
			cout << "Loi! Xin kiem ta lai! " << endl;
			goto Anhkhoa1;
		}
		Xoa1(l, i);
	}
	else
	{
	Anhkhoa2:
		int GiaTri;
		cout << "Gia tri can xoa:";
		cin >> GiaTri;
		if (i == -1)
		{
			cout << "Loi! Khong tiem thay gia tri can xoa! " << endl;
			goto Anhkhoa2;
		}
		Xoa2(l,GiaTri);
	}
}
