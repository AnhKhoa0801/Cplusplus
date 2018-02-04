#pragma once
#include<iostream>
using namespace std;

class SoHang
{
public:
	SoHang();
	friend istream& operator>>(istream&, SoHang&);
	friend ostream& operator<<(ostream&, SoHang);
	SoHang& operator=(const SoHang&);
	friend SoHang& operator+(SoHang, SoHang);
	friend SoHang& operator*(SoHang, SoHang);
	int getter_HeSo();
	int getter_SoMu();
	~SoHang();
private:
	int HeSo;
	int SoMu;
};

SoHang::SoHang()
{
	HeSo = 0;
	SoMu = 0;
}

int SoHang::getter_HeSo()
{
	return HeSo;
}


int SoHang::getter_SoMu()
{
	return SoMu;
}

istream& operator>> (istream& is, SoHang &x)
{
	cout << "Nhap he so:";
	is >> x.HeSo;
	cout << "Nhap so mu: ";
	is >> x.SoMu;
	return is;
}

ostream& operator<< (ostream& os, SoHang x)
{
	os << x.HeSo << "X^(" << x.SoMu << ")";
	return os;
}

SoHang& SoHang::operator=(const SoHang &x)
{
	this->HeSo = x.HeSo;
	this->SoMu = x.SoMu;
	return *this;
}

SoHang& operator+(SoHang x1,SoHang x2)
{
	SoHang Temp;
	Temp.HeSo = x1.HeSo + x2.HeSo;
	Temp.SoMu = x1.SoMu;
	return Temp;
}

SoHang& operator*(SoHang x1, SoHang x2)
{
	SoHang Temp;
	Temp.HeSo = x1.HeSo*x2.HeSo;
	Temp.SoMu = x1.SoMu + x2.SoMu;
	return Temp;
}

SoHang::~SoHang()
{
}

struct Node
{
	SoHang Data;
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

Node* getNode(SoHang x)
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

void AddHead(List &l, SoHang x)
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
void AddTail(List &l,SoHang x)
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
	SoHang x;
	int Check;
	do
	{
		cout << "Nhap lua chon (1: Nhap/0:Thoat)";
		cin >> Check;
		if (Check == 1)
		{
			cin >> x;
			if (x.getter_HeSo() == 0)
			{
				continue;
			}
			AddTail(l, x);
		}
		else 
		{
			if (Check != 0)
			{
				cout << "Loi! Xin kiem tra lai!" << endl;
			}
		}

	} while (Check != 0);
}

void Xuat(List l)
{
	cout << l.pHead->Data;
	for (Node*p = l.pHead->pNext; p != NULL; p = p->pNext)
	{
		if (p->Data.getter_HeSo() > 0)
		{
			cout << "+";
		}
		cout << p->Data;
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

void SapXep(List &l)
{
	for (Node *p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (Node *q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->Data.getter_SoMu() < q->Data.getter_SoMu())
			{
				swap(p->Data,q->Data);
			}
		}
	}
}
// Rút gọn đa thức chưa sắp xếp 
void RutGonDaThuc(List &l)
{
	for (Node *p = l.pHead; ; p = p->pNext)
	{
		Node *Temp = p;
		for (Node *q = p->pNext; q != NULL;)
		{
			if (p->Data.getter_SoMu() == q->Data.getter_SoMu())
			{
				if (q == l.pTail)
				{
					l.pTail = Temp;
				}
				p->Data = p->Data + q->Data;
				Temp->pNext = q->pNext;
				delete q;
				q = Temp->pNext;
			}
			else
			{
				Temp = q;
				q = q->pNext;
			}
		}
		if (p == l.pTail)
		{
			break;
		}
	}
}

void NhanDathuc(List &l, List l1, List l2)
{
	for (Node *p = l1.pHead; p != NULL; p = p->pNext)
	{
		for (Node *q = l2.pHead; q != NULL; q = q->pNext)
		{
			SoHang Temp;
			Temp = p->Data*q->Data;
			AddTail(l, Temp);
		}
	}
}