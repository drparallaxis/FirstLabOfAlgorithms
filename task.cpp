#include<iostream>
#include<conio.h>
#include<cstring>
#include<string>
using namespace std;

void palindrome(string ftr)
{
	string str;
	if ((ftr.size() % 2) == 1)
	{
		char* buffer1 = new char[ftr.size()];
		char* buffer2 = new char[ftr.size() - 1];
		int g = 0;

		for (int i = 0; i < ftr.size(); i++)
			buffer1[i] = ftr[i];
		for (int i = 0; i < ftr.size(); i++)
		{
			if (i != ftr.size() / 2)
			{
				buffer2[g] = buffer1[i];
				g++;
			}
		}
		for (int i = 0; i < ftr.size() - 1; i++)
			str += buffer2[i];
	}

	char* half1 = new char[str.size() / 2];
	char* half2 = new char[str.size() / 2];
	int counter = 0, test = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (i < (str.size() / 2))
			half1[i] = str[i];
		else
		{
			half2[counter] = str[i];
			counter++;
		}
	}

	for (int i = 0, j = (str.size() / 2) - 1; i < str.size() / 2, j >= 0; i++, j--)
	{
		if (half1[i] == half2[j])
			test++;
	}
	if (test == str.size() / 2)
		cout << "\nYes!\n";
	else
		cout << "\nNot!\n";
}


int main()
{
	string word = "deed";

	palindrome(word);


	_getch();
}