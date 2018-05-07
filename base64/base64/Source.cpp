#define _CRT_SECURE_NO_WARNINGS	 //!
#include<fstream>
#include<iostream>
#include<bitset>				 //!

using namespace std;

char* getName()
{
	cout << "file name:";
	char* newName = new char[256];
	cin >> newName;

	return newName;
}

int* fileInputEncode(int &i)
{
	int arr[2048];
	for (int j = 0; j < 2048; j++)
		arr[j] = 0;

	i = 0;

	ifstream file(getName(), ios::binary);
	while(!file.eof())
	{
		arr[i] = file.get();
		i++;
	}
	i--;
	arr[i] = 0;
	file.close();
	return arr;
}	   

int* fileInputDecode()
{
	int* result = new int;
	return result;
}

void fileOutputEncode(int * arr, int size, char* code, int eights)
{
	ofstream file(getName());
	for (int i = 0; i < size; i++)
	{
		if (i < size - 2)
		file << code[arr[i]];
		else
		{
			if (arr[i] == 0)
				file << '=';
			else
				file << code[arr[i]];
		}
	}
	file.close();
}

void fileOutputDecode()
{

}

int* encode(int* arr,int size)
{
	int* result = new int[size * 6];
	for (int i = 0; i < size * 6; i++)
		result[i] = 0;

	for (int i = 0, s = 0; s < size; i += 3, s += 4)
	{
		result[s] = (arr[i] & 252) >> 2;
	}

	for (int i = 0, j = 1, s = 1; s < size; i += 3, j += 3, s += 4)
	{
		result[s] = ((arr[i] & 3) << 4) + ((arr[j] & 240) >> 4);
	}

	for (int i = 1, j = 2, s = 2; s < size; i += 3, j += 3, s += 4)
	{
		result[s] = ((arr[i] & 15) << 2) + ((arr[j] & 192) >> 6);
	}

	for (int i = 2, s = 3; s < size; i += 3, s += 4)
	{
		result[s] = arr[i] & 63;
	}
	return result;
}

int* decode(int* arr, int size)
{
	int* result = new int;
	
	for (int i = 0, j = 1, s = 0; s < size; i += 4, j += 4, s += 3)
	{
		result[s] = arr[i] << 2 + ((arr[j] & 48) >> 4);
	}

	return result;
}

int* debug_fileInput(int &i)
{
	int arr[2048];
	for (int j = 0; j < 2048; j++)
		arr[j] = 0;

	i = 0;

	ifstream file("input.txt", ios::binary);
	while (!file.eof())
	{
		arr[i] = file.get();
		i++;
	}
	i--;
	arr[i] = 0;
	file.close();
	return arr;
}						//!


void main()
{
	char code[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" };
	int counter;

	int* arr;
	arr = debug_fileInput(counter);
	counter *= 8;
	int numOfEights = 0;
	
	while (counter % 6 != 0)
	{
		counter += 8;
		numOfEights++;
	}

	counter /= 6;

	//int* result = encode(arr, counter);
	//fileOutputEncode(result, counter, code, numOfEights);
	int counter_2;
	arr = debug_fileInput(counter_2);
	int* result_2 = decode(arr, counter_2);

}

//Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.
//TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=
//AAAA
//QUFBQQ==