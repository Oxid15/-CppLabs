#include<fstream>

using namespace std;

void fileInput(int* arr, int &i)
{
	ifstream iFile("input.txt", ios::binary);
	while(!iFile.eof())
	{
		arr[i] = iFile.get();
		i++;
	}
}

void main()
{
	int counter = 0;
	int arr[2048];
	fileInput(arr,counter);

	int addCount = 0;
	while (counter % 6 == 0)
	{
		counter += 8;
		addCount++;
	}

}