#include"TracNghiem.h"
#define XX 20
#define YY 7

// flag = 1 khung nhập có password
void Khung(string s1, string s2, string &in1, string &in2, bool flag)
{
	textcolor(63);
	int x1, y1;
	int x2, y2;
	for (int i = 1; i <= 8; i++)
	{
		if (i == 3)
		{
			gotoxy(XX + 1, YY + i);
			cout << " " << s1 << "\t  ";
			x1 = wherex();
			y1 = wherey();
			gotoxy(XX + 40 - 2, YY + i);
			cout << "   ";
		}
		else if (i == 6)
		{
			gotoxy(XX + 1, YY + i);
			cout << " " << s2 << "\t  ";
			x2 = wherex();
			y2 = wherey();
			gotoxy(XX + 40 - 2, YY + i);
			cout << "   ";
		}
		else
		{
			for (int j = 1; j <= 40; j++)
			{
				gotoxy(XX + j, YY + i);
				cout << " ";
			}
		}
	}
	textcolor(7);
	if (flag)
	{
		gotoxy(x1 + 1, y1 + 1);
		do
		{
			in1 = ChuanHoaNhap1();
			if (in1 == "\0")
			{
				return;
			}
		} while (in1 == "");
		gotoxy(x2 + 1, y2 + 1);
		do
		{
			in2 = ChuanHoaPass();
			if (in2 == "\0")
			{
				return;
			}
		} while (in2 == "");
	}
	else
	{
		gotoxy(x1 + 1, y1 + 1);
		do
		{
			in1 = ChuanHoaNhap2();
			if (in1 == "\0")
			{
				return;
			}
		} while (in1 == "");
		gotoxy(x2 + 1, y2 + 1);
		do
		{
			in2 = ChuanHoaNhap2();
			if (in2 == "\0")
			{
				return;
			}
		} while (in2 == "");
	}
}

