#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int MAXLIST = 100;
struct SinhVien
{
	int MaSo;
	string HoTen;
};

struct Node
{
	SinhVien Data;
	struct Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void Nhapsv(SinhVien &sv)
{
	cout << "nhap ma so sinh vien:";
	cin >> sv.MaSo;
	cin.ignore();
	cout << "nhap ho ten sinh vien:";
	getline(cin, sv.HoTen);
}

void Xuatsv(SinhVien sv)
{
	cout << "Ma so sv: " << sv.MaSo;
	cout << "Ho ten sv: " << sv.HoTen;
}

void getList(List &l)
{
	l.pHead = l.pTail = NULL;
}

Node* getNode(SinhVien x)
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

void AddTail(List &l, SinhVien sv)
{
	Node *p = getNode(sv);
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

void InPut(List &l)
{
	int Check;
	SinhVien sv;
	do
	{
		cout << "Nhap lua chon (1:Nhap SV/0: Thoat):";
		cin >> Check;
		if (Check == 1)
		{
			Nhapsv(sv);
			AddTail(l, sv);
		}
		else 
		{
			if (Check != 0)
			{
				cout << "Error!" << endl;
			}
		}
	} while (Check != 0);
}

void OutPut(List l)
{
	for (Node*p = l.pHead; p != NULL; p = p->pNext)
	{
		Xuatsv(p->Data);
		cout << endl;
	}
}

int main()
{
	List l;
	int a;
	do
	{
		cout << "========+++==== MENU =======+++======" << endl;
		cout << "1. Nhap danh sach " << endl;
		cout << "2. Liet ke ds" << endl;
		cout << "3. Tong so nut trong ds" << endl;
		cout << "4. Them 1 phan tu vao sau ptu thu i" << endl;
		cout << "5. Nhap ma so -> In ra thong tin sv" << endl;
		cout << "6. Nhap ma so -> xoa sv" << endl;
		cout << "7. Sap xep ds theo thu tu maso tang" << endl;
		cout << "8. Ghi ds vao file" << endl;
		cout << "9. Nap ds tu file vao" << endl;
		cout << "10. Thoat! " << endl;
		cout << "Moi ban chon: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			InPut(l);
			break;
		}
		case 2:
		{
			OutPut(l);
			break;
		}
		}
	} while (a != 10);
	system("pause");
	return 0;
}