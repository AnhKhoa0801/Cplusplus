#include<iostream>
#include<Windows.h>
#include<time.h>
#include<vector>
#include<conio.h>
using namespace std;
char a[20][20]={' '};
int PLAYER = 0, COMP = 0;
// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
// Hàm dịch chuyển con trỏ console đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
// Hàm tô màu 
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

struct Word
{
	char KyTu;
	int i;
	int j;
};
vector<Word> List;
void VeKhung()
{
	for (int i = 0; i < 20; i++)
	{
		a[0][i] = char(219);
		a[19][i] = char(219);
		a[i][0] = char(219);
		a[i][19] = char(219);
	}
}
// Loại bỏ phần tử đầu danh sách 
void BoPhanTuDau()
{
	int Size = List.size();
	for (int i = 0; i < Size - 1; i++)
	{
		List[i] = List[i + 1];
	}
	List.pop_back(); 
}
// Vẽ chữ random 
void VeChu()		
{
	int W = 97 + rand() % (122 - 97 + 1);
	int j = 1 + rand() % (18 - 1 + 1);
	a[1][j] = W;
	Word Temp;
	Temp.KyTu = W;
	Temp.i = 1;
	Temp.j = j;
	List.push_back(Temp);
}

void DiChuyen()
{
	for (int i = 0; i < List.size(); i++)
	{
		if (List[i].i == 18)
		{
			a[List[i].i][List[i].j] = ' ';
			COMP++;
			BoPhanTuDau();
			return DiChuyen();
		}
		a[List[i].i + 1][List[i].j] = a[List[i].i][List[i].j];
		a[List[i].i][List[i].j] = ' ';
		List[i].i++;
	}
}

void NhapChu()
{
	if (_kbhit())
	{
		char c = _getch();
		if (c == List[0].KyTu)
		{
			PLAYER++;
			a[List[0].i][List[0].j] = ' ';
			BoPhanTuDau();
		}
	}
}

void Xuat()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (a[i][j] >= 97 && a[i][j] <= 122)
			{
				textcolor(14);
			}
			cout << a[i][j];
			textcolor(7);
		}
		cout << endl;
	}
}

int main()
{
	int m = 0;
	ShowCur(0);
	VeKhung();
	gotoxy(1, 24);
	cout << "PLAYER: " << PLAYER;
	gotoxy(70, 24);
	cout << "COMP: " << COMP;
	gotoxy(1, 1);
	srand(time(0));
	while (true)
	{
		if (m % 6 == 0)
		{
			VeChu();
		}
		NhapChu();
		Xuat();
		gotoxy(1, 24);
		cout << "PLAYER: " << PLAYER;
		gotoxy(70, 24);
		cout << "COMP: " << COMP;
		gotoxy(1, 1);
		/*if (PLAYER == 5 || COMP == 5)
		{
			break;
		}*/
		Sleep(150);
		DiChuyen();
		XoaManHinh();
		m++;
	}
	system("cls");
	if (PLAYER == 5)
	{
		cout << "You win" << endl;
	}
	else cout << "Computer win" << endl;
	system("pause");
	return 0;
}