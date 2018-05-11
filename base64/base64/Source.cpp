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

int* fileInput(int &i)
{
	int arr[2048];
	for (int j = 0; j < 2048; j++)
		arr[j] = 0;

	i = 0;

	ifstream file("input.txt", ios::binary);
	while(!file.eof())
	{
		arr[i] = file.get();
		i++;
	}
	i--;
	arr[i] = 0;
	file.close();
	//int* result = new int[i];
	//for (int j = 0; j < i; j++)
	//{
	//	result[j] = arr[j];
	//}
	//return result;
	return arr;
}

int* _fileInput(int &i)
{
	int arr[2048];
	for (int j = 0; j < 2048; j++)
		arr[j] = 0;

	i = 0;

	ifstream file("input.txt", ios::binary);
	while (!file.eof())
	{
		arr[i] = file.get() - 65;
		i++;
	}
	i--;
	arr[i] = 0;
	file.close();
	return arr;
}

void fileOutputEncode(int * arr, int size, char* code, int eights)
{
	ofstream file("output.txt");
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

void fileOutputDecode(int* arr, int size)
{
	ofstream file("output.txt");
	for (int i = 0; i < size; i++)
	{
		file << arr[i] << " ";
	}
	file.close();
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

	for (int i = 0, j = 1, s = 0; i < size; i += 4, j += 4, s += 3)
	{
		result[s] = (arr[i] << 2) + ((arr[j] & 48) >> 4);
	}

	for (int i = 1, j = 2, s = 1; s < size; i += 4, j += 4, s += 3)
	{
		result[s] = ((arr[i] & 15) << 4) + ((arr[j] >> 2) & 15);
	}

	//for (int i = 2, j = 3, s = 2; s < size; i += 4, j += 4, s += 3)
	//{
	//	result[s] = ((arr[i] & 3) << 6) + ((arr[j] & 63));
	//}

	return result;
}



void main()
{
	char code[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" };

	//int size;
	//int* arr = new int;
	//arr = fileInput(size);
	//size *= 8;
	//int numOfEights = 0;
	//while (size % 6 != 0)
	//{
	//	size += 8;
	//	numOfEights++;
	//}
	//size /= 6;

	//int* result = encode(arr, size);
	//fileOutputEncode(result, size, code, numOfEights);

	int size_2;
	int* arr_2 = new int;
	arr_2 = _fileInput(size_2);
	int numOfEights_2 = 0;
	for (int i = size_2; i > (size_2 - 3); i--)
	{
		if (arr_2[i] == '=')
			numOfEights_2++;
	}
	size_2 *= 6;
	size_2 -= numOfEights_2 * 8;
	size_2 /= 8; 
	
	int* result_2 = decode(arr_2, size_2);
	fileOutputDecode(result_2, size_2);
}

//Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.
//TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=
//AAAA
//QUFBQQ==