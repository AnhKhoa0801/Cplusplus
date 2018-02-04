#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

struct Disk
{
	int idx;			// Đĩa thứ n
	int x;
	int y;
};

vector<Disk> A;			// Mảng chứa các dĩa trong cột A
vector<Disk> B;
vector<Disk> C;
int TOP;				// Vị trí của đỉnh cột 
int SODIA;
int TIME = 400;			// Thời gian ngủ	[25,400]
int X_A; 				// Vị trí X của cột A
int X_B; 				// Vị trí X của cột B
int X_C;				// Vị trí X của cột C
int KC;					// Khoảng cách giữa hai dĩa
int VITRIVECHAN;

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
// Hàm vẽ chân trụ
void VeChan(int n)
{
	int SoKhoangTrang = 3 + 2 * n - 5 + 1 + 2;
	textcolor(128);
	for (int i = 1; i <= SoKhoangTrang; i++)
	{
		if (i == SoKhoangTrang / 2 + 1)
		{
			cout << "Cot A";
		}
		else
		{
			cout << " ";
		}
	}
	textcolor(7);
	cout << "  ";
	textcolor(140);
	for (int i = 1; i <= SoKhoangTrang; i++)
	{
		if (i == SoKhoangTrang / 2 + 1)
		{
			cout << "Cot B";
		}
		else
		{
			cout << " ";
		}
	}
	textcolor(7);
	cout << "  ";
	textcolor(142);
	for (int i = 1; i <= SoKhoangTrang; i++)
	{
		if (i == SoKhoangTrang / 2 + 1)
		{
			cout << "Cot C";
		}
		else
		{
			cout << " ";
		}
	}
	textcolor(7);
}
// Hàm vẽ cột trụ 
void VeCot(int n)
{
	int SoCot = n + 2;
	int SoKhoangTrang = 3 + 2 * n - 5 + 1 + 2;
	int X = (3 + 2 * SODIA + 2) / 2;
	VITRIVECHAN = (80 - (3 + 2 * SODIA + 2) * 3 - 4) / 2;
	X_A = X + VITRIVECHAN;
	X_B = X + 2 * X + 1 + 2 + VITRIVECHAN;
	X_C = X_B + 2 * X + 1 + 2;
	KC = X_B - X_A;
	textcolor(128);
	for (int i = 1; i <= SoCot; i++)
	{
		gotoxy(X_A, 24 - i);
		cout << " ";
	}
	for (int i = 1; i <= SoCot; i++)
	{
		gotoxy(X_B, 24 - i);
		cout << " ";
	}
	for (int i = 1; i <= SoCot; i++)
	{
		gotoxy(X_C, 24 - i);
		cout << " ";
	}
	textcolor(7);
}
// Hàm vẽ đĩa
void VeDia(Disk a, char c)		// Number: dĩa thứ n (đếm từ 1)
{
	gotoxy(a.x, a.y);
	textcolor(a.idx);
	a.idx--;
	int length = 3 + 2 * a.idx;
	for (int i = 1; i <= length; i++)
	{
		cout << c;
	}
	textcolor(7);
}
// Hàm vẽ tháp 
void VeThap(int n)
{
	VeCot(n);
	gotoxy(VITRIVECHAN, 24);
	VeChan(n);
	int temp = n;
	Disk T;
	for (int i = 1; i <= n; i++)
	{
		T.x = VITRIVECHAN + 1 + i;
		T.y = 24 - i;
		T.idx = temp--;
		VeDia(T, 219);
		A.push_back(T);
	}
}
// Hàm thay đổi tốc độ 
void TangGiamTIME()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (TIME != 25)
		{
			TIME /= 2;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (TIME != 400)
		{
			TIME *= 2;
		}
	}
}
// Hàm di chuyển đĩa 
void Move(vector<Disk> &Start, char St, vector<Disk> &End, char En)		// 3,24
{
	int size_S = Start.size();
	Disk temp = Start[size_S - 1];		// Lấy ra ptử cuối cùng 
	int x = X_A;
	if (St == 'B')
	{
		x = X_B;
	}
	else if (St == 'C')
	{
		x = X_C;
	}
	Start.pop_back();
	// Di chuyển đi lên 
	for (; temp.y >= TOP; temp.y--)
	{
		VeDia(temp, 219);
		TangGiamTIME();
		Sleep(TIME);
		VeDia(temp, ' ');
		gotoxy(x, temp.y);
		textcolor(128);
		cout << ' ';
		textcolor(7);
	}
	VeDia(temp, 219);
	TangGiamTIME();
	Sleep(TIME + 150);
	VeDia(temp, ' ');
	// Di chuyển đi ngang 
	int a = St - En;
	if (a < 0)
	{
		a *= -1;
	}
	while (a)
	{
		if (St < En)
		{
			temp.x += KC;
		}
		else temp.x -= KC;
		VeDia(temp, 219);
		TangGiamTIME();
		Sleep(TIME + 150);
		VeDia(temp, ' ');
		a--;
	}
	// Di chuyển đi xuống 
	int size_E = End.size();
	x = X_A;
	if (En == 'B')
	{
		x = X_B;
	}
	else if (En == 'C')
	{
		x = X_C;
	}
	temp.y++;
	for (; temp.y < 23 - size_E; temp.y++)
	{
		VeDia(temp, 219);
		TangGiamTIME();
		Sleep(TIME);
		VeDia(temp, ' ');
		gotoxy(x, temp.y);
		textcolor(128);
		cout << ' ';
		textcolor(7);
	}
	VeDia(temp, 219);
	TangGiamTIME();
	Sleep(TIME);
	End.push_back(temp);
}
// Hàm di chuyển đĩa
void MOVE(char Start, char End)
{
	if (Start == 'A')
	{

		if (End == 'B')
		{
			Move(A, Start, B, End);
		}
		else Move(A, Start, C, End);
	}
	else if (Start == 'B')
	{
		if (End == 'A')
		{
			Move(B, Start, A, End);
		}
		else Move(B, Start, C, End);
	}
	else
	{
		if (End == 'B')
		{
			Move(C, Start, B, End);
		}
		else Move(C, Start, A, End);
	}
}
// Hàm đệ quy
void Try(int n, char Nguon, char TrungGian, char Dich/*, ofstream &File*/)
{

	if (n == 1)
	{
		/*FILE << Nguon << " -> " << Dich << endl;*/
		MOVE(Nguon, Dich);
	}
	else
	{
		Try(n - 1, Nguon, Dich, TrungGian/*, File*/);
		/*FILE << Nguon << " -> " << Dich << endl;*/
		MOVE(Nguon, Dich);
		Try(n - 1, TrungGian, Nguon, Dich/*, File*/);
	}
}

