#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<iostream>
#include <bitset>

using namespace std;

char code[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
void fileInput(int* arr, int &i)
{
	ifstream file("input.txt", ios::binary);
	while(!file.eof())
	{
		arr[i] = file.get();
		i++;
	}
	i--;
	file.close();
}

void fileOutput(int * arr, int size, char* code)
{
	ofstream file("output.txt");
	for (int i = 0; i < size; i++)
	{
		file << code[arr[i]];
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

	for (int i = 0, s = 0; s < counter; i += 3, s += 4)
	{
		result[s] = (arr[i] & 252) >> 2;
	}

	for (int i = 0 ,j = 1, s = 1; s < counter; i += 3, j += 3, s += 4)
	{
		result[s] = ((arr[i] & 3) << 4) + ((arr[j] & 240) >> 4);
	}

	for (int i = 1, j = 2, s = 2; s < counter; i += 3, j += 3, s += 4)
	{
		result[s] = ((arr[i] & 15) << 2) + ((arr[j] & 192) >> 6);
	}

	for (int i = 2, s = 3; s < counter; i += 3, s += 4)
	{
		result[s] = arr[i] & 63;
	}

	fileOutput(result, counter, code);
	//system("pause");
}

//Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.
//AAAA = QUFBQQ==

//cout << "array: ";
//for (int k = 0; k < counter; k++)
//{
//	cout << bitset<8>(arr[k]) << " , ";
//}
//cout << "\n";
//cout << "\n";
//cout << "return: ";
//for (int k = 0; k < counter; k++)
//{
//	cout << bitset<8>(result[k]) << " , ";
//}
//cout << "\n";