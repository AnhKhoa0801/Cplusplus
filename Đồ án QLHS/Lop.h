#pragma once
#include"SinhVien.h"
#include"DSLK_SV.h"
#include"DiemThi.h"

class CLop
{
private:
	int MaLop;
	string TenLop;
	List Arr;
public:
	CLop();
	void Nhap(List2 &);
	void DocSV(ifstream&);
	string Get_TenLop();
	void Set_TenLop(string);
	int Get_Malop();
	void Set_MaLop(int);
	Node* TimKiemSV(int);
	void BangDiem(List2, int);
	~CLop();
};

CLop::CLop()
{
	MaLop = 0;
	TenLop = "";
	CreateList(Arr);
}

int CLop::Get_Malop()
{
	return MaLop;
}

void CLop::Set_MaLop(int x)
{
	MaLop = x;
}

void CLop::Set_TenLop(string s)
{
	TenLop = s;
}

string CLop::Get_TenLop()
{
	return TenLop;
}

Node* CLop::TimKiemSV(int x)
{
	return TimKiem(Arr, x);
}

// Tìm kiếm mã sinh viên trong SinhVien[]
bool TimKiemMangSV(int x)
{
	for (int i = 0; i < SoSV; i++)
	{
		if (SinhVien[i] == x)
		{
			return true;
		}
	}
	return false;
}

// In bảng điểm của 1 môn của lớp 
void CLop::BangDiem(List2 l2, int Mamh)
{
	int i = 1;
	cout << "Ma lop:" << MaLop << "\tTen lop:" << TenLop << endl;
	cout << "STT\tMaSV\tHo\t\tTen\t\tPhai\t\tDiem";
	cout << endl;
	if (Arr.pHead==NULL)
	{
		cout << "Lop chua co sinh vien!";
	}
	else
	{
		for (Node *p = Arr.pHead; p; p = p->pNext)
		{
			Node2 *q = TimKiemDiemSV(l2, Mamh, p->Data.Get_MaSV());
			cout << i++ << "\t";
			p->Data.Xuat();
			cout << "\t\t";
			if (q->Data.Diem == -1)
			{
				cout << "CHUA THI";
			}
			else
			{
				cout << q->Data.Diem;
			}
			cout << endl;
		}
	}
	_getch();
}

void CLop::Nhap(List2 &l)
{
	// Nhập danh sách sinh viên của 1 lớp
	int LuaChon;
	int i = 0;
	system("cls");
	do
	{
		cout << "Ma Lop: " << MaLop << endl;
		cout << "Ten Lop: " << TenLop << endl;
	NhapSV:
		cout << "Nhap Lua Chon(1:Nhap sinh vien/0:Thoat): ";
		cin >> LuaChon;
		if (LuaChon == 1)
		{
			string Temp;
			int k;
			cout << "Nhap MaSV: ";
			do
			{
				Temp = ChuanHoaNhap2();
			} while (Temp == "");
			cout << endl;
			k = atoi((char*)Temp.c_str());
			if (TimKiemMangSV(k))
			{
				cout << "Loi! Ma sv bi trung!" << endl;
				goto NhapSV;
			}
			else
			{
				CSinhVien x;
				x.Set_MaSV(k);
				x.Nhap();
				AddTail(Arr, x);
				SinhVien[SoSV] = k;
				TaoDSDiem_SV(l, k);
				SoSV++;
				system("cls");
			}
		}
		else if (LuaChon != 0)
		{
			cout << "Loi! Xin kiem tra lai!" << endl;
			goto NhapSV;
		}
	} while (LuaChon != 0);
}

// Đọc 1 sinh viên từ File
void CLop::DocSV(ifstream &File)
{
	CSinhVien x;
	x.DocSinhVien(File);
	AddTail(Arr, x);
}

CLop::~CLop()
{
}
