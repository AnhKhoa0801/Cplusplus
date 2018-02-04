#pragma once
#include<iostream>
using namespace std; 
struct DiemThi
{
	int Masv, Mamh, Diem = -1;
};

// Node điểm thi
struct Node2
{
	DiemThi Data;
	Node2 *pNext;
	Node2 *pPrev;
};

// Danh sách điểm thi
struct List2
{
	Node2 *pHead;
	Node2 *pTail;
};

void TaoDSDiem_SV(List2 &, int);
void TaoDSDiem_Mon(List2 &, int);

void CreateList(List2 &l)
{
	l.pHead = l.pTail = NULL;
}

Node2* getNode(DiemThi x)
{
	Node2 *p = new Node2;
	if (p == NULL)
	{
		return NULL;
	}
	p->Data = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

void AddTail(List2 &l, DiemThi x)
{
	Node2 *p = getNode(x);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}

// Tìm sinh viên theo Mamh và Masv
Node2* TimKiemDiemSV(List2 l, int Mamh, int Masv)
{
	for (Node2 *p = l.pHead; p; p = p->pNext)
	{
		if (p->Data.Mamh == Mamh&&p->Data.Masv == Masv)
		{
			return p;
		}
	}
}

// Kiểm tra sinh viên đã thi chưa trả về true nếu đã thi
bool KiemTraDiemSV(List2 l, int Mamh, int Masv)
{
	for (Node2 *p = l.pHead; p; p = p->pNext)
	{
		if (p->Data.Mamh == Mamh&&p->Data.Masv == Masv)
		{
			if (p->Data.Diem != -1)
			{
				return true;
			}
			return false;
		}
	}
}