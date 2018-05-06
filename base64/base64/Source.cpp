#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<iostream>

using namespace std;

//enum code { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 
//	        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

void fileInput(int* arr, int &i)
{
	ifstream file("input.txt", ios::binary);
	while(!file.eof())
	{
		arr[i] = file.get();
		i++;
	}
	file.close();
}

void fileOutput(int * arr, int size)
{
	ofstream file("output.txt");
	for (int i = 0; i < size; i++)
	{
		//char* c = new char;
		//_itoa(arr[i], c, 10);								 //!
		char c = arr[i] + 65;
		file << c;
	}
	file.close();
}

void main()
{
	int counter = 0;
	int arr[2048];
	fileInput(arr,counter);
	int size = counter * 8;
	int numOfEights = 0;
	
	while (size % 6 != 0)
	{
		size += 8;
		numOfEights++;
	}

	int* result = new int[counter * 6];

	for (int i = 0, s = 0; i < counter; i += 3, s += 4)
	{
		result[s] = (arr[i] & 252) >> 2;
	}

	for (int i = 0 ,j = 1, s = 1; j < counter; i += 3, j += 3, s += 4)
	{
		result[s] = ((arr[i] & 3) << 4) + ((arr[j] & 240) >> 4);
	}

	for (int i = 1, j = 2, s = 2; j < counter; i += 3, j += 3, s += 4)
	{
		result[s] = ((arr[i] & 15) << 2) + ((arr[j] & 192) >> 6);
	}

	for (int i = 2, s = 3; i < counter; i += 3, s += 4)
	{
		result[s] = arr[i] & 63;
	}

	fileOutput(result, counter * 6);
}

//void main()
//{
//	int a = 77, b = 97;
//	int c = a & 3;
//	int d = b & 240;
//	int e = c << 4;
//	int f = d >> 4;
//	int g = e + f;
//}


//void main()
//{
//	ofstream ofile ("output.txt");
//	for (int i = 0; i < 10000; i += 2)
//	{
//		int result = i;
//		int counter = 0;
//		while (result % 6 != 0)
//		{
//			result += 8;
//			counter++;
//		}
//		ofile << i << ": " << counter << " of 8 = " << result << "\n";
//	}
//}