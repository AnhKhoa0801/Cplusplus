#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int a[30][30];
void Input(ifstream &file, int &n)
{
	file >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			file >> a[i][j];
		}
	}
}



void Bai9(int a[], int b[], int c[])
{
	int k = 0;
	bool flag1 = false, flag2 = false;
	for (int i = 0, j = 0; i < 5 || j < 6;)
	{
		if (flag1)
		{
			c[k++] = b[j++];
		}
		else if(flag2)
		{
			c[k++] = a[i++];
		}

		if (i == 5)
		{
			flag1 = true;
		}
		else if (j == 6)
		{
			flag2 = true;
		}
		else if (a[i] == b[j])
		{
			c[k++] = a[i++];
			c[k++] = b[j++];
		}
		else if (a[i] > b[j])
		{
			c[k++] = b[j++];
		}
		else if (a[i] < b[j])
		{
			c[k++] = a[i++];
		}
	}
}

int MIN(int a[],int t)
{
	int Min = -1, vt = 0;
	for (int i = 1; i <= t; i++)
	{
		vt = 4;
		for (int j = 0; j < 5; j++)
		{
			if (Min >= a[j])
			{
				continue;
			}
			if (a[j] < a[vt])
			{
				vt = j;
			}
		}
		Min = a[vt];
	}
	return vt;
}
int main()
{
	/*int n;
	ifstream File("input.txt",ios::in);
	if (!File)
	{
		cout << "Khong mo duoc File!";
		return 0;
	}
	Input(File, n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	int a[] = { 4,1,2,6,7 };
	int b[] = { 1,2,3,6,8,10 };
	int c[11];
	cout << a[MIN(a, 3)];
	system("pause");
	return 0;
}