int  KiemTraInPut(string s)
{
	int n = atoi((char *)s.c_str());
	if (n >= 3 && n <= 9)
	{
		return n;
	}
	return 0;
}

int main()
{
	int n;					// Số dĩa
	/*ofstream FILE("output.txt", ios::out);
	if (!FILE)
	{
		cout << "Khong mo duoc File!" << endl;
	}*/
	string s;
	gotoxy(60, 25);
	cout << "Copyright " << char(1) << " ANHKHOA";
	gotoxy(1, 1);
	cout << "Hanoi Tower" << endl;
	do
	{
		fflush(stdin);
		cout << "Input disk( 3->9 ): ";
		getline(cin, s);
		if (!KiemTraInPut(s))
		{
			cout << "Error! Please try again! " << endl;
		}
	} while (!KiemTraInPut(s));
	n = KiemTraInPut(s);
	TOP = 25 - n - 3;
	SODIA = n;
	system("cls");
	ShowCur(0);				// Tắt con trỏ nhấp nháy
	VeThap(n);
	gotoxy(60, 25);
	cout << "Copyright "<<char(1)<<" ANHKHOA";
	gotoxy(1, 1);
	cout << "Press any key to start !";
	_getch();
	gotoxy(1, 1);
	cout << "                        ";
	gotoxy(45, 1);
	cout << "Press UP or DOWN to change speed !";
	Try(n, 'A', 'B', 'C');
	//FILE.close();
	gotoxy(1, 25);
	system("pause");
	return 0;
}



