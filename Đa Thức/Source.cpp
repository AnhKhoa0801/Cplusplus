//#include"LinkList.h"
//#include <cmath>
//int main()
//{
//	/*List l,l1,l2;
//	CreateList(l);
//	CreateList(l1);
//	CreateList(l2);
//	cout << "Nhap da thuc 1"<<endl;
//	Nhap(l1);
//	cout << "Nhap da thuc 2"<<endl;
//	Nhap(l2);
//	RutGonDaThuc(l1);
//	RutGonDaThuc(l2);
//	Xuat(l1);
//	cout << endl;
//	Xuat(l2);
//	cout << endl;
//	NhanDathuc(l, l1, l2);
//	RutGonDaThuc(l);
//	cout << "Nhan 2 da thuc " << endl;
//	Xuat(l);
//	GiaiPhong(l);
//	GiaiPhong(l1);
//	GiaiPhong(l2);
//	system("pause");*/
//	return 0;
//}
#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
//#include "mylib.h"
#define MAX 100
using namespace std;

struct DanhMucSach
{
	int maSach;
	int ttSach;
	int vitri;
};
struct DMSNode
{
	DanhMucSach data;
	DMSNode *pNext;
};
struct ListDMS
{
	DMSNode *pHead;
	DMSNode *pTail;
};
typedef struct ListDMS LDMS;
// ---------- Khoi tao ---------
void KhoitaoLDMS(LDMS &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

DMSNode* CreateDMS(DanhMucSach x)
{
	DMSNode *p = new DMSNode;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void AddTailDMS(LDMS &l, DMSNode *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

int DuyetDMS(LDMS &l)
{
	int dem = 0;
	for (DMSNode *p = l.pHead; p != NULL; p = p->pNext)
	{
		dem++;
	}
	return dem;
}

void NhapDMS(LDMS &l)
{
	DanhMucSach data;
	cout << " \nVi Tri :";
	cin >> data.vitri;
	fflush(stdin);

	cout << "\nTT Sach ";
	cin >> data.ttSach;
	fflush(stdin);
	data.maSach = 100 + DuyetDMS(l);
	cout << DuyetDMS(l) << endl;
	AddTailDMS(l, CreateDMS(data));
}



struct DauSach
{
	string ISBN;
	string tenSach;
	string tacGia;
	string theLoaiSach;
	int soTrang;
	int namSB;
	LDMS sach;
};
typedef struct ListDauSach
{
	int n;
	DauSach DS[MAX];
}LDS;

//----- Khoi tao -------

void KhoitaoDS(LDS &l)
{
	l.n = 0;
}

void themDS(LDS &l, DauSach data)
{
	if (l.n > MAX)
	{
		return;
	}
	l.DS[l.n] = data;

}

int KiemtraISBN(LDS l, string temp)
{
	for (int i = 0; i < l.n; i++)
	{
		if (l.DS[i].ISBN == temp)
			return 0;
	}
	return 1;
}

void NhapDauSach(LDS &l)
{
	KhoitaoDS(l);
	DauSach data;
	if (l.n > MAX)
		return;
	else
	{
		cout << "Nhap IBSN ";
		getline(cin, data.ISBN);
		if (KiemtraISBN(l, data.ISBN) == 0)
			cout << "Trung IBSN ";
		fflush(stdin);

		cout << " \nTen sach :";
		getline(cin, data.tenSach);
		fflush(stdin);

		cout << "\nTac gia ";
		getline(cin, data.tacGia);
		fflush(stdin);

		cout << "\nThe loai sach ";
		getline(cin, data.theLoaiSach);
		fflush(stdin);

		cout << "\nSo trang ";
		cin >> data.soTrang;
		fflush(stdin);

		cout << "\nNam SB ";
		cin >> data.namSB;
		fflush(stdin);
		themDS(l, data);
		KhoitaoLDMS(l.DS[l.n].sach);
		NhapDMS(l.DS[l.n].sach);
		
	}
}

void XuatDauSach(LDS &l)
{
	for (int i = 0; i < l.n; i++)
	{
		cout << l.DS[i].ISBN << " " << l.DS[i].tenSach << " " << l.DS[i].soTrang << " " << l.DS[i].tacGia << " " << l.DS[i].namSB << " " << l.DS[i].theLoaiSach << endl;
		for (DMSNode *p = l.DS[i].sach.pHead; p != NULL; p = p->pNext)
		{
			cout << p->data.maSach << endl;
		}
	}
}

// --------- Ghi file ----------
void GhiFileDS(LDS l)
{
	ofstream f("DauSach.txt");
	for (int i = 0; i < l.n; i++)
	{
		f << l.DS[i].ISBN << endl;
		f << l.DS[i].tenSach << endl;
		f << l.DS[i].tacGia << endl;
		f << l.DS[i].theLoaiSach << endl;
		f << l.DS[i].soTrang << endl;
		f << l.DS[i].namSB;
		if (i != l.n - 1)
		{
			f << endl;
		}
	}
	f.close();
}


void Timsach(LDS &l)
{
	char data[30];
	cout << "\nNhap ten sach :";
	cin.getline(data, 30);
	for (int i = 0; i < l.n; i++)
	{
		if (l.DS[i].tenSach == data)
		{
			cout << l.DS[i].ISBN << " " << l.DS[i].tenSach << " " << l.DS[i].soTrang << " " << l.DS[i].tacGia << " " << l.DS[i].namSB << " " << l.DS[i].theLoaiSach << endl;
			return;
		}
	}
	cout << "Ten sach khong ton tai !!";
}

// --------- Load File ---------
void LoadFileDS(LDS &l)
{
	DauSach data;
	ifstream file("DauSach.txt");
	while (!file.eof())
	{
		string s;
		getline(file, data.ISBN);
		getline(file, data.tenSach);
		getline(file, data.tacGia);
		getline(file, data.theLoaiSach);
		getline(file, s);
		data.soTrang = atoi((char*)s.c_str());
		getline(file, s);
		data.namSB = atoi((char*)s.c_str());
		themDS(l, data);
		//cout << data.ISBN << " " << data.tenSach << " " << data.soTrang << " " << data.tacGia << " " << data.namSB << " " << data.theLoaiSach << endl;

	}
	file.close();
}

void XuatDMS(LDS a)
{
	for (DMSNode *p = a.DS[a.n].sach.pHead; p != NULL; p = p->pNext)
	{
		cout << p->data.maSach << " " << p->data.ttSach << " " << p->data.vitri << " " << endl;
	}
}


int main()
{
	LDS l;
	NhapDauSach(l);
	XuatDauSach(l);
	XuatDMS(l);
	system("pause");
}

