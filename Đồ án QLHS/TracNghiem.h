//#pragma once
#include"DSDiemthi.h"
#include"DiemThi.h"
#define CAUHOITHIMAX 50
#define SVTHI 100

struct ABCD
{
	string arr[4];
};

struct TracNghiemSV
{
	int Masv, Mamh;
	char DSDapan[CAUHOITHIMAX];
	char DSTraloi[CAUHOITHIMAX];
	int id[CAUHOITHIMAX];
	string DSCauhoi[CAUHOITHIMAX];
	int SoCauHoi = 0;
	ABCD ArrDapAn[CAUHOITHIMAX];
};

TracNghiemSV DSThi[SVTHI];
int SVThi = 0;		// Sinh viên đã thi


// Tìm câu hỏi đã thi
bool TimIDThi(int x)
{
	int Socauhoi = DSThi[SVThi].SoCauHoi;
	for (int i = 0; i < Socauhoi; i++)
	{
		if (DSThi[SVThi].id[i] == x)
		{
			return true;
		}
	}
	return false;
}

// Khởi tạo danh sách trả lời
void KhoiTaoDSTraloi(int Socauhoi)
{
	for (int i = 0; i < Socauhoi; i++)
	{
		DSThi[SVThi].DSTraloi[i] = ' ';
	}
}

// Khởi tạo trước khi thi 
void KhoiTaoThi(Tree t, int MaMh, int Masv, int Socauhoi)
{
	DSThi[SVThi].Mamh = MaMh;
	DSThi[SVThi].Masv = Masv;
	DSThi[SVThi].SoCauHoi = Socauhoi;
	Tree x;
	int j = 1;
	for (int i = 0; i < Socauhoi;)
	{
		x = NULL;
		for (; j <= 30000; j++)
		{
			if (ID[j] == 1)
			{
				break;
			}
		}
		x = TimCauHoi(t, MaMh, j);
		if (x != NULL)
		{
			DSThi[SVThi].id[i] = j;
			DSThi[SVThi].DSDapan[i] = x->Data.Get_DapAn();
			DSThi[SVThi].DSCauhoi[i] = x->Data.Get_NoiDung();
			x->Data.DSLuachon(DSThi[SVThi].ArrDapAn[i].arr);
			i++;
		}
		j++;
	}
}

// Thi trắc nghiệm
void ThiTracNghiem(List2 &l,Tree t,int Time)
{
	int mamh = DSThi[SVThi].Mamh;
	int masv = DSThi[SVThi].Masv;
	int socauhoi = DSThi[SVThi].SoCauHoi;
	int Vitritomau;
	int Diem = 0;
	int time = Time * 60;
	KhoiTaoDSTraloi(socauhoi);
	Node2 *p = TimKiemDiemSV(l, mamh, masv);	// Điểm môn của học sinh
	int j = 0;
	while(time!=0)
	{
		gotoxy(1, 25);
		cout << "ESC:FINISH || ENTER:CHOOSE || LEFT:BACK || RIGHT:NEXT ";
		if (DSThi[SVThi].DSTraloi[j] != ' ')
		{
			Vitritomau = DSThi[SVThi].DSTraloi[j] - 65;
		}
		else
		{
			Vitritomau = -1;
		}
		gotoxy(1, 1);
		cout << j + 1 << "." << DSThi[SVThi].DSCauhoi[j];
		xuatMenu(DSThi[SVThi].ArrDapAn[j].arr, Vitritomau, 4, 2, 2);
		char c;
		do
		{
			// Đếm ngược thời gian 
			do
			{
				if (time == 0)
				{
					goto TinhDiem;
				}
				gotoxy(75, 1);
				cout << time--<<"  ";
				Sleep(1000);
			} while (!_kbhit());
			c = _getch();
			if (c == 27)
			{
				goto TinhDiem;
			}
			else if (c == -32)
			{
				c = _getch();
				if (c == 80)
				{
					if (Vitritomau == 4 - 1)
					{
						Vitritomau = -1;
					}
					xuatMenu(DSThi[SVThi].ArrDapAn[j].arr, ++Vitritomau, 4, 2, 2);
				}
				else if (c == 72)
				{
					if (Vitritomau == 0 || Vitritomau == -1)
					{
						Vitritomau = 4;
					}
					xuatMenu(DSThi[SVThi].ArrDapAn[j].arr, --Vitritomau, 4, 2, 2);
				}
				else
				{
					if (c == 75)
					{
						if (j == 0)
						{
							j = socauhoi;
						}
						j--;
					}
					else if (c == 77)
					{
						if (j == socauhoi - 1)
						{
							j = -1;
						}
						j++;
					}
					break;
				}
			}
		} while (c != 13);
		if (c == 13)
		{
			if (Vitritomau >= 0 && Vitritomau <= socauhoi - 1)
			{
				DSThi[SVThi].DSTraloi[j] = Vitritomau + 65;
			}
			if (j == socauhoi - 1)
			{
				j = -1;
			}
			j++;
		}
		system("cls");
	}
TinhDiem:;
	float x = 10.0 / socauhoi;
	float temp = 0;
	for (int i = 0; i < socauhoi; i++)
	{
		if (DSThi[SVThi].DSTraloi[i] == DSThi[SVThi].DSDapan[i])
		{
			temp += x;
		}
	}
	// Làm tròn 
	if (temp - int(temp) >= 0.5)
	{
		temp += 0.5;
	}
	p->Data.Diem = int(temp);
	SVThi++;
}

