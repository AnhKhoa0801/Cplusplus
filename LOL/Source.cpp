#include<iostream>
#include<time.h>
using namespace std;
int main()
{

	

	time_t t1 = clock();
	for (int i = 0; i < 100000000; i++)
	{

	}
	int k1 = 1*2;
	int k2 = k1 + 3*4;
	int kq = k2;
	time_t t2 = clock();
	cout << t2 - t1 << endl;

	time_t t3 = clock();
	for (int i = 0; i < 100000000; i++)
	{

	}
	int k3 = 1*2;
	int k4 = 3*4;
	int kqq = k3 + k4;
	time_t t4 = clock();
	cout << t4 - t3 << endl;

	system("pause");

	return 0;
}