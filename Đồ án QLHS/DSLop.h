#pragma once
#include"Lop.h"
#include<iomanip>

CLop DSLop[LOPMAX];
int SoLop = 0;

// Kiểm tra mã lớp có trong danh sách nếu có trả về true
bool TimKiemMaLop(int MaLop)
{
	for (int i = 0; i < SoLop; i++)
	{
		if (DSLop[i].Get_Malop() == MaLop)
		{
			return true;
		}
	}
	return false;
}

// Nhập danh sách lớp 
void NhapDanhSachLop()
{
	string s;
	int LuaChon;
	do
	{
	NhapDSLop:
		cout << "Nhap lua chon(1:Nhap lop/0:Thoat): ";
		cin >> LuaChon;
		if (LuaChon == 1)
		{
			cout << "Nhap Ma Lop: ";
			do
			{
				s = ChuanHoaNhap2();
			} while (s == "");
			cout << endl;
			int MaLop = atoi((char*)s.c_str());
			if (TimKiemMaLop(MaLop))
			{
				cout << "Ma lop bi trung! ";
				cout << endl;
				goto NhapDSLop;
			}
			else
			{
				DSLop[SoLop].Set_MaLop(MaLop);
			}
			cout << "Nhap Ten Lop: ";
			do
			{
				s = ChuanHoaNhap1();
			} while (s == "");
			cout << endl;
			DSLop[SoLop++].Set_TenLop(s);
		}
		else if (LuaChon != 0)
		{
			cout << "Loi! Xin kiem tra lai! " << endl;
		}
	} while (LuaChon != 0);
}

void xuatMenu(string Menu[], int ViTriToMau, int Size, int x, int y)
{
	for (int i = 0; i < Size; i++)
	{
		gotoxy(x, y + i);
		if (i == ViTriToMau)
		{
			textcolor(151);
		}
		else textcolor(7);
		cout << Menu[i];
	}
	textcolor(7);
}

// Hàm tạo Menu động
void toMau(string Menu[], int &ViTriToMau, int Size, int x, int y)
{
	char c;
	do
	{
		c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 80)
			{
				if (ViTriToMau == Size - 1)
				{
					ViTriToMau = -1;
				}
				xuatMenu(Menu, ++ViTriToMau, Size, x, y);
			}
			if (c == 72)
			{
				if (ViTriToMau == 0)
				{
					ViTriToMau = Size;
				}
				xuatMenu(Menu, --ViTriToMau, Size, x, y);
			}
		}
	} while (c != 13);
}

// Menu động nhập sinh viên cho lớp 
void NhapSinhVien(List2 &l)
{
	string Lop[30];
	cout << "Ma lop   || Ten Lop  " << endl;
	for (int i = 0; i < SoLop; i++)
	{
		cout << DSLop[i].Get_Malop();
		gotoxy(10, i + 2);
		cout << "||";
		cout << endl;
		Lop[i] = DSLop[i].Get_TenLop();
	}
	int i = 0;
	xuatMenu(Lop, i, SoLop, 13, 2);
	toMau(Lop, i, SoLop, 13, 2);
	DSLop[i].Nhap(l);
}

// Đọc danh sách lớp học từ file 
void DocDSLop()
{
	ifstream File("DSLOP.TXT");
	while (!File.eof())
	{
		int Malop;
		File >> Malop;
		DSLop[SoLop].Set_MaLop(Malop);
		File.ignore();
		string s;
		getline(File, s);
		DSLop[SoLop].Set_TenLop(s);
		int n;
		File >> n;
		File.ignore();
		for (int i = 1; i <= n; i++)
		{
			DSLop[SoLop].DocSV(File);
		}
		SoLop++;
	}
	File.close();
}

// Ghi danh sách lớp vào file
void GhiDSLop()
{
	ofstream File("InDSLop.TXT");
	File << "Ma lop         Ten lop";
	File << endl;
	for (int i = 0; i < SoLop; i++)
	{
		File << setw(3) << DSLop[i].Get_Malop();
		File << "              ";
		File << DSLop[i].Get_TenLop() << endl;
	}
	File.close();
}

// Tìm kiếm mã sv trong toàn bộ danh sách lớp
Node* TimkiemDS_SV(int x)
{
	for (int i = 0; i < SoLop; i++)
	{
		if (DSLop[i].TimKiemSV(x) != NULL)
		{
			return DSLop[i].TimKiemSV(x);
		}
	}
}

void InDSLop()
{
	cout << "Malop\t\tTen lop" << endl;
	for (int i = 0; i < SoLop; i++)
	{
		cout << DSLop[i].Get_Malop() << "\t\t" << DSLop[i].Get_TenLop() << endl;
	}
}