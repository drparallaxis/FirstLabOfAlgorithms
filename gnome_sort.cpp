#include<iostream>
#include<conio.h>
#include<vector>
#include<ctime>
#include<random>
using namespace std;

//Реализация алгоритма гномьей сортировки
void gnome_sort(vector<int> &arr, int& comparison, int& permutation)
{
	comparison = permutation = 0;
	int counter = 0;
	while (counter + 1 < arr.size())
	{
		if (arr[counter] <= arr[counter + 1])
		{
			counter++;
			comparison++;
		}
		else
		{
			swap(arr[counter], arr[counter + 1]);
			counter--;
			permutation++;
			if (counter < 0)
			{
				counter = 0;
				comparison++;
			}
		}
	}
}

void gnome_sort_void()
{
	//9, 8, 7, 6, 5, 4, 3, 2, 1, 0
	//4, 7, 9, 2, 5, 0, 1, 3, 6, 8

	unsigned int start_time = 0, end_time = 0;
	int comparison = 0, permutation = 0;

	//1-st array
	vector<int> arr1(10);
	cout << "1-st array of gnome sort: ";
	for (int i = 0, j = 9; i < 10, j >= 0; i++, j--)
	{
		arr1[i] = j;
		cout << arr1[i] << ", ";
	}
	cout << "\n\n";
	gnome_sort(arr1, comparison, permutation);
	for (int i = 0; i < 10; i++)
		cout << arr1[i] << ", ";
	cout << "\n\nnumber of comparisons: " << comparison << ",  number of permutations: " << permutation;
	comparison = 0, permutation = 0;


	//2-nd array
	vector<int> arr2(10);
	arr2[0] = 4, arr2[1] = 7, arr2[2] = 9, arr2[3] = 2, arr2[4] = 5, arr2[5] = 0, arr2[6] = 1, arr2[7] = 3, arr2[8] = 6, arr2[9] = 8;
	cout << "\n\n2-nd array of gnome sort: ";
	for (int i = 0; i < 10; i++)
		cout << arr2[i] << ", ";
	cout << "\n\n";
	gnome_sort(arr2, comparison, permutation);
	for (int i = 0; i < 10; i++)
		cout << arr2[i] << ", ";
	cout << "\n\nnumber of comparisons: " << comparison << ",  number of permutations: " << permutation;
	comparison = 0, permutation = 0;


	//array of 100 random numbers
	cout << "\n\n\n\n3-st array of gnome sort: \n";
	vector<int> arr3(100);
	for (int i = 0; i < 100; i++)
	{
		arr3[i] = 1 + rand() % 100;
		cout << arr3[i] << ", ";
	}
	cout << "\n\n";
	start_time = clock();
	gnome_sort(arr3, comparison, permutation);
	end_time = clock();
	for (int i = 0; i < 100; i++)
		cout << arr3[i] << ", ";
	cout << "\n\nnumber of comparisons: " << comparison << ",  number of permutations: " << permutation\
		<< "\n\nsorting time: " << end_time - start_time << " milliseconds";
	comparison = 0, permutation = 0;
	start_time = 0, end_time = 0;


	//array of 1000 random numbers
	cout << "\n\n\n\n4-th array of gnome sort: \n";
	vector<int> arr4(1000);
	for (int i = 0; i < 1000; i++)
	{
		arr4[i] = 1 + rand() % 1000;
		cout << arr4[i] << ", ";
	}
	cout << "\n\n";
	start_time = clock();
	gnome_sort(arr4, comparison, permutation);
	end_time = clock();
	for (int i = 0; i < 1000; i++)
		cout << arr4[i] << ", ";
	cout << "\n\nnumber of comparisons: " << comparison << ",  number of permutations: " << permutation\
		<< "\n\nsorting time: " << end_time - start_time << " milliseconds";
	comparison = 0, permutation = 0;
	start_time = 0, end_time = 0;
}

int main()
{
	srand(time(NULL));

	gnome_sort_void();

	_getch();
}
