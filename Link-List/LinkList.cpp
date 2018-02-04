#include"LinkList.h"
void SapXepTang(List &l)
{
	for (Node *p = l.pHead; p!=l.pTail; p = p->pNext)
	{
		for (Node *q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->Data > q->Data)
			{
				swap(p->Data, q->Data);
			}
		}
	}
}

// Đảo DSLK
void DaoDSLK(List &l)			
{
	if (l.pHead->pNext == NULL)
	{
		return;
	}
	l.pTail = l.pHead;
	Node *p = l.pHead->pNext;
	Node *q = p;
	l.pHead->pNext = NULL;
	do
	{
		q = q->pNext;
		p->pNext = l.pHead;
		l.pHead = p;
		p = q;
	} while (p);
}

// Xóa trùng đã sắp xếp tăng
void XoaPhanTuTrung1(List &l)
{
	SapXepTang(l);
	for (Node *p = l.pHead; p->pNext != NULL;)
	{
		Node *q = p->pNext;
		if (p->Data == q->Data)
		{
			p->pNext = q->pNext;
			if (p->pNext == NULL)
			{
				l.pTail = p;
			}
			delete q;
		}
		else
		{
			p = p->pNext;
		}
	}
}

// Xóa trùng chưa sắp xếp tăng 
void XoaPhanTuTrung2(List &l)
{
	for (Node *p = l.pHead; p != l.pTail; p = p->pNext)
	{
		Node *Temp = NULL;
		for (Node *q = p->pNext; q; q = q->pNext)
		{
			if (p->Data == q->Data)
			{
				if (Temp != NULL)
				{
					delete Temp;
					Temp = NULL;
				}
				p->pNext = q->pNext;
				Temp = q;
				if (q->pNext == NULL)
				{
					if (l.pHead->pNext == NULL)
					{
						delete Temp;
						l.pTail = l.pHead;
						return;
					}
					else
					{
						l.pTail = q;
					}
				}
			}
		}
	}
}

// Thêm đã sắp xếp tăng 
void ThemCoThuTu(List &l,int x)
{
	SapXepTang(l);
	if (l.pHead->Data >= x)
	{
		AddHead(l, x);
	}
	else if (l.pTail->Data <= x)
	{
		AddTail(l, x);
	}
	else
	{
		Node *p = getNode(x);
		Node *s = l.pHead;
		while (s->pNext->Data <= x)
		{
			s = s->pNext;
		}
		p->pNext = s->pNext;
		s->pNext = p;
	}
}

int main()
{
	List l;
	Nhap(l);
	Xuat(l);
	system("pause");
	return 0;
}