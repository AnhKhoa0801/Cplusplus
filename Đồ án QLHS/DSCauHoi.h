#include"DSMonHoc.h"
class CauHoi
{
private:
	int Id, MaMH;
	string NoiDung, A, B, C, D;
	char DapAn;
public:
	CauHoi();
	void Nhap();
	int Get_Id();
	void Set_id(int);
	int Get_MaMH();
	void Set_MaMH(int);
	void DocCauHoi(ifstream&);
	void DSLuachon(string[]);
	char Get_DapAn();
	string Get_NoiDung();
};

CauHoi::CauHoi()
{
	Id = MaMH = -1;
	A = "A.";
	B = "B.";
	C = "C.";
	D = "D.";
	DapAn = '0';
}

char CauHoi::Get_DapAn()
{
	return DapAn;
}

int CauHoi::Get_Id()
{
	return Id;
}

string CauHoi::Get_NoiDung()
{
	return NoiDung;
}

void CauHoi::Set_id(int a)
{
	Id = a;
}

int CauHoi::Get_MaMH()
{
	return MaMH;
}

void CauHoi::Set_MaMH(int a)
{
	MaMH = a;
}

void CauHoi::DSLuachon(string a[])
{
	a[0] = A;
	a[1] = B;
	a[2] = C;
	a[3] = D;
}

void CauHoi::Nhap()
{
	string s;
	string Temp;
	// Id và MaMH nhập ở danh sách câu hỏi
	cout << "Id: " << Id << endl;
	cin.ignore();
	cout << "Nhap noi dung:";
	getline(cin, NoiDung);
	cout << "A. ";
	getline(cin, Temp);
	A += Temp;
	cout << "B. ";
	getline(cin, Temp);
	B += Temp;
	cout << "C. ";
	getline(cin, Temp);
	C += Temp;
	cout << "D. ";
	getline(cin, Temp);
	D += Temp;
	cout << "Dap an: ";
	int x = wherex();
	int y = wherey();
	do
	{
		s = ChuanHoaNhap();
		if (s.length() != 1)
		{
			gotoxy(x, y + 1);
			cout << "          ";
			gotoxy(x, y + 1);
		}
	} while (s == "" || s.length() != 1);
	DapAn = s[0];
}

void CauHoi::DocCauHoi(ifstream &File)
{
	getline(File, NoiDung);
	getline(File, A);
	getline(File, B);
	getline(File, C);
	getline(File, D);
	File >> DapAn;
	File.ignore();
}

// Node câu hỏi
struct Node1
{
	CauHoi Data;
	Node1* pLeft;
	Node1* pRight;
};

typedef Node1* Tree;

void CreateTree(Tree &t)
{
	t = NULL;
}

Node1* getNode(CauHoi x)
{
	Node1 *p = new Node1;
	if (p == NULL)
	{
		return NULL;
	}
	p->Data = x;
	p->pLeft = p->pRight = NULL;
	return p;
}

void Insert(Tree &t, CauHoi x)
{
	if (t == NULL)
	{
		Node1 *p = getNode(x);
		t = p;
	}
	else
	{
		if (t->Data.Get_Id() > x.Get_Id())
		{
			Insert(t->pLeft, x);
		}
		else if (t->Data.Get_Id() < x.Get_Id())
		{
			Insert(t->pRight, x);
		}
	}
}

int ID[30001] = { 0 };		// Mảng đánh dấu ID

// Nhập Node cho cây
void InputTree(Tree &t, int MAMH, int i)
{
	int KiemTra;
	int id;
	string s;
	do
	{
		CauHoi x;
		cout << "Nhap lua chon(1:Nhap cau hoi/0: Thoat): ";
		cin >> KiemTra;
		if (KiemTra == 1)
		{
		NhapID:
			srand(time(0));
			id = 1 + rand() % 30000;
			if (ID[id])
			{
				goto NhapID;
			}
			else
			{
				ID[id] = 1;
				x.Set_id(id);
				x.Set_MaMH(MAMH);
				x.Nhap();
				Insert(t, x);
				DSMon2[i].SoCauHoi++;
				cout << endl;
			}
		}
		else
		{
			if (KiemTra != 0)
			{
				cout << "Loi! Xin nhap lai!" << endl;
			}
		}
	} while (KiemTra != 0);
}

void NLR(Tree t)
{
	if (t != NULL)
	{
		cout << t->Data.Get_Id() << endl;
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// Nhập câu hỏi cho môn học 
void NhapCauHoi(Tree &t)
{
	string Mon[30];
	cout << "Ma MH    || Ten MH  " << endl;
	// Khởi tạo Menu
	for (int i = 0; i < SoMH; i++)
	{
		cout << DSMon[i].MaMH;
		gotoxy(10, i + 2);
		cout << "||";
		cout << endl;
		Mon[i] = DSMon[i].TenMH;
	}
	int i = 0;
	xuatMenu(Mon, i, SoMH, 13, 2);
	toMau(Mon, i, SoMH, 13, 2);
	system("cls");
	cout << "Ma MH: " << DSMon[i].MaMH << endl;
	cout << "Ten MH: " << DSMon[i].TenMH << endl;
	InputTree(t, DSMon[i].MaMH, i);
}

// Đọc câu hỏi từ file
void DocDSCauhoi(Tree &t)
{
	CauHoi x;
	int Monhoc;
	ifstream File("DSCauhoi.txt");
	File >> Monhoc;
	int i = TimMonViTri(Monhoc);
	int n;
	File >> n;
	DSMon2[i].SoCauHoi = n;
	File.ignore();
	srand(time(0));
	for (int i = 0; i < n; )
	{
		int id = 1 + rand() % 30000;
		if (ID[id])
		{
			continue;
		}
		else
		{
			ID[id] = 1;
			x.Set_id(id);
			x.Set_MaMH(Monhoc);
			x.DocCauHoi(File);
			Insert(t, x);
			i++;
		}
	}
}

// Tìm câu hỏi có Mamh và id
Tree TimCauHoi(Tree t,int Mamh, int id)
{
	if (t->Data.Get_Id() == id&&t->Data.Get_MaMH() == Mamh)
	{
		return t;
	}
	else
	{
		if (t->Data.Get_Id() > id)
		{
			TimCauHoi(t->pLeft, Mamh, id);
		}
		else if (t->Data.Get_Id() < id)
		{
			TimCauHoi(t->pRight, Mamh, id);
		}
		else if (t->Data.Get_Id() == id&&t->Data.Get_MaMH() != Mamh)
		{
			return NULL;
		}
	}
}