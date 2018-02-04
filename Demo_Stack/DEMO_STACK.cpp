 #include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<myfunc.h>
#define SIZEMENU 5
#define VITRIX 2
#define VITRIY 2
using namespace std;
vector<string> Menu;
int Top1 = -1, Top2 = -1;
// Khởi tạo menu
void getMenu()

{
	Menu.resize(SIZEMENU);
	Menu[0] = "1. Push stack 1 ";
	Menu[1] = "2. Pop stack 1  ";
	Menu[2] = "3. Push stack 2 ";
	Menu[3] = "4. Pop stack 2  ";
	Menu[4] = "5. Exit         ";
}
// Tô màu Menu
void xuatMenu(int ViTriToMau)
{
	for (int i = 0; i < SIZEMENU; i++)
	{
		gotoxy(VITRIX, VITRIY + i);
		if (i == ViTriToMau)
		{
			textcolor(151);
		}
		else textcolor(7);
		cout << Menu[i];
	}
}
// Hàm tạo Menu động
void toMau(int &i)
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
				if (i == SIZEMENU - 1)
				{
					i = -1;
				}
				xuatMenu(++i);
			}
			if (c == 72)
			{
				if (i == 0)
				{
					i = SIZEMENU;
				}
				xuatMenu(--i);
			}
		}
	} while (c != 13);
}
// Vẽ khung 
void VeKhung()
{
	textcolor(14);
	for (int i = 25; i <= 75; i++)
	{
		if (i % 5 == 0)
		{
			gotoxy(i, 3);
			cout << char(203);
			gotoxy(i, 5);
			cout << char(202);
			gotoxy(i, 4);
			cout << char(186);

		}
		else
		{
			gotoxy(i, 3);
			cout << char(205);
			gotoxy(i, 5);
			cout << char(205);
		}
	}
	gotoxy(25, 3);
	cout << char(201);
	gotoxy(25, 5);
	cout << char(200);
	gotoxy(75, 3);
	cout << char(187);
	gotoxy(75, 5);
	cout << char(188);
	// Vẽ ô chứa giá trị 
	for (int i = 30; i <= 35; i++)
	{
		gotoxy(i, 11);
		cout << char(205);
		gotoxy(i, 13);
		cout << char(205);
		if (i % 5 == 0)
		{
			gotoxy(i, 12);
			cout << char(186);
		}
	}
	gotoxy(30, 11);
	cout << char(201);
	gotoxy(30, 13);
	cout << char(200);
	gotoxy(35, 11);
	cout << char(187);
	gotoxy(35, 13);
	cout << char(188);
	textcolor(7);
}
// Vẽ hai con trỏ Stack1
void VeConTro1(int x)
{
	gotoxy(x, 6);
	textcolor(9);
	cout << char(6);
	textcolor(7);
}
// Vẽ hai con trỏ Stack2
void VeConTro2(int x)
{
	gotoxy(x, 6);
	textcolor(15);
	cout << char(6);
	textcolor(7);
}

void Push1(int x)
{
	gotoxy(27 + 5 * ++Top1, 4);
	cout << x;
}

void Push2(int x)
{
	gotoxy(72 - 5 * ++Top2, 4);
	cout << x;
}

void Pop1()
{
	gotoxy(27 + 5 * Top1--, 4);
	cout << "   ";
}

void Pop2()
{
	gotoxy(72 - 5 * Top2--, 4);
	cout << "   ";
}

void Nhap(int &x)
{
	ShowCur(1);
	gotoxy(32, 12);
	cin >> x;
	gotoxy(32, 12);
	cout << "   ";
	ShowCur(0);
}
// Hàm kiểm tra thao tác Push
bool Full()
{
	return Top1 == 9 || Top2 == 9 || Top1 + Top2 == 8;
	// True: Full
}

void LoiPop()
{
	gotoxy(45, 8);
	textcolor(12);
	cout << "Pop fail! ";
	textcolor(7);
	Sleep(300);
	gotoxy(45, 8);
	cout << "          ";
}

int main()
{
	getMenu();
	int i = 0;
	int x;		// Biến nhập
	ShowCur(0);	// Tắt con trỏ 
	xuatMenu(0);
	VeKhung();
	VeConTro1(27 + 5 * Top1);
	VeConTro2(72 - 5 * Top2);
	do
	{
		toMau(i);
		if (i == 0 || i == 2)
		{
			if (!Full())
			{
				if (i == 0)
				{
					gotoxy(27 + 5 * Top1, 6);
					cout << " ";
					VeConTro1(27 + 5 * (Top1 + 1));
					Nhap(x);
					Push1(x);

				}
				else
				{
					gotoxy(72 - 5 * Top2, 6);
					cout << " ";
					VeConTro2(72 - 5 * (Top2 + 1));
					Nhap(x);
					Push2(x);
				}
			}
			else
			{
				gotoxy(45, 8);
				textcolor(12);
				cout << "Stack full!";
				textcolor(7);
				Sleep(300);
				gotoxy(45, 8);
				cout << "           ";
			}
		}
		else
		{
			if (i == 1)
			{
				if (Top1 == -1)
				{
					LoiPop();
				}
				else
				{
					gotoxy(27 + 5 * Top1, 6);
					cout << " ";
					VeConTro1(27 + 5 * (Top1 - 1));
					Pop1();
				}
			}
			else if (i == 3)
			{
				if (Top2 == -1)
				{
					LoiPop();
				}
				else
				{
					gotoxy(72 - 5 * Top2, 6);
					cout << " ";
					VeConTro2(72 - 5 * (Top2 - 1));
					Pop2();
				}
			}
		}
	} while (i != 4);
	return 0;
}
