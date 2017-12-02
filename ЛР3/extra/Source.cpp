#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;



int main()
{
	ifstream ifile("Input.txt");
	if (!ifile)
	{
		cout << "Input file error";
	}
	int x = 0, g = 0;
	int* a = new int[256],* orig = new int[512];
	while (!ifile.eof())
	{
		int buff = ifile.get() - 48;
		orig[g] = buff;
		if (buff < 10 && buff >= 0 || buff == 11 || buff == -38)
		{
			a[x] = buff;
			x++;
		}
		g++;
	}

	int* b = new int[x];
	int lentmp = 0;
	for (int i = 0; i < x; i++)
	{
		if (a[i] == 11 && a[i+1] == 11 && a[i+2] == 11)
		{
			i = i + 3;
		}
		if (a[i] == -38)
		{
			b[lentmp] = 11;
			lentmp++;
		}
		else
		{
			b[lentmp] = a[i];
			lentmp++;
		}
	}
	delete[]a;
	int* temp = new int[lentmp];
	for (int i = 0; i < lentmp; i++)
	{
		temp[i] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < lentmp; i++)
	{
		if (b[i] != 11)
		{
			temp[cnt] = temp[cnt]*10 + b[i];
		}
		else
		{
			cnt++;
		}
	}
	delete[]b;
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
	delete[] temp;
	int mnymax = 0, index = 0;
	for (int i = 0; i < mnylen; i++)
	{
		if (mny[i] > mnymax)
		{
			mnymax = mny[i];
			index = i;
		}
	}
	delete[] mny;
	delete[] yrs;
	ifile.close();

	ofstream ofile("Output.txt");
		int count = 0, count2 = 0;
	for (int i = 0; i < g; i++)
	{
		for (int i = 0; i < g; i++)
		{
			if (orig[i] == -38)
				count++;

			if (count == index)
			{
				if (orig[i] == -38)
					i++;
				if (orig[i] == 11)
					count2++;
				if (count2 < 2)
				{
					if (orig[i] == 11)
					{
						ofile << " ";
						i++;
					}
					ofile << (char)(orig[i] + 16);
				}

			}
		}
	}
	ofile << " - worker with a biggest wage and younger than 35" << "\n";
	ofile.close();
	delete[] orig;
//	system("pause");
}