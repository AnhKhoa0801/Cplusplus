//#include <iostream>
//#include <math.h>
//#include <vector>
//#include <string>
//#include <conio.h>
//#include <stdio.h>
//#include <time.h>
//#include<Windows.h>
//using namespace std;
//
//#define MAX 100
//#define BACKSPACE 8
//#define  ENTER 13
//#define  T_RIGHT 185
//#define  MID 186
//#define  RIGHT_TOP 187
//#define  RIGHT_BOT 188
//#define  LEFT_BOT 200
//#define  LEFT_TOP 201
//#define  T_BOT 202
//#define  T_TOP 203
//#define  T_LEFT 204
//#define  MID_TOP 20
//#define  TOP 205
//#define  BOT 205
//#define  VTx 3
//#define  VTy 7
//#define  sizeMenu 8
//#define  BACKSPACE 8
//#define  UP 72
//#define  DOWN 80
//#define  LEFT 75
//#define  RIGHT 77
//#define  ESC  27
//#define  CHUTHAP 206
//
//int wherex(void)
//{
//	CONSOLE_SCREEN_BUFFER_INFO coninfo;
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
//	return coninfo.dwCursorPosition.X;
//}
//
//int wherey(void)
//{
//	CONSOLE_SCREEN_BUFFER_INFO coninfo;
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
//	return coninfo.dwCursorPosition.Y;
//}
//
//void textcolor(int x)
//{
//	HANDLE mau;
//	mau = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(mau, x);
//}
//
//void gotoxy(short x, short y)
//{
//	HANDLE hConsoleOutput;
//	COORD Cursor_an_Pos = { x,y };
//	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
//}
//
/////// VAT TU ///////
//struct VT
//{
//	string MAVT = "", TENVT = "", DVT = "";
//	int SLT = 0;
//};
//struct DSVT
//{
//	VT vt[MAX];
//	int key = 0;
//};
//
///////CTHD + HD /////
//struct InfoCTHD
//{
//	string MAVT = "";
//	float VAT;
//	int SOLUONG, DONGIA;
//};
//struct CTHD
//{
//	InfoCTHD info;
//	CTHD *pnext;
//};
//struct Date
//{
//	int ngay, thang, nam;
//};
//struct InfoHD
//{
//	string SOHD = "", MANV = "";
//	Date time;
//	char LOAI;
//	CTHD* FirstCTHD;
//};
//struct HD
//{
//	InfoHD info;
//	HD* pnext;
//};
//
/////// NV /////////
//struct InfoNV
//{
//	string MANV = "", HO = "", TEN = "";
//	bool PHAI;  // 1 la nam - 0 la nu
//	HD* FirstHD;
//};
//
//struct NV
//{
//	InfoNV info;
//	NV *pleft;
//	NV *pright;
//};
//
/////////////////////////////////////////////////// CAC LOAI HAM /////////////////////////////////////////////////////////////
//
////////// CHUAN HOA ////////
////chuyen HOA thanh THUONG
//string chuanHoaKiTu(string &a)
//{
//	int k = a.length();
//	char* s = strlwr((char*)a.c_str());				// chuyen tat ca thanh chu thuong
//	for (int i = 0; i < k; i++)
//	{
//		a[i] = s[i];
//	}
//	if (a[0] >= 'a'&&a[0] <= 'z')
//		a[0] = a[0] - 32;
//	for (int i = 0; i < k; i++)			//sau dau  "space" viet HOA
//	{
//		if (a[i] == ' ' && (a[i + 1] >= 'a'&&a[i + 1] <= 'z'))
//		{
//			a[i + 1] = a[i + 1] - 32;
//		}
//	}
//
//	return a;
//}
//
////Viet HOA chu dau, del ' '
//void chuanHoaChuoi(string &a)
//{
//	while (a[0] == ' ')		// replace(vt bat dau,so ki tu,ki tu thay the)
//	{
//		a.replace(0, 1, "");
//	}
//	while (a[a.length() - 1] == ' ')
//	{
//		a.replace(a.length() - 1, 1, "");
//	}
//	int i = 0;
//	int k = a.length();
//	while (i < k)
//	{
//		if (a[i] != ' ')
//			i++;
//		else
//		{
//			while (a[i + 1] == a[i])
//			{
//				a.replace(i, 1, "");
//			}
//			k -= 1;
//		}
//	}
//	a = chuanHoaKiTu(a);
//}
//
////// HAM VE THAO TAC NHAP
//// Ham nhap cho tat ca string
//char Nhap(string &data, short x, short y)
//{
//
//	char c;
//	gotoxy(x, y);
//	cout << data;
//	while (1)
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == UP || c == DOWN)
//				return c;
//		}
//		else
//		{
//			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ')
//			{
//				cout << c;
//				data = data + c;
//			}
//			else if (c == BACKSPACE)
//			{
//				if (data.length() > 0)
//				{
//					cout << "\b \b";
//					data.replace(data.length() - 1, 1, "");
//				}
//			}
//			else return c;
//		}
//	}
//}
//
//// Nhap Ma viet HOA + khong SPACE
//char NhapMA(string &data, short x, short y) // Ham nhap cho tat ca string
//{
//
//	char c;
//	gotoxy(x, y);
//	cout << data;
//	while (1)
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == UP || c == DOWN)
//				return c;
//		}
//		else
//		{
//			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//			{
//				if ((c >= 'a' && c <= 'z'))
//					c = c - 32;
//				cout << c;
//				data = data + c;
//			}
//			else if (c == BACKSPACE)
//			{
//				if (data.length() > 0)
//				{
//					cout << "\b \b";
//					data.replace(data.length() - 1, 1, "");
//				}
//			}
//			else return c;
//		}
//	}
//}
//
//// Ham nhap chi nhan vao so
//char Nhapso(string &data, short x, short y)
//{
//
//	char c;
//	gotoxy(x, y);
//	cout << data;
//	while (1)
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == UP || c == DOWN)
//				return c;
//		}
//		else
//		{
//			if ((c >= '0' && c <= '9'))
//			{
//				cout << c;
//				data = data + c;
//			}
//			else if (c == BACKSPACE)
//			{
//				if (data.length() > 0)
//				{
//					cout << "\b \b";
//					data.replace(data.length() - 1, 1, "");
//				}
//			}
//			else return c;
//		}
//	}
//}
//
////chi lay so + LEFT, RIGHT
//char NhapNgay(string &data, short x, short y)
//{
//	char c;
//	gotoxy(x, y);
//	cout << data;
//	while (1)
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == LEFT || c == RIGHT)
//				return c;
//		}
//		else
//		{
//			if ((c >= '0' && c <= '9'))
//			{
//				cout << c;
//				data = data + c;
//			}
//			else if (c == BACKSPACE)
//			{
//				if (data.length() > 0)
//				{
//					cout << "\b \b";
//					data.replace(data.length() - 1, 1, "");
//				}
//			}
//			else return c;
//		}
//	}
//}
//
//// kt ngay thang nam hop le
//bool ktDate(Date time)
//{
//	int Thang[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (((time.nam % 4 == 0 && time.nam % 100) != 0) || time.nam % 400 == 0)
//	{
//		Thang[2] = 29;
//	}
//	if (time.thang >= 1 && time.thang <= 12)
//	{
//		if (time.ngay >= 1 && time.ngay <= Thang[time.thang])
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//// Nhap Date theo toa do x y
//void setdate(Date &Time, short x, short y)
//{
//Nhap:
//	char kt;
//	string t1 = "", t2 = "", t3 = "";
//	gotoxy(x, y);
//	cout << "Ngay      Thang      Nam         ";
//NhapNGAY:
//	do
//	{
//		kt = NhapNgay(t1, x + 6, y);
//		if (kt == RIGHT&&t1 != "")
//		{
//			goto NhapTHANG;
//		}
//	} while (t1 == "");
//NhapTHANG:
//	Time.ngay = atoi((char*)t1.c_str());
//	do
//	{
//		kt = NhapNgay(t2, x + 17, y);
//		if (kt == LEFT)
//		{
//			goto NhapNGAY;
//		}
//		else if (kt == RIGHT&&t2 != "")
//		{
//			goto NhapNAM;
//		}
//	} while (t2 == "");
//NhapNAM:
//	Time.thang = atoi((char*)t2.c_str());
//	do
//	{
//		kt = NhapNgay(t3, x + 27, y);
//		if (kt == LEFT)
//		{
//			goto NhapTHANG;
//		}
//	} while (t3 == "");
//	Time.nam = atoi((char*)t3.c_str());
//	if (!ktDate(Time))
//	{
//		gotoxy(x, y + 1);
//		cout << "Ngay Thang Nam khong hop le!";
//		Sleep(1000);
//		gotoxy(x, y + 1);
//		cout << "                            ";
//		goto Nhap;
//	}
//}
//
///////Ham CTHD //////
//CTHD*  newCTHD(InfoCTHD a)
//{
//	CTHD* pnew = new CTHD;
//	pnew->info = a;
//	pnew->pnext = NULL;
//
//	return pnew;
//}
//
//void addHeadCTHD(CTHD* &First, InfoCTHD a)
//{
//	CTHD* p = newCTHD(a);
//	if (First == NULL)
//	{
//		First = p;
//	}
//	else
//	{
//		p->pnext = First;
//		First = p;
//	}
//}
//void addTailCTHD(CTHD* &First, InfoCTHD a)
//{
//	CTHD* p = newCTHD(a);
//	if (First == NULL)
//	{
//		First = p;
//	}
//	else
//	{
//		CTHD* k = First;
//		while (k->pnext != NULL)
//		{
//			k = k->pnext;
//		}
//		k->pnext = p;
//	}
//}
//
///////// Ham HD ////////////////
//HD* newHD(InfoHD a)
//{
//	HD* pnew = new HD;
//
//	pnew->info = a;
//	pnew->pnext = NULL;
//
//	return pnew;
//}
//void addHeadHD(HD* &First, InfoHD a)
//{
//	HD* p = newHD(a);
//	if (First == NULL)
//	{
//		First = p;
//	}
//	else
//	{
//		p->pnext = First;
//		First = p;
//	}
//}
//void addTailHD(HD* &First, InfoHD a)
//{
//	HD* p = newHD(a);
//	if (First == NULL)
//	{
//		First = p;
//	}
//	else
//	{
//		HD* k = First;
//		while (k->pnext != NULL)
//		{
//			k = k->pnext;
//		}
//		k->pnext = p;
//
//	}
//}
//// tra ve true neu trung So HD (search SoHD cua 1 NV)
//bool searchSoHD(HD* FirstHD, string x)
//{
//	HD* k = FirstHD;
//	for (k; k != NULL; k = k->pnext)
//	{
//		if (k->info.SOHD == x)
//			return true;
//	}
//
//	return false;
//}
//
//// Duyệt cây tìm SoHD trong toàn bộ NV, nếu có trả về true
//bool TimSoHD(NV* Root, string x)
//{
//	if (Root != NULL)
//	{
//		if (searchSoHD(Root->info.FirstHD, x))
//		{
//			return true;
//		}
//		if (TimSoHD(Root->pleft, x))
//			return true;
//		if (TimSoHD(Root->pright, x))
//			return true;
//	}
//	return false;
//}
/////////// VT /////////////
//// Trùng trả về true
//bool searchMAVT(DSVT ds, string a)
//{
//	for (int i = 0; i < ds.key; i++)
//	{
//		if (ds.vt[i].MAVT == a)
//			return true;
//	}
//	return false;
//}
//
/////////// NV ////////////
//// tra ve true neu a>b 
//bool ssTen(InfoNV a, InfoNV b)
//{
//	if (a.TEN > b.TEN)
//		return 1;
//	else if (a.TEN < b.TEN)
//		return 0;
//	else
//	{
//		if (a.HO > b.HO)
//			return 1;
//		else if (a.HO < b.HO)
//			return 0;
//		else
//		{
//			if (a.MANV > b.MANV)
//				return 1;
//			else
//				return 0;
//		}
//	}
//}
//
//NV* newNV(InfoNV a)
//{
//	NV* pnew = new NV;
//	pnew->info = a;
//	pnew->pleft = NULL;
//	pnew->pright = NULL;
//	return pnew;
//}
//
//// Trả về NV nếu có tồn tại
//NV* searchNV(NV* Root, string x)
//{
//	if (Root != NULL)
//	{
//		if (Root->info.MANV == x)
//		{
//			return Root;
//		}
//		searchNV(Root->pleft, x);
//		searchNV(Root->pright, x);
//	}
//	return NULL;
//}
//
//void addNV(NV* &Root, InfoNV a)
//{
//	if (Root == NULL)
//	{
//		Root = newNV(a);
//	}
//	else
//	{
//		if (ssTen(Root->info, a))
//			addNV(Root->pleft, a);
//		else
//			addNV(Root->pright, a);
//	}
//}
//
//
////////////////////////////////////////////////// MENU ///////////////////////////////////////////////////////////////
//vector<string> MENU;
//
//int tap = -1;
//
//void newMenu()
//{
//	MENU.resize(sizeMenu);
//	MENU[0] = "Nhap vat tu";
//	MENU[1] = "In danh sach vat tu ton kho";
//	MENU[2] = "Nhap nhan vien";
//	MENU[3] = "In danh sach nhan vien";
//	MENU[4] = "Lap hoa don nhap";
//	MENU[5] = "Lap hoa don xuat";
//	MENU[6] = "In hoa don";
//	MENU[7] = "Thong ke hoa don";
//
//
//}
//void xuatMenu(int vitritomau)
//{
//	for (int i = 0; i < sizeMenu; i++)
//	{
//		gotoxy(VTx, VTy + i);
//		if (i == vitritomau)
//		{
//			textcolor(151);
//		}
//		else
//			textcolor(7);
//		cout << MENU[i] << endl;
//	}
//}
//
//void xuatMenu()
//{
//
//	for (int i = 0; i < sizeMenu; i++)
//	{
//		gotoxy(VTx, VTy + i);
//		cout << MENU[i] << endl;
//	}
//}
//void Phim(int &i)
//{
//	char c;
//	do
//	{
//		c = _getch();
//		if (c == ESC)
//		{
//			xuatMenu();
//			gotoxy(64, 2);
//			textcolor(7);
//			cout << "LOAD";
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//		}
//		if (c == -32)
//		{
//			c = _getch();
//			if (c == DOWN)
//			{
//				if (tap == -1) //con ngoai menu
//				{
//					if (i == sizeMenu - 1)
//					{
//						textcolor(7);
//						xuatMenu();
//						gotoxy(64, 2);
//						textcolor(224);
//						cout << "LOAD";
//						i = -1;
//
//					}
//					else if (wherey() == 2)
//					{
//						textcolor(7);
//						gotoxy(64, 2);
//						cout << "LOAD";
//						gotoxy(73, 2);
//						textcolor(7);
//						cout << "EXIT";
//						xuatMenu(0);
//						i = 0;
//					}
//					else
//					{
//						xuatMenu(++i);
//					}
//				}
//			}
//
//			if (c == UP)
//			{
//				if (tap == -1)
//				{
//					if (i == 0)
//					{
//						textcolor(7);
//						xuatMenu();
//						gotoxy(64, 2);
//						textcolor(224);
//						cout << "LOAD";
//						i = -1; // de i roi vao vong else if
//
//					}
//					else if (wherey() == 2)
//					{
//						textcolor(7);
//						gotoxy(64, 2);
//						cout << "LOAD";
//						gotoxy(73, 2);
//						textcolor(7);
//						cout << "EXIT";
//						xuatMenu(sizeMenu - 1);
//						i = sizeMenu - 1;
//					}
//					else
//					{
//						xuatMenu(--i);
//					}
//				}
//			}
//			if (c == LEFT || c == RIGHT)          // cho qua lai EXIT + LOAD
//			{
//				if (tap == -1)
//				{
//					if (wherey() == 2)
//					{
//						if (wherex() == 68)
//						{
//							textcolor(7);
//							gotoxy(64, 2);
//							cout << "LOAD";
//							gotoxy(73, 2);
//							textcolor(224);
//							cout << "EXIT";
//						}
//
//						else if (wherex() == 77)
//						{
//							textcolor(7);
//							gotoxy(73, 2);
//							cout << "EXIT";
//							gotoxy(64, 2);
//							textcolor(224);
//							cout << "LOAD";
//						}
//					}
//				}
//			}
//
//		}
//	} while (c != ENTER);
//
//	if (wherex() == 77)
//	{
//		system("pause");
//	}
//}
//void veKhung()
//{
//	cout << char(LEFT_TOP);
//	for (int i = 1; i <= 78; i++)
//	{
//		cout << char(TOP);
//	}
//	cout << char(RIGHT_TOP);
//
//	gotoxy(0, 41);
//	cout << char(LEFT_BOT);
//	for (int i = 1; i <= 78; i++)
//	{
//		cout << char(TOP);
//	}
//	cout << char(RIGHT_BOT);
//	gotoxy(0, 1);
//	for (int i = 1; i <= 40; i++)
//	{
//		cout << char(MID);
//		for (int j = 1; j <= 78; j++)
//		{
//			cout << " ";
//		}
//		cout << char(MID);
//
//	}
//	gotoxy(0, 4);
//	cout << char(T_LEFT);
//	for (int i = 1; i <= 78; i++)
//	{
//		cout << char(TOP);
//	}
//	cout << char(T_RIGHT);
//
//	/////////////////////////////////////////////////////////
//	gotoxy(3, 2);
//	cout << "PHAN    MEM    QUAN    LI    VAT    LIEU    XAY    DUNG";
//	gotoxy(61, 0);
//	cout << char(T_TOP);
//	gotoxy(61, 1);
//	for (int i = 1; i <= 4; i++)
//	{
//		gotoxy(61, i);
//		cout << char(MID);
//	}
//	gotoxy(61, 4);
//	cout << char(T_BOT);
//	gotoxy(64, 2);
//	cout << "LOAD";
//
//	gotoxy(70, 0);
//	cout << char(T_TOP);
//	gotoxy(70, 1);
//	for (int i = 1; i <= 4; i++)
//	{
//		gotoxy(70, i);
//		cout << char(MID);
//	}
//	gotoxy(70, 4);
//	cout << char(T_BOT);
//	gotoxy(73, 2);
//	cout << "EXIT";
//
//
//}
////////////////////////////////////////
////xoa chu trong khung
//void clearText()
//{
//	gotoxy(1, 5);
//	for (int i = 1; i <= 78; i++)
//	{
//		for (int j = 5; j <= 40; j++)
//		{
//			gotoxy(i, j);
//			cout << " ";
//		}
//	}
//	gotoxy(64, 2);
//	cout << "    ";
//	gotoxy(73, 2);
//	cout << "    ";
//}
//
//void write(string a, short x, short y)
//{
//	gotoxy(x, y);
//	cout << a;
//}
///////////////Switch case////////////////////
//void do_0()
//{
//	tap = 0;
//	clearText();
//	textcolor(10);
//	gotoxy(14, 5);
//	cout << "--------------------NHAP VAT TU--------------------";
//
//	textcolor(7);
//	gotoxy(65, 2); cout << "OK";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(14);
//	write("Nhap ma vat tu    : ", VTx, VTy + 1);
//	write("Nhap ten vat tu   : ", VTx, VTy + 2);
//	write("Nhap don vi tinh  : ", VTx, VTy + 3);
//}
//void do_1()
//{
//	clearText();
//	textcolor(10);
//	gotoxy(7, 5);
//	cout << "--------------------DANH SACH VAT TU TON KHON--------------------";
//	textcolor(7);
//	gotoxy(64, 2); cout << "EDIT";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(14);
//
//	gotoxy(VTx, VTy + 3);
//	cout << "MAVT";
//
//	gotoxy(VTx + 20, VTy + 3);
//	cout << "TENVT";
//
//	gotoxy(VTx + 45, VTy + 3);
//	cout << "DVT";
//
//	gotoxy(VTx + 60, VTy + 3);
//	cout << "So Luong Ton";
//}
//void do_2()
//{
//	clearText();
//	textcolor(10);
//	gotoxy(13, 5);
//	cout << "--------------------NHAP NHAN VIEN--------------------";
//	textcolor(7);
//	gotoxy(65, 2); cout << "OK";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(14);
//	write("Nhap ma nhan vien      : ", VTx, VTy + 1);
//	write("Nhap ho                : ", VTx, VTy + 2);
//	write("Nhap ten               : ", VTx, VTy + 3);
//	write("Nhap phai (nam/nu)     : ", VTx, VTy + 4);
//
//
//}
//void do_3()
//{
//	clearText();
//	textcolor(10);
//	gotoxy(11, 5);
//	cout << "--------------------THONG TIN NHAN VIEN--------------------";
//	textcolor(7);
//	gotoxy(64, 2); cout << "EDIT";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(7);
//	gotoxy(0, VTy + 1);		// dong tren
//	cout << char(T_LEFT);
//	gotoxy(79, VTy + 1);
//	cout << char(T_RIGHT);
//	gotoxy(1, VTy + 1);
//	for (int i = 1; i <= 78; i++)
//	{
//		cout << char(TOP);
//	}
//	gotoxy(20, VTy + 1);
//	cout << char(T_TOP);
//	gotoxy(50, VTy + 1);
//	cout << char(T_TOP);
//	gotoxy(65, VTy + 1);
//	cout << char(T_TOP);
//
//	gotoxy(0, VTy + 3);		// dong duoi
//	cout << char(T_LEFT);
//	gotoxy(79, VTy + 3);
//	cout << char(T_RIGHT);
//	gotoxy(1, VTy + 3);
//	for (int i = 1; i <= 78; i++)
//	{
//		cout << char(TOP);
//	}
//	gotoxy(20, VTy + 3);
//	cout << char(CHUTHAP);
//	gotoxy(50, VTy + 3);
//	cout << char(CHUTHAP);
//	gotoxy(65, VTy + 3);
//	cout << char(CHUTHAP);
//
//	gotoxy(20, VTy + 2);	//dong giua
//	cout << char(MID);
//	gotoxy(50, VTy + 2);
//	cout << char(MID);
//	gotoxy(65, VTy + 2);
//	cout << char(MID);
//
//	for (int i = 4; i <= 33; i++)
//	{
//		gotoxy(20, VTy + i);	//dong giua
//		cout << char(MID);
//		gotoxy(50, VTy + i);
//		cout << char(MID);
//		gotoxy(65, VTy + i);
//		cout << char(MID);
//	}
//
//	gotoxy(20, VTy + 34);
//	cout << char(T_BOT);
//	gotoxy(50, VTy + 34);
//	cout << char(T_BOT);
//	gotoxy(65, VTy + 34);
//	cout << char(T_BOT);
//
//	gotoxy(8, VTy + 2);
//	cout << "MANV";
//	gotoxy(34, VTy + 2);
//	cout << "HO";
//	gotoxy(56, VTy + 2);
//	cout << "TEN";
//	gotoxy(71, VTy + 2);
//	cout << "PHAI";
//}
//char check;
//void do_4_a()
//{
//	clearText();
//	textcolor(10);
//	gotoxy(14, 5);
//	cout << "--------------------HOA DON NHAP--------------------";
//	textcolor(7);
//	gotoxy(65, 2); cout << "OK";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(14);
//	write("Ma nhan vien      : ", VTx, VTy + 3);
//	write("So hoa don        : ", VTx, VTy + 4);
//}
//void do_4_b()
//{
//	clearText();
//	textcolor(10);
//	gotoxy(14, 5);
//	cout << "--------------------HOA DON NHAP--------------------";
//	textcolor(7);
//	gotoxy(65, 2); cout << "OK";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(14);
//	write("Nhap ma vat tu      : ", VTx, VTy + 0);
//	write("So luong            : ", VTx, VTy + 1);
//	write("Don gia             : ", VTx, VTy + 2);
//	write("% VAT               : ", VTx, VTy + 3);
//
//	textcolor(7);
//	gotoxy(0, VTy + 4);
//	cout << char(T_LEFT);
//	gotoxy(79, VTy + 4);
//	cout << char(T_RIGHT);
//	gotoxy(1, VTy + 4);
//	for (int i = 1; i <= 78; i++)
//	{
//		cout << char(TOP);
//	}
//
//
//	gotoxy(VTx + 25, VTy + 4);
//	cout << char(T_TOP);
//	gotoxy(VTx + 25, 41);
//	cout << char(T_BOT);
//	for (int i = 5; i <= 33; i++)
//	{
//		gotoxy(VTx + 25, VTy + i);
//		cout << char(MID);
//	}
//	gotoxy(12, VTy + 5);
//	cout << "MAVT";
//	/////////////////////////
//	gotoxy(VTx + 40, VTy + 4);
//	cout << char(T_TOP);
//	gotoxy(VTx + 40, 41);
//	cout << char(T_BOT);
//	for (int i = 5; i <= 33; i++)
//	{
//		gotoxy(VTx + 40, VTy + i);
//		cout << char(MID);
//	}
//	gotoxy(32, VTy + 5);
//	cout << "SO LUONG";
//	/////////////////////////
//	gotoxy(VTx + 65, VTy + 4);
//	cout << char(T_TOP);
//	gotoxy(VTx + 25, 41);
//	cout << char(T_BOT);
//	for (int i = 5; i <= 33; i++)
//	{
//		gotoxy(VTx + 65, VTy + i);
//		cout << char(MID);
//	}
//	gotoxy(52, VTy + 5);
//	cout << "DON GIA";
//	/////////////////////////
//	gotoxy(72, VTy + 5);
//	cout << "% VAT";
//
//
//	gotoxy(0, VTy + 6);
//	cout << char(T_LEFT);
//	gotoxy(79, VTy + 6);
//	cout << char(T_RIGHT);
//	gotoxy(1, VTy + 6);
//	for (int i = 1; i <= 78; i++)
//	{
//		cout << char(TOP);
//	}
//	gotoxy(VTx + 25, VTy + 6);
//	cout << char(CHUTHAP);
//	gotoxy(VTx + 40, VTy + 6);
//	cout << char(CHUTHAP);
//	gotoxy(VTx + 65, VTy + 6);
//	cout << char(CHUTHAP);
//
//}
//
////////////////////////////////////////////////////////////////
//
//// MODULE 1: Nhap Vat Tu
//void NhapVT(DSVT &ds)
//{
//	VT tam;
//	int sl;
//	char c;
//	char kt;
//NhapMAVT:     //Nhãn MAVT
//	do
//	{
//		kt = NhapMA(tam.MAVT, VTx + 20, VTy + 1);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == DOWN && tam.MAVT != "")
//		{
//			goto NhapTENVT;
//		}
//	} while (tam.MAVT == "");
//
//NhapTENVT:
//	if (searchMAVT(ds, tam.MAVT) == true)
//	{
//		gotoxy(VTx, VTy + 10);
//		textcolor(224);
//		cout << "Trung ma vat tu!";
//		getch();
//		gotoxy(VTx, VTy + 10);
//		textcolor(14);
//		cout << "                               ";
//		gotoxy(VTx + 20, VTy + 1);
//		cout << "                                              ";
//		tam.MAVT = "";
//		goto NhapMAVT;
//	}
//	do
//	{
//		kt = Nhap(tam.TENVT, VTx + 20, VTy + 2);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == UP)
//		{
//			goto NhapMAVT;
//		}
//		else if (kt == DOWN && tam.TENVT != "")
//		{
//			goto NhapDVT;
//		}
//	} while (tam.TENVT == "");
//
//
//NhapDVT:
//	do
//	{
//		kt = Nhap(tam.DVT, VTx + 20, VTy + 3);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == UP)
//		{
//			goto NhapTENVT;
//		}
//		else if (kt == ENTER && tam.DVT != "")
//		{
//			gotoxy(65, 2);
//			textcolor(224);
//			cout << "OK";
//			goto KEY;
//		}
//	} while (tam.DVT == "");
//
//KEY:
//	do
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == RIGHT || c == LEFT)
//			{
//				if (wherey() == 2)
//				{
//					if (wherex() == 67)
//					{
//						gotoxy(65, 2);
//						textcolor(7); cout << "OK";
//						gotoxy(73, 2);
//						textcolor(224); cout << "EXIT";
//						textcolor(14);
//
//					}
//					else if (wherex() == 77)
//					{
//						gotoxy(73, 2);
//						textcolor(7); cout << "EXIT";
//						gotoxy(65, 2);
//						textcolor(224); cout << "OK";
//						textcolor(14);
//
//					}
//				}
//			}
//			if (c == DOWN)
//			{
//				gotoxy(73, 2);
//				textcolor(7); cout << "EXIT";
//				gotoxy(65, 2);
//				textcolor(7); cout << "OK";
//				textcolor(14);
//				goto NhapMAVT;
//			}
//		}
//	} while (c != ENTER);
//
//	if (wherex() == 67)
//	{
//		if (tam.MAVT != "" && tam.DVT != "" && tam.TENVT != "")
//		{
//			ds.vt[ds.key].MAVT = tam.MAVT;
//			ds.vt[ds.key].TENVT = tam.TENVT;
//			ds.vt[ds.key].DVT = tam.DVT;
//			ds.key++;
//			gotoxy(VTx, VTy + 10);
//			cout << "Luu thanh cong";
//			_getch();
//		}
//		else
//		{
//			gotoxy(65, 2);
//			textcolor(7); cout << "OK";
//			textcolor(14);
//			gotoxy(VTx, VTy + 10);
//			cout << "Chua dien du thong tin!";
//			Sleep(1000);
//			gotoxy(VTx, VTy + 10);
//			cout << "                       ";
//			goto NhapMAVT;
//		}
//	}
//	else if (wherex() == 78)
//	{
//		tam.MAVT = "";
//		tam.TENVT = "";
//		tam.DVT = "";
//		tap = -1;
//		for (int i = 1; i <= 4; i++)
//		{
//			gotoxy(VTx + 20, VTy + i);
//			cout << "                                                                    ";
//		}
//	}
//	tap = -1;
//	textcolor(7);
//
//
//}
//
//// EDIT MODULE 1
//void EDIT_1(DSVT &ds)
//{
//	clearText();
//	string temp;
//	VT tam;
//	char kt, c;
//	textcolor(10);
//	gotoxy(14, 5);
//	cout << "------------------EDIT THONG TIN VAT TU------------------";
//	textcolor(7);
//	gotoxy(65, 2); cout << "OK";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(14);
//	write("Nhap MAVT can EDIT: ", VTx, VTy + 1);
//
//	do
//	{
//		kt = NhapMA(temp, VTx + 20, VTy + 1);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//	} while (temp == "");
//
//	if (searchMAVT(ds, temp))
//	{
//		textcolor(14);
//		write("Nhap ma vat tu   (edit): ", VTx, VTy + 5);
//		write("Nhap ten vat tu  (edit): ", VTx, VTy + 6);
//		write("Nhap don vi tinh (edit): ", VTx, VTy + 7);
//
//	NhapMAVT:
//		do
//		{
//			kt = NhapMA(tam.MAVT, VTx + 25, VTy + 5);
//			if (kt == ESC)
//			{
//				gotoxy(73, 2);
//				textcolor(224);
//				cout << "EXIT";
//				goto KEY;
//			}
//			if (kt == DOWN && tam.MAVT != "")
//			{
//				goto NhapTENVT;
//			}
//		} while (tam.MAVT == "");
//
//	NhapTENVT:
//		if (searchMAVT(ds, tam.MAVT) == true)
//		{
//			gotoxy(VTx, VTy + 10);
//			textcolor(224);
//			cout << "Trung ma vat tu!";
//			getch();
//			gotoxy(VTx, VTy + 10);
//			textcolor(14);
//			cout << "                               ";
//			gotoxy(VTx + 20, VTy + 1);
//			cout << "                                              ";
//			tam.MAVT = "";
//			goto NhapMAVT;
//		}
//		do
//		{
//			kt = Nhap(tam.TENVT, VTx + 25, VTy + 6);
//			if (kt == ESC)
//			{
//				gotoxy(73, 2);
//				textcolor(224);
//				cout << "EXIT";
//				goto KEY;
//			}
//			if (kt == UP)
//			{
//				goto NhapMAVT;
//			}
//			else if (kt == ENTER && tam.TENVT != "")
//			{
//				goto NhapDVT;
//			}
//		} while (tam.TENVT == "");
//
//
//	NhapDVT:
//		do
//		{
//			kt = Nhap(tam.DVT, VTx + 25, VTy + 7);
//			if (kt == ESC)
//			{
//				gotoxy(73, 2);
//				textcolor(224);
//				cout << "EXIT";
//				goto KEY;
//			}
//			if (kt == UP)
//			{
//				goto NhapTENVT;
//			}
//			else if (kt == ENTER && tam.DVT != "")
//			{
//				gotoxy(65, 2);
//				textcolor(224);
//				cout << "OK";
//				goto KEY;
//			}
//		} while (tam.DVT == "");
//
//
//	KEY:
//		do
//		{
//			c = getch();
//			if (c == -32)
//			{
//				c = getch();
//				if (c == RIGHT || c == LEFT)
//				{
//					if (wherey() == 2)
//					{
//						if (wherex() == 67)
//						{
//							gotoxy(65, 2);
//							textcolor(7); cout << "OK";
//							gotoxy(73, 2);
//							textcolor(224); cout << "EXIT";
//							textcolor(14);
//
//						}
//						else if (wherex() == 77)
//						{
//							gotoxy(73, 2);
//							textcolor(7); cout << "EXIT";
//							gotoxy(65, 2);
//							textcolor(224); cout << "OK";
//							textcolor(14);
//
//						}
//					}
//				}
//				if (c == DOWN)
//				{
//					gotoxy(73, 2);
//					textcolor(7); cout << "EXIT";
//					gotoxy(65, 2);
//					textcolor(7); cout << "OK";
//					textcolor(14);
//					goto NhapMAVT;
//				}
//			}
//		} while (c != ENTER);
//
//		if (wherex() == 67)
//		{
//			if (tam.MAVT != "" && tam.DVT != "" && tam.TENVT != "")
//			{
//				ds.vt[ds.key].MAVT = tam.MAVT;
//				ds.vt[ds.key].TENVT = tam.TENVT;
//				ds.vt[ds.key].DVT = tam.DVT;
//				ds.key++;
//				gotoxy(VTx, VTy + 10);
//				cout << "Luu thanh cong";
//				_getch();
//			}
//			else
//			{
//				gotoxy(65, 2);
//				textcolor(7); cout << "OK";
//				textcolor(14);
//				gotoxy(VTx, VTy + 10);
//				cout << "Chua dien du thong tin!";
//				Sleep(1000);
//				gotoxy(VTx, VTy + 10);
//				cout << "                       ";
//				goto NhapMAVT;
//			}
//		}
//		else
//		{
//			tam.MAVT = "";
//			tam.TENVT = "";
//			tam.DVT = "";
//			tap = -1;
//			for (int i = 1; i <= 4; i++)
//			{
//				gotoxy(VTx + 20, VTy + i);
//				cout << "                                                                    ";
//			}
//		}
//		tap = -1;
//		textcolor(7);
//	}
//}
//
////MODULE 2: In VT ton kho 
//void InTonKho(DSVT ds)
//{
//	char c;
//	textcolor(14);
//	for (int i = 0; i < ds.key; i++)
//	{
//		if (ds.vt[i].SLT > 0)
//		{
//			gotoxy(VTx, VTy + 4 + i);
//			cout << ds.vt[i].MAVT;
//
//			gotoxy(VTx + 20, VTy + 4 + i);
//			cout << ds.vt[i].TENVT;
//
//			gotoxy(VTx + 45, VTy + 4 + i);
//			cout << ds.vt[i].DVT;
//
//			gotoxy(VTx + 60, VTy + 4 + i);
//			cout << ds.vt[i].SLT;
//		}
//	}
//	gotoxy(64, 2);
//	textcolor(224); cout << "EDIT";
//	textcolor(14);
//	do
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == RIGHT || c == LEFT)
//			{
//				if (wherey() == 2)
//				{
//					if (wherex() == 68)
//					{
//						gotoxy(64, 2);
//						textcolor(7); cout << "EDIT";
//						gotoxy(73, 2);
//						textcolor(224); cout << "EXIT";
//						textcolor(14);
//
//					}
//					else if (wherex() == 77)
//					{
//						gotoxy(73, 2);
//						textcolor(7); cout << "EXIT";
//						gotoxy(64, 2);
//						textcolor(224); cout << "EDIT";
//						textcolor(14);
//
//					}
//				}
//
//			}
//		}
//	} while (c != ENTER);
//
//	if (wherex() == 68)
//	{
//		EDIT_1(ds);
//	}
//
//	textcolor(7);
//	tap = -1;
//}
//
////MODULE 3:  Nhap NV 
//void NhapNV(NV* &Root)
//{
//	textcolor(14);
//	char c;
//	char kt;
//	InfoNV a;
//	string tam;
//	int temp;
//
//NhapMANV:
//	do
//	{
//		kt = NhapMA(a.MANV, VTx + 25, VTy + 1);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == DOWN && a.MANV != "")
//		{
//			goto NhapHO;
//		}
//	} while (a.MANV == "");
//
//NhapHO:
//	if (searchNV(Root, a.MANV) != NULL)
//	{
//		gotoxy(VTx, VTy + 10);
//		textcolor(224);
//		cout << "Trung ma nhan vien!";
//		Sleep(1000);
//		gotoxy(VTx, VTy + 10);
//		textcolor(14);
//		cout << "                               ";
//		gotoxy(VTx + 25, VTy + 1);
//		cout << "                               ";
//		a.MANV = "";
//		goto NhapMANV;
//	}
//	do
//	{
//		kt = Nhap(a.HO, VTx + 25, VTy + 2);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == UP)
//		{
//			goto NhapMANV;
//		}
//		if (kt == DOWN && a.HO != "")
//		{
//			goto NhapTEN;
//		}
//	} while (a.HO == "");
//
//
//NhapTEN:
//	do
//	{
//		kt = Nhap(a.TEN, VTx + 25, VTy + 3);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == UP)
//		{
//			goto NhapHO;
//		}
//		if (kt == DOWN && a.TEN != "")
//		{
//			goto NhapPHAI;
//		}
//	} while (a.TEN == "");
//
//NhapPHAI:
//
//	do
//	{
//		kt = Nhap(tam, VTx + 25, VTy + 4);
//		chuanHoaChuoi(tam);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (tam == "Nam")
//			a.PHAI = 1;
//		else if (tam == "Nu")
//			a.PHAI = 0;
//		else
//		{
//			gotoxy(VTx + 25, VTy + 4);
//			cout << "                             ";
//			tam = "";
//			goto NhapPHAI;
//		}
//
//		if (kt == UP)
//		{
//			goto NhapTEN;
//		}
//		else if ((kt == ENTER) && tam != "")
//		{
//			gotoxy(65, 2);
//			textcolor(224); cout << "OK";
//		}
//	} while (tam == "");
//
//KEY:
//	do
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == RIGHT || c == LEFT)
//			{
//				if (wherey() == 2)
//				{
//					if (wherex() == 67)
//					{
//						gotoxy(65, 2);
//						textcolor(7); cout << "OK";
//						gotoxy(73, 2);
//						textcolor(224); cout << "EXIT";
//						textcolor(14);
//
//					}
//					else if (wherex() == 77)
//					{
//						gotoxy(73, 2);
//						textcolor(7); cout << "EXIT";
//						gotoxy(65, 2);
//						textcolor(224); cout << "OK";
//						textcolor(14);
//
//					}
//				}
//
//			}
//		}
//	} while (c != ENTER);
//
//
//
//	if (wherex() == 67)
//	{
//		if (a.HO != ""&& a.MANV != "" &&a.TEN != ""&& tam != "")
//		{
//			chuanHoaChuoi(a.HO);
//			chuanHoaChuoi(a.TEN);
//			addNV(Root, a);
//
//			gotoxy(VTx, VTy + 10);
//			textcolor(224);
//			cout << "Luu thanh cong";
//			getch();
//		}
//		else
//		{
//			gotoxy(65, 2);
//			textcolor(7); cout << "OK";
//			textcolor(14);
//			gotoxy(VTx, VTy + 10);
//			cout << "Chua dien du thong tin!";
//			Sleep(1000);
//			gotoxy(VTx, VTy + 10);
//			cout << "                       ";
//			goto NhapMANV;
//		}
//
//	}
//
//	textcolor(7);
//	tap = -1;
//}
//
//// EDIT MODULE 3
//void EDIT_3(NV* &Root)
//{
//	system("cls");
//	textcolor(7);
//	veKhung();
//	clearText();
//	NV* a, *nv;
//	string temp, tam;
//	char kt, c;
//	textcolor(10);
//	gotoxy(12, 5);
//	cout << "------------------EDIT THONG TIN NHAN VIEN------------------";
//	textcolor(7);
//	gotoxy(65, 2); cout << "OK";
//	gotoxy(73, 2); cout << "EXIT";
//
//	textcolor(14);
//	write("Nhap MANV can EDIT: ", VTx, VTy + 1);
//	do
//	{
//		kt = NhapMA(temp, VTx + 20, VTy + 1);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//	} while (temp == "");
//
//
//	if (searchNV(Root, temp) != NULL)
//	{
//		textcolor(14);
//		write("Nhap ma nhan vien (edit): ", VTx, VTy + 5);
//		write("Nhap ho           (edit): ", VTx, VTy + 5);
//		write("Nhap ten          (edit): ", VTx, VTy + 5);
//		write("Nhap phai(nam/nu) (edit): ", VTx, VTy + 5);
//
//		nv = searchNV(Root, temp);
//	NhapMANV:
//		do
//		{
//			kt = NhapMA(a->info.MANV, VTx + 25, VTy + 1);
//			if (kt == ESC)
//			{
//				gotoxy(73, 2);
//				textcolor(224);
//				cout << "EXIT";
//				goto KEY;
//			}
//			if (kt == DOWN && a->info.MANV != "")
//			{
//				goto NhapHO;
//			}
//		} while (a->info.MANV == "");
//
//	NhapHO:
//		if (searchNV(Root, a->info.MANV))
//		{
//			gotoxy(VTx, VTy + 10);
//			textcolor(224);
//			cout << "Trung ma nhan vien!";
//			Sleep(1000);
//			gotoxy(VTx, VTy + 10);
//			textcolor(14);
//			cout << "                               ";
//			gotoxy(VTx + 25, VTy + 1);
//			cout << "                               ";
//			a->info.MANV = "";
//			goto NhapMANV;
//		}
//
//		do
//		{
//			kt = Nhap(a->info.HO, VTx + 25, VTy + 2);
//			if (kt == ESC)
//			{
//				gotoxy(73, 2);
//				textcolor(224);
//				cout << "EXIT";
//				goto KEY;
//			}
//			if (kt == UP)
//			{
//				goto NhapMANV;
//			}
//			if (kt == DOWN && a->info.HO != "")
//			{
//				goto NhapTEN;
//			}
//		} while (a->info.HO == "");
//
//
//	NhapTEN:
//		do
//		{
//			kt = Nhap(a->info.TEN, VTx + 25, VTy + 3);
//			if (kt == ESC)
//			{
//				gotoxy(73, 2);
//				textcolor(224);
//				cout << "EXIT";
//				goto KEY;
//			}
//			if (kt == UP)
//			{
//				goto NhapHO;
//			}
//			if (kt == DOWN && a->info.TEN != "")
//			{
//				goto NhapPHAI;
//			}
//		} while (a->info.TEN == "");
//
//	NhapPHAI:
//
//		do
//		{
//			kt = Nhap(tam, VTx + 25, VTy + 4);
//			chuanHoaChuoi(tam);
//			if (kt == ESC)
//			{
//				gotoxy(73, 2);
//				textcolor(224);
//				cout << "EXIT";
//				goto KEY;
//			}
//			if (tam == "Nam")
//				a->info.PHAI = 1;
//			else if (tam == "Nu")
//				a->info.PHAI = 0;
//			else
//			{
//				gotoxy(VTx + 25, VTy + 4);
//				cout << "                             ";
//				tam = "";
//				goto NhapPHAI;
//			}
//
//			if (kt == UP)
//			{
//				goto NhapTEN;
//			}
//			else if ((kt == ENTER) && tam != "")
//			{
//				gotoxy(65, 2);
//				textcolor(224); cout << "OK";
//			}
//		} while (tam == "");
//
//	KEY:
//		do
//		{
//			c = getch();
//			if (c == -32)
//			{
//				c = getch();
//				if (c == RIGHT || c == LEFT)
//				{
//					if (wherey() == 2)
//					{
//						if (wherex() == 67)
//						{
//							gotoxy(65, 2);
//							textcolor(7); cout << "OK";
//							gotoxy(73, 2);
//							textcolor(224); cout << "EXIT";
//							textcolor(14);
//
//						}
//						else if (wherex() == 77)
//						{
//							gotoxy(73, 2);
//							textcolor(7); cout << "EXIT";
//							gotoxy(65, 2);
//							textcolor(224); cout << "OK";
//							textcolor(14);
//
//						}
//					}
//
//				}
//			}
//		} while (c != ENTER);
//
//
//
//		if (wherex() == 67)
//		{
//			if (a->info.HO != ""&& a->info.MANV != "" &&a->info.TEN != ""&& tam != "")
//			{
//				chuanHoaChuoi(a->info.HO);
//				chuanHoaChuoi(a->info.TEN);
//
//				nv->info.MANV = a->info.MANV;
//				nv->info.TEN = a->info.TEN;
//				nv->info.HO = a->info.HO;
//				nv->info.PHAI = a->info.PHAI;
//
//				gotoxy(VTx, VTy + 10);
//				textcolor(224);
//				cout << "Luu thanh cong";
//				getch();
//			}
//			else
//			{
//				gotoxy(65, 2);
//				textcolor(7); cout << "OK";
//				textcolor(14);
//				gotoxy(VTx, VTy + 10);
//				cout << "Chua dien du thong tin!";
//				Sleep(1000);
//				gotoxy(VTx, VTy + 10);
//				cout << "                       ";
//				goto NhapMANV;
//			}
//
//		}
//	}
//
//}
//
////MODULE 4: In danh sach nhan vien LNR
//int chay = 0;
//void InNV(NV* Root)
//{
//	if (Root != NULL)
//	{
//		InNV(Root->pleft);
//		gotoxy(VTx + 2, VTy + 4 + chay);
//		cout << Root->info.MANV;
//		gotoxy(VTx + 22, VTy + 4 + chay);
//		cout << Root->info.HO;
//		gotoxy(VTx + 53, VTy + 4 + chay);
//		cout << Root->info.TEN;
//		gotoxy(VTx + 68, VTy + 4 + chay);
//		if (Root->info.PHAI == 1)
//			cout << "Nam";
//		else
//			cout << "Nu";
//		chay++;
//		InNV(Root->pright);
//	}
//
//}
//void control3(NV* Root)
//{
//	InNV(Root);
//	char c;
//	gotoxy(64, 2);
//	textcolor(224); cout << "EDIT";
//	textcolor(14);
//	do
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == RIGHT || c == LEFT)
//			{
//				if (wherey() == 2)
//				{
//					if (wherex() == 68)
//					{
//						gotoxy(64, 2);
//						textcolor(7); cout << "EDIT";
//						gotoxy(73, 2);
//						textcolor(224); cout << "EXIT";
//						textcolor(14);
//
//					}
//					else if (wherex() == 77)
//					{
//						gotoxy(73, 2);
//						textcolor(7); cout << "EXIT";
//						gotoxy(64, 2);
//						textcolor(224); cout << "EDIT";
//						textcolor(14);
//					}
//				}
//
//			}
//		}
//	} while (c != ENTER);
//
//	if (wherex() == 68)
//	{
//		EDIT_3(Root);
//	}
//	if (wherex() == 77)
//		tap = -1;
//
//	textcolor(7);
//	tap = -1;
//}
//
//// Điều khiển do_4_b() của MODULE 5
//void control4()
//{
//	char kt, c;
//	string t1 = "", t2 = "", t3 = "", t4 = "";
//	textcolor(14);
//NhapMAVT:
//	do
//	{
//		kt = NhapMA(t1, VTx + 22, VTy + 0);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == DOWN  && t1 != "")
//		{
//			goto NhapSL;
//		}
//	} while (t1 == "");
//
//NhapSL:
//	do
//	{
//		kt = NhapMA(t2, VTx + 22, VTy + 1);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == DOWN  && t2 != "")
//		{
//			goto NhapDG;
//		}
//	} while (t2 == "");
//
//NhapDG:
//	do
//	{
//		kt = NhapMA(t3, VTx + 22, VTy + 2);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == DOWN  && t3 != "")
//		{
//			goto NhapVAT;
//		}
//	} while (t3 == "");
//
//NhapVAT:
//	do
//	{
//		kt = NhapMA(t4, VTx + 22, VTy + 3);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == DOWN  && t4 != "")
//		{
//			gotoxy(67, 2);
//			textcolor(224); cout << "OK";
//			textcolor(7);
//			goto KEY;
//		}
//	} while (t4 == "");
//KEY:
//	do
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == RIGHT || c == LEFT)
//			{
//				if (wherey() == 2)
//				{
//					if (wherex() == 67)
//					{
//						gotoxy(65, 2);
//						textcolor(7); cout << "OK";
//						gotoxy(73, 2);
//						textcolor(224); cout << "EXIT";
//						textcolor(7);
//
//					}
//					else if (wherex() == 77)
//					{
//						gotoxy(73, 2);
//						textcolor(7); cout << "EXIT";
//						gotoxy(65, 2);
//						textcolor(224); cout << "OK";
//						textcolor(7);
//
//					}
//				}
//
//			}
//		}
//	} while (c != ENTER);
//}
////MODULE 5: 
//void LapHoaDonNhap(NV* &Root)
//{
//	InfoHD HD;
//	NV* nv;
//	Date time;
//	string a = "", b = "";
//	char kt, c, l;
//	setdate(time, 45, VTy + 1);
//NhapMANV:
//	do
//	{
//		kt = NhapMA(a, VTx + 20, VTy + 3);
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if ((kt == DOWN || kt == UP) && a != "")
//		{
//			goto NhapSoHD;
//		}
//	} while (a == "");
//
//NhapSoHD:
//	if (!searchNV(Root, a))
//	{
//		gotoxy(VTx, VTy + 10);
//		cout << "Chua co NV nay!";
//		Sleep(1000);
//		gotoxy(VTx, VTy + 10);
//		cout << "                ";
//		goto NhapMANV;
//	}
//	else
//	{
//		nv = searchNV(Root, a);
//		HD.LOAI = 'N';
//	}
//	do
//	{
//		kt = NhapMA(b, VTx + 20, VTy + 4);
//		if (TimSoHD(nv, b))
//		{
//			gotoxy(VTx, VTy + 10);
//			cout << "Trung SoHD vui long nhap lai!";
//			Sleep(1000);
//			gotoxy(VTx, VTy + 10);
//			cout << "                             ";
//			goto NhapSoHD;
//		}
//		if (kt == ESC)
//		{
//			gotoxy(73, 2);
//			textcolor(224);
//			cout << "EXIT";
//			goto KEY;
//		}
//		if (kt == ENTER && a != "")
//		{
//			gotoxy(67, 2);
//			textcolor(224); cout << "OK";
//			textcolor(7);
//			goto KEY;
//		}
//	} while (a == "");
//
//KEY:
//	do
//	{
//		c = getch();
//		if (c == -32)
//		{
//			c = getch();
//			if (c == RIGHT || c == LEFT)
//			{
//				if (wherey() == 2)
//				{
//					if (wherex() == 67)
//					{
//						gotoxy(65, 2);
//						textcolor(7); cout << "OK";
//						gotoxy(73, 2);
//						textcolor(224); cout << "EXIT";
//						textcolor(7);
//
//					}
//					else if (wherex() == 77)
//					{
//						gotoxy(73, 2);
//						textcolor(7); cout << "EXIT";
//						gotoxy(65, 2);
//						textcolor(224); cout << "OK";
//						textcolor(7);
//
//					}
//				}
//
//			}
//		}
//	} while (c != ENTER);
//
//
//	if (wherex() == 67)
//	{
//		if (a != "" && b != "")
//		{
//			do_4_b();
//			control4();
//
//		}
//		else
//		{
//			gotoxy(65, 2);
//			textcolor(7); cout << "OK";
//			textcolor(14);
//			gotoxy(VTx, VTy + 10);
//			cout << "Chua dien du thong tin!";
//			Sleep(1000);
//			gotoxy(VTx, VTy + 10);
//			cout << "                       ";
//			goto NhapMANV;
//		}
//	}
//	else if (wherex() == 77)
//	{
//		textcolor(7);
//		tap = -1;
//	}
//
//
//
//}
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//int main()
//{
//	newMenu();
//	DSVT ds;
//	NV * Root = NULL;
//	HD* First = NULL;
//
//Start:
//	veKhung();
//	xuatMenu(0);
//	int i = 0;
//	do
//	{
//		Phim(i);
//		switch (i)
//		{
//		case 0:
//		{
//			do_0();
//			NhapVT(ds);
//			break;
//		}
//		case 1:
//		{
//			do_1();
//			InTonKho(ds);
//			break;
//		}
//		case 2:
//		{
//			do_2();
//			NhapNV(Root);
//			break;
//		}
//		case 3:
//		{
//			do_3();
//			control3(Root);
//			break;
//		}
//		case 4:
//		{
//			do_4_a();
//			LapHoaDonNhap(Root);
//			break;
//		}
//		case 5:
//		{
//
//
//		}
//		}
//		if (tap == -1)
//			goto Start;
//	} while (1);
//
//	return 0;
//
//}