//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//using namespace std;
//struct luu {
//	int dai;
//	int x;
//};
//luu dia[7];
//int t = 0;
//
//int u = 500;
//int luudia[4][30];
//int dau[130], cuoi[130];
//void gotoxy(int x, int y)
//{
//	HANDLE hConsoleOutput;
//	COORD Cursor_an_Pos = { x - 1,y - 1 };
//	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
//}
//void vecot(int x, int &n) {
//	int c, d;
//	c = 22;
//	d = 17;
//	for (int i = 0; i<d; i++) {
//		gotoxy(x + i, c);
//		cout << "-";
//	}
//	for (int i = 0; i<c - 4; i++) {
//		gotoxy(x + d / 2, 5 + i);
//		cout << "|";
//	}
//}
//void vedia(int x, int y, int a, int c, int n) {
//	gotoxy(x - 1, y);
//	cout << a + 1;
//	luudia[c][y] = a;
//	for (int i = 0; i<dia[a].dai; i++) {
//		gotoxy(x - 1 - dia[a].dai / 2 + i, y - 1);
//		cout << "-";
//	}
//	gotoxy(x - dia[a].dai / 2 - 1, y);
//	cout << "|";
//	gotoxy(x + dia[a].dai / 2 - 1, y);
//	cout << "|";
//	for (int i = 0; i<dia[a].dai; i++) {
//		gotoxy(x - 1 - dia[a].dai / 2 + i, y + 1);
//		cout << "-";
//	}
//}
//void xoadia(int x, int y, int a, int c, int n) {
//	gotoxy(x - 1, y);
//	if (y >= 4) cout << "|";
//	else cout << " ";
//	luudia[c][y] = -1;
//	for (int i = 0; i<dia[a].dai; i++) {
//		gotoxy(x - 1 - dia[a].dai / 2 + i, y - 1);
//		cout << " ";
//	}
//	gotoxy(x - dia[a].dai / 2 - 1, y);
//	cout << " ";
//	gotoxy(x + dia[a].dai / 2 - 1, y);
//	cout << " ";
//	if (y>5) {
//		gotoxy(x - 1, y - 1);
//		cout << "|";
//	}
//	if (y != 21) {
//		for (int i = 0; i<dia[a].dai; i++) {
//			gotoxy(x - 1 - dia[a].dai / 2 + i, y + 1);
//			cout << " ";
//		}
//		if ((x == 9) || (x == 29) || (x == 49)) {
//			gotoxy(x - 1, y + 1);
//			if (y >= 5) cout << "|";
//		}
//	}
//	else {
//		gotoxy(x - 1, 22);
//		cout << "|";
//	}
//}
//
//void ve(int &n) {
//	vecot(0, n);
//	vecot(20, n);
//	vecot(40, n);
//	for (int i = n - 1; i >= 0; i--) vedia(9, 21 - (n - 1 - i) * 2, i, 1, n);
//}
//int kiemtra(int a) {
//	for (int i = 3; i <= 21; i = i + 2)
//		if (luudia[a][i] != -1) return 1;
//	return 0;
//}
//int kiemtra2(int a) {
//	int j;
//	j = 0;
//	for (int i = 3; i <= 21; i = i + 2)
//		if (luudia[a][i] != -1) j++;
//	if (j>1) return 1;
//	return 0;
//}
//
//void chuyen(int a, int b, int n) {
//	int x, y, t;
//
//	for (int i = 5; i <= 21; i = i + 2)
//		if (luudia[a][i] != -1) {
//			t = luudia[a][i];
//			x = 9 + (a - 1) * 20;
//			y = i;
//			break;
//		}
//	for (int i = y; i >= 5; i = i - 2) {
//		if (_kbhit()) {
//			char key = _getch();
//			if (key == 'w') u = u + 100;
//			if (key == 's') u = u - 100;
//		}
//		xoadia(x, i, t, a, n);
//		if (luudia[a][y + 2] != -1) vedia(x, y + 2, luudia[a][y + 2], a, n);
//		vedia(x, i - 2, t, a, n);
//		Sleep(u);
//	}
//	if (a<b)
//		for (int i = x; i <= (9 + (b - 1) * 20 - 2); i = i + 2) {
//			if (_kbhit()) {
//				char key = _getch();
//				if (key == 'w') u = u + 100;
//				if (key == 's') u = u - 100;
//			}
//			xoadia(i, 3, t, b, n);
//			vedia(i + 2, 3, t, b, n);
//			Sleep(u);
//		}
//	else
//		for (int i = 9 + (a - 1) * 20; i >= (9 + (b - 1) * 20) + 2; i = i - 2) {
//			if (_kbhit()) {
//				char key = _getch();
//				if (key == 'w') u = u + 100;
//				if (key == 's') u = u - 100;
//			}
//			xoadia(i, 3, t, b, n);
//			vedia(i - 2, 3, t, b, n);
//			Sleep(u);
//		}
//	for (int i = 3; i <= 19; i = i + 2)
//		if (luudia[b][i + 2] != -1) break;
//		else {
//			if (_kbhit()) {
//				char key = _getch();
//				if (key == 'w') u = u + 100;
//				if (key == 's') u = u - 100;
//			}
//			xoadia(9 + (b - 1) * 20, i, t, b, n);
//			vedia(9 + (b - 1) * 20, i + 2, t, b, n);
//			Sleep(u);
//		}
//}
//void hanoi(int n, int a, int b, int c)
//{
//	if (n>0)
//	{
//		hanoi(n - 1, a, c, b);
//		t++;
//		dau[t] = a;
//		cuoi[t] = b;
//		hanoi(n - 1, c, b, a);
//	}
//}
//int main() {
//	int n, a, b, c;
//	a = 1;
//	b = 2;
//	c = 3;
//	cout << "Nhap so luong dia (<7 dia): "; cin >> n;
//	system("cls");
//	for (int i = 1; i <= 3; i++)
//		for (int j = 1; j <= 30; j++) luudia[i][j] = -1;
//	for (int i = 0; i<n; i++) {
//		dia[i].dai = 3 + 2 * i;
//	}

//	ve(n);
//	hanoi(n, a, c, b);
//
//	for (int i = 1; i <= t; i++) chuyen(dau[i], cuoi[i], n);
//	gotoxy(1, 24);
//	return 0;
//}
