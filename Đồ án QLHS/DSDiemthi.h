#pragma once
#include"DSCauHoi.h"

// Khởi tạo danh sách điểm
void KhoiTaoDSDiem(List2 &l) 
{
	CreateList(l);
	for (int i = 0; i < SoMH; i++)
	{
		for (int j = 0; j < SoSV; j++)
		{
			DiemThi x;
			x.Mamh = DSMon[i].MaMH;
			x.Masv = SinhVien[j];
			AddTail(l, x);
		}
	}
}

// Thêm danh sách điểm khi thêm môn
void TaoDSDiem_Mon(List2 &l,int Mamh)
{
	for (int i = 0; i < SoSV; i++)
	{
		DiemThi x;
		x.Mamh = Mamh;
		x.Masv = SinhVien[i];
		AddTail(l, x);
	}
}

// Thêm danh sách điểm khi thêm sinh viên
void TaoDSDiem_SV(List2 &l, int Masv)
{
	for (int i = 0; i < SoMH; i++)
	{
		DiemThi x;
		x.Mamh = DSMon[i].MaMH;
		x.Masv = Masv;
		AddTail(l, x);
	}
}

void DuyetDiem(List2 l)
{
	for (Node2 *p = l.pHead; p; p = p->pNext)
	{
		cout << p->Data.Mamh << " " << p->Data.Masv << endl;
	}
}