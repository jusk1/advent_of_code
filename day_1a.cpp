// day_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
	This program looks for 2 integers in the input file that sum to 2020
	and outputs their product. If not found, then the output is -1;
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int partition(vector<int>& v, int lo, int hi);
void quickSort(vector<int>& v, int lo, int hi);
int find2020two(vector<int>& v);
int find2020three(vector<int>& v);

int main()
{
	fstream fin;
	fin.open("input.txt");
	if (fin.fail())
	{
		cout << "Cannot find file.\n";
		exit(1);
	}

	vector<int> v;
	int value;
	while (fin >> value) // scans each value 
	{
		v.push_back(value); // adds them to the vector
	}

	quickSort(v, 0, v.size() - 1);

	/*int format = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 1000)
			cout << " ";
		cout << v[i] << " ";
		format++;
		if (format % 20 == 0)
			cout << endl;
	}
	cout << endl;
	*/
	cout << "2 Sum answer: " << find2020two(v) << endl;
	cout << "3 Sum answer: " << find2020three(v) << endl;
	fin.close();
	return 0;
}

void quickSort(vector<int>& v, int lo, int hi)
{
	if (hi <= lo)
		return;
	int j = partition(v, lo, hi);
	quickSort(v, lo, j - 1);
	quickSort(v, j + 1, hi);
}

int partition(vector<int>& v, int lo, int hi)
{
	int i = lo, j = hi + 1;
	while (true)
	{
		while (v[++i] < v[lo])
			if (i == hi)
				break;
		while (v[lo] < v[--j])
			if (j == lo)
				break;
		if (i >= j)
			break;
		else
			swap(v[i], v[j]);
	}
	swap(v[lo], v[j]);
	return j;
}

int find2020two(vector<int>& v) // adds beginning and end of the vector
{
	int i = 0, j = v.size() - 1;
	while (j > i) // end if the pointers cross
	{
		if (v[i] + v[j] == 2020)
			return (v[i] * v[j]);
		if (v[i] + v[j] < 2020) // if the sum is less than 2020, then increase the lower number
			i++;
		else					// if the sum is greater than 2020, then decrease the higher number
			j--;
	}
	return -1; // if not found, return -1;
}

int find2020three(vector<int>& v) // iterates the find2020two through the entire vector 
{
	for (int k = 0; k < v.size(); k++)
	{
		int i = k+1, j = v.size() - 1;
		while (j > i) // end if the pointers cross
		{
			if (v[k] + v[i] + v[j] == 2020)
				return (v[k] * v[i] * v[j]);
			if (v[k] + v[i] + v[j] < 2020) // if the sum is less than 2020, then increase the lower number
				i++;
			else					// if the sum is greater than 2020, then decrease the higher number
				j--;
		}
	}
	return -1; // if not found, return -1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
