#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<myfunc.h>
#include<fstream>
#include<time.h>
#include<iomanip>
#define SVMAX 5000
#define LOPMAX 100
#define MONMAX 30
using namespace std;

class CSinhVien
{
private:
	int MaSV;
	string Ho, Ten, PassWord, Phai;
public:
	CSinhVien();
	void Nhap();
	void Xuat();
	int Get_MaSV();
	void Set_MaSV(int);
	void DocSinhVien(ifstream&);
	string Get_Pass();
	~CSinhVien();
};

int wherex(void)
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	return coninfo.dwCursorPosition.X;
}

int wherey(void)
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	return coninfo.dwCursorPosition.Y;
}

// In ra ký tự hoa không có ký tự số 
string ChuanHoaNhap()
{
	string s = "";
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			return "\0";
		}
		if (c >= 'a'&&c <= 'z')
		{
			c = c - 32;
		}
		if (c >= 'A'&&c <= 'Z')
		{
			cout << c;
			s += c;
		}
		else if (c == 8)
		{
			if (s.length() > 0)
			{
				cout << "\b \b";
				s.replace(s.length() - 1, 1, "");
			}
		}
	} while (c != 13);
	return s;
}

// In ra ký tự hoa có ký tự số 
string ChuanHoaNhap1()
{
	string s = "";
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			return "\0";
		}
		if (c >= 'a'&&c <= 'z')
		{
			c = c - 32;
		}
		if (c >= 'A'&&c <= 'Z' || c >= '0'&&c <= '9' || c == ' ')
		{
			cout << c;
			s += c;
		}
		else if (c == 8)
		{
			if (s.length() > 0)
			{
				cout << "\b \b";
				s.replace(s.length() - 1, 1, "");
			}
		}
	} while (c != 13);
	return s;
}

// In ra ký tự chỉ có số
string ChuanHoaNhap2()
{
	string s = "";
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			return "\0";
		}
		if (c >= '0'&&c <= '9')
		{
			cout << c;
			s += c;
		}
		else if (c == 8)
		{
			if (s.length() > 0)
			{
				cout << "\b \b";
				s.replace(s.length() - 1, 1, "");
			}
		}
	} while (c != 13);
	return s;
}

// Hàm nhập Password
string ChuanHoaPass()
{
	string s = "";
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			return "\0";
		}
		if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z' || c >= '0'&&c <= '9')
		{
			cout << "*";
			s += c;
		}
		else if (c == 8)
		{
			if (s.length() > 0)
			{
				cout << "\b \b";
				s.replace(s.length() - 1, 1, "");
			}
		}
	} while (c != 13);
	return s;
}

int SinhVien[SVMAX];		// Mảng đánh dấu mã sinh viên 
int SoSV = 0;

// Tìm kiếm sinh viên trong toàn bộ danh sách lớp
CSinhVien::CSinhVien()
{
	MaSV = 0;
	Ho = Ten = PassWord = Phai = "";
}

void CSinhVien::Nhap()
{
	cout << "Nhap Ho: ";
	do
	{
		Ho = ChuanHoaNhap();
	} while (Ho == "");
	cout << endl;
	cout << "Nhap Ten: ";
	do
	{
		Ten = ChuanHoaNhap();
	} while (Ten == "");
	cout << endl;
	cout << "Nhap gioi tinh(NAM/NU): ";
	int x = wherex();
	int y = wherey();
	do
	{
		Phai = ChuanHoaNhap();
		if (Phai != "NAM" && Phai != "NU")
		{
			gotoxy(x + 1, y + 1);
			cout << "          ";
			gotoxy(x + 1, y + 1);
		}
	} while (Phai != "NAM" && Phai != "NU");
	cout << endl;
	cout << "Nhap Password: ";
	do
	{
		PassWord = ChuanHoaPass();
	} while (PassWord == "");
}

void CSinhVien::Xuat()
{
	cout << MaSV << "\t" << Ho << "\t\t" << Ten << "\t\t" << Phai;
}

string CSinhVien::Get_Pass()
{
	return PassWord;
}

// Đọc sinh viên từ file
void CSinhVien::DocSinhVien(ifstream &File)
{
	File >> MaSV >> Ho >> Ten >> Phai >> PassWord;
	SinhVien[SoSV++] = MaSV;
}

int CSinhVien::Get_MaSV()
{
	return MaSV;
}

void CSinhVien::Set_MaSV(int x)
{
	MaSV = x;
}

CSinhVien::~CSinhVien()
{
}