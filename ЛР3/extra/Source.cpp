#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	ifstream ifile("Input.txt");
	if (!ifile)
	{
		cout << "Input file error";
	}
	int x = 0, lenof = 0;
	int* a = new int[256];
	while (!ifile.eof())
	{
		int buff = ifile.get() - 48;
		if (buff < 10 && buff >= 0 || buff == 11 || buff == -38)
		{
			a[x] = buff;
			x++;
		}
		lenof++;
	}
	//for (int j = 0; j < x; j++)
	//{
	//	cout << "a[" << j << "]= " << a[j] << "\n";
	//}

	int* b = new int[x];
	int j = 0;
	for (int i = 0; i < x; i++)
	{
		if (a[i] == 11 && a[i+1] == 11 && a[i+2] == 11)
		{
			i = i + 3;
		}
		if (a[i] == -38)
		{
			b[j] = 11;
			j++;
		}
		else
		{
			b[j] = a[i];
			j++;
		}
	}
	//for (int k = 0; k < j; k++)
	//{
	//	cout << "b[" << k << "]= " << b[k] << "\n";
	//}
	//cout << "j =" << j << "\n";
	int* temp = new int[j];
	for (int i = 0; i < j; i++)
	{
		temp[i] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < j; i++)
	{
		if (b[i] != 11)
		{
			temp[cnt] = temp[cnt]*10 + b[i];
			//cout << cnt << " - " << temp[cnt] << "\n";
		}
		else
		{
			cnt++;
			//cout << "cnt_e= " << cnt << "\n" ;
		}
	}
	//for (int k = 0; k < cnt; k++)
	//{
	//	cout << "temp[" << k << "]= " << temp[k] << "\n";
	//}
	//cout << "temp length = " << cnt << "\n";
	int* yrs = new int[cnt], * mny = new int[cnt];
	int yrslen = 0, mnylen = 0, in = 0;
	for (int i = 0, j =0, k = 1; i < cnt; i++, j = j + 2, k = k + 2)
	{
		if (temp[j])
		{
				yrs[yrslen] = temp[j];
				yrslen++;
				if (temp[j] < 1982)
				in = yrslen;
		}
		if (k != in)
		{
			if (temp[k])
			{
				mny[mnylen] = temp[k];
				mnylen++;
			}
		}
		else
		{
			mny[mnylen] = 0;
			mnylen++;
		}
	}

	//for (int k = 0; k < yrslen; k++)
	//{
	//	cout << "yrs[" << k << "]= " << yrs[k] << "\n";
	//}
	//cout << "\n" << "\n";
	//for (int k = 0; k < mnylen; k++)
	//{
	//	cout << "mny[" << k << "]= " << mny[k] << "\n";
	//}

	////finally.... finding maximum of wages
	int mnymax = 0, index = 0;
	for (int i = 0; i < mnylen; i++)
	{
		if (mny[i] > mnymax)
		{
			mnymax = mny[i];
			index = i;
		}
		cout << index;
	}
	system("pause");
}