// Các module của GV
void MenuGV(Tree &t, List2 &l)
{
	string GV[15];
	GV[0] = "1. Nhap lop       ";
	GV[1] = "2. Nhap sinh vien ";
	GV[2] = "3. Nhap mon hoc   ";
	GV[3] = "4. Nhap cau hoi   ";
	GV[4] = "5. Bang diem lop  ";
	GV[5] = "6. Xem cau hoi thi";
	GV[6] = "7. Danh sach lop  ";
	GV[7] = "8. Dang xuat      ";
	xuatMenu(GV, 0, 8, 2, 2);
	int i = 0;
	do
	{
	MenuGV:
		toMau(GV, i, 8, 2, 2);
		system("cls");
		switch (i)
		{
		case 0:
		{
			NhapDanhSachLop();
			break;
		}
		case 1:
		{
			NhapSinhVien(l);
			break;
		}
		case 2:
		{
			NhapMH(l);
			break;
		}
		case 3:
		{
			NhapCauHoi(t);
			break;
		}
		case 4:
		{
			int Malop = -1, Mamh = -1;
			string s1, s2;
			do
			{
				gotoxy(1, 25);
				cout << "ESC:Exit";
				Khung("Ma lop:", "Ma MH:", s1, s2, 0);
				if (s1 == "\0" || s2 == "\0")
				{
					break;
				}
				Malop = atoi((char*)s1.c_str());
				Mamh = atoi((char*)s2.c_str());
				if (!(TimKiemMaLop(Malop) && TimKiemMaMH(Mamh)))
				{
					gotoxy(XX + 7, YY + 10);
					cout << "Loi! Thong tin nhap sai! ";
					Sleep(1000);
				}
				system("cls");
			} while (!(TimKiemMaLop(Malop) && TimKiemMaMH(Mamh)));
			if (TimKiemMaLop(Malop) && TimKiemMaMH(Mamh))
			{
				for (int k = 0; k < SoLop; k++)
				{
					if (DSLop[k].Get_Malop() == Malop)
					{
						DSLop[k].BangDiem(l, Mamh);
						break;
					}
				}
			}
			break;
		}
		case 5:
		{
			int Masv = -1, Mamh = -1;
			string s1, s2;
			do
			{
				gotoxy(1, 25);
				cout << "ESC:Exit";
				Khung("Ma SV:", "Ma MH:", s1, s2, 0);
				if (s1 == "\0" || s2 == "\0")
				{
					break;
				}
				Masv = atoi((char*)s1.c_str());
				Mamh = atoi((char*)s2.c_str());
				if (!(TimkiemDS_SV(Masv) && TimKiemMaMH(Mamh)))
				{
					gotoxy(XX + 7, YY + 10);
					cout << "Loi! Thong tin nhap sai! ";
					Sleep(1000);
				}
				system("cls");
			} while (!(TimkiemDS_SV(Masv) && TimKiemMaMH(Mamh)));
			int k;
			if (TimkiemDS_SV(Masv) && TimKiemMaMH(Mamh))
			{
				bool flag = KiemTraDiemSV(l, Mamh, Masv);
				if (flag)
				{
					for (k = 0; k < SVThi; k++)
					{
						if (DSThi[k].Masv == Masv&&DSThi[k].Mamh == Mamh)
						{
							cout << "STT\tID\tNoiDung\t\t\t\t\tDap an\tTra loi" << endl;
							for (int t = 0; t < DSThi[k].SoCauHoi; t++)
							{
								cout << t + 1 << "\t" << DSThi[k].id[t] << "\t";
								int length = DSThi[k].DSCauhoi[t].length();
								if (length > 30)
								{
									for (int q = 0; q < 30; q++)
									{
										cout << DSThi[k].DSCauhoi[t][q];
									}
									cout << "....";
								}
								else
								{
									for (int q = 0; q < length; q++)
									{
										cout << DSThi[k].DSCauhoi[t][q];
									}
								}
								gotoxy(60, t + 2);
								cout << DSThi[k].DSDapan[t] << "\t   " << DSThi[k].DSTraloi[t];
								cout << endl;
							}
							break;
						}
					}
				}
				else
				{
					cout << "Sinh vien nay chua thi!" << endl;
				}
				_getch();
			}
			
			break;
		}
		case 6:
		{
			InDSLop();
			_getch();
			break;
		}
		}
		system("cls");
		xuatMenu(GV, i, 8, 2, 2);
	} while (i != 7);
}
int main()
{
	Tree t;	// Node cây nhị phân câu hỏi
	List2 l;	// Danh sách điểm thi 
	CreateTree(t);
	DocDSMon();
	DocDSCauhoi(t);
	DocDSLop();
	KhoiTaoDSDiem(l);
	string s1, s2;
	do
	{
		Khung("Ma SV:", "Mat Khau:", s1, s2, 1);
		if (s1 == "GV")
		{
			if (s2 == "GV")
			{
				system("cls");
				MenuGV(t, l);
				system("cls");
			}
			else
			{
				gotoxy(XX + 7, YY + 10);
				cout << "Loi! Mat khau sai!";
				Sleep(1000);
				system("cls");
			}
		}
		else
		{
			int Masv = atoi((char*)s1.c_str());
			if (TimKiemMangSV(Masv))
			{
				Node *p = TimkiemDS_SV(Masv);
				if (1)
				{
					// Thi trắc nghiệm
					system("cls");
					string s1;
					int Mamh;
					cout << "Nhap Ma MH: ";
					int x1 = wherex();
					bool check;		// Chưa thi
					do
					{
						check = false;
						s1 = ChuanHoaNhap2();
						Mamh = atoi((char*)s1.c_str());
						if (!TimKiemMaMH(Mamh) && s1 != "")
						{
							gotoxy(52, 1);
							textcolor(12);
							cout << "Loi! Khong tim thay Ma MH!";
							textcolor(7);
							Sleep(1000);
							gotoxy(52, 1);
							cout << "                          ";
							gotoxy(x1 + 1, 1);
							cout << "                          ";
							gotoxy(x1 + 1, 1);
						}
						else if (TimKiemMaMH(Mamh))
						{
							Node2 *p = TimKiemDiemSV(l, Mamh, Masv);
							if (p->Data.Diem != -1)
							{
								check = true;
								gotoxy(52, 1);
								textcolor(12);
								cout << "Loi! Ban da thi mon nay!";
								textcolor(7);
								Sleep(1000);
								gotoxy(52, 1);
								cout << "                          ";
								gotoxy(x1 + 1, 1);
								cout << "                          ";
								gotoxy(x1 + 1, 1);
							}
						}
					} while (s1 == "" || !TimKiemMaMH(Mamh) || check);
					cout << endl;
					int i = TimMonViTri(Mamh);
					int Socauhoi;
					cout << "So cau hoi: ";
					int x2 = wherex();
					do
					{
						s1 = ChuanHoaNhap2();
						Socauhoi = atoi((char*)s1.c_str());
						if (Socauhoi > DSMon2[i].SoCauHoi && s1 != "")
						{
							gotoxy(55, 1);
							textcolor(12);
							cout << "Loi! Toi da la:" << DSMon2[i].SoCauHoi;
							textcolor(7);
							Sleep(1000);
							gotoxy(55, 1);
							cout << "                          ";
							gotoxy(x2 + 1, 2);
							cout << "                          ";
							gotoxy(x2 + 1, 2);
						}
					} while (s1 == "" || Socauhoi > DSMon2[i].SoCauHoi);
					int time;
					cout << endl;
					cout << "Thoi gian (phut): ";
					int x3 = wherex();
					do
					{
						s1 = ChuanHoaNhap2();
						time = atoi((char*)s1.c_str());
					} while (s1 == "");
					if (Socauhoi != 0)
					{
						KhoiTaoThi(t, Mamh, Masv, Socauhoi);
						system("cls");
						ThiTracNghiem(l, t, time);
					}
					system("cls");
				}
				else
				{
					gotoxy(XX + 7, YY + 10);
					cout << "Loi! Mat khau sai!";
					Sleep(1000);
					system("cls");
				}
			}
			else
			{
				gotoxy(XX + 7, YY + 10);
				cout << "Loi! Khong tim thay Ma SV! ";
				Sleep(1000);
				system("cls");
			}
		}
	} while (1);
	return 0;
}