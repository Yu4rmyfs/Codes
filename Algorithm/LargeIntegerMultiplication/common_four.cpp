#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;

size_t size = 250000;

void DisplayDigital(int *a, int flag)
{
	int i = (size*flag) - 1;
	while (i >= 0)
	{
		if (a[i]<10)
			cout << "000" << a[i--];
		else if (a[i]<100)
			cout << "00" << a[i--];
		else if (a[i]<1000)
			cout << '0' << a[i--];
		else
			cout << a[i--]; 
	}
	cout << endl;
}

int main()
{
	clock_t start, end;
	int *multiplier = new int[size];
	int *multiplicand = new int[size];
	int *result = new int[2 * size]();


	srand((int)time(0));
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		multiplicand[i] = rand() % 10000;
		multiplier[i] = rand() % 10000 ;
	}
	multiplicand[i] = rand() % 9000 + 1000;
	multiplier[i] = rand() % 9000 + 1000;

	start = clock();
	for (i = 0; i < size; i++)
	{
		int carry = 0;
		int temp = 0;
		int j = 0;
		for (j = 0; j < size; j++)
		{
			temp = multiplier[i] * multiplicand[j] + carry + result[i + j];

			result[i + j] = temp % 10000;
			carry = temp / 10000;
		}
		result[i + j] += carry;
	}
	

	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

	time_t nowtime;
	nowtime = time(NULL);
	char timebuf[26];
	errno_t err;
	struct tm ptr;
	localtime_s(&ptr, &nowtime);
	asctime_s(timebuf, 26, &ptr);

	delete[]multiplier;
	delete[]multiplicand;
	delete[]result;
}