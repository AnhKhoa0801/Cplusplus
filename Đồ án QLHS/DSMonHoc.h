#include"DSLop.h"

struct MHoc
{
	int MaMH;
	string TenMH;
};


MHoc DSMon[MONMAX];
int SoMH = 0;

struct MHoc2
{
	int MaMH;
	int SoCauHoi = 0;
};

MHoc2 DSMon2[MONMAX];		// Mảng đánh dấu số câu hỏi của môn

// Tìm kiếm mã MH trả về true nếu có
bool TimKiemMaMH(int MA)
{
	for (int i = 0; i < SoMH; i++)
	{
		if (DSMon[i].MaMH == MA)
		{
			return true;
		}
	}
	return false;
}

int TimMonViTri(int MA)
{
	for (int i = 0; i < SoMH; i++)
	{
		if (DSMon[i].MaMH == MA)
		{
			return i;
		}
	}
}

void NhapMH(List2 &l)
{
	string s;
	int LuaChon;
	do
	{
		cout << "Nhap lua chon(1:Nhap mon hoc/0:Thoat): ";
		cin >> LuaChon;
		if (LuaChon == 1)
		{
			cout << "Nhap Ma mon hoc: ";
			do
			{
				s = ChuanHoaNhap2();
			} while (s == "");
			cout << endl;
			int MaMH = atoi((char*)s.c_str());
			if (TimKiemMaMH(MaMH))
			{
				cout << "Ma mon hoc bi trung! ";
				cout << endl;
			}
			else
			{
				DSMon2[SoMH].MaMH = DSMon[SoMH].MaMH = MaMH;
				cout << "Nhap Ten mon hoc: ";
				do
				{
					s = ChuanHoaNhap1();
				} while (s == "");
				cout << endl;
				DSMon[SoMH++].TenMH = s;
				TaoDSDiem_Mon(l, MaMH);
			}
		}
		else if (LuaChon != 0)
		{
			cout << "Loi! Xin kiem tra lai! " << endl;
		}
	} while (LuaChon != 0);
}

// Đọc danh sách môn học từ file
void DocDSMon()
{
	ifstream File("DSMon.TXT");
	while (!File.eof())
	{
		File >> DSMon[SoMH].MaMH;
		DSMon2[SoMH].MaMH = DSMon[SoMH].MaMH;
		File.ignore();
		string s;
		getline(File, s);
		DSMon[SoMH++].TenMH = s;
	}
	File.close();
}

// Ghi danh sách môn học vào file
void GhiDSMon()
{
	ofstream File("InDSMon.TXT");
	File << "Ma MH         Ten MH";
	File << endl;
	for (int i = 0; i < SoMH; i++)
	{
		File << setw(3) << DSMon[i].MaMH;
		File << "              ";
		File << DSMon[i].TenMH << endl;
	}
	File.close();
}