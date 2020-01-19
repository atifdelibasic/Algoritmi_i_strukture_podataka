#include <iostream>

using namespace std;

int GetMax(int niz[], int vel)
{
	int max = INT_MIN;
	for (int i = 0; i < vel; i++)
	{
		if (niz[i] > max)
			max = niz[i];
	}
	return max;
}

void RadixSort(int niz[], int n, int exp)
{
	int counter[10] = { 0 };
	int* pomocni = new int[n];

	for (int i = 0; i < n; i++)
		counter[(niz[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		counter[i] += counter[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		int c = (niz[i] / exp) % 10;
		int& p = counter[c];
		p--;
		pomocni[p] = niz[i];
	}
	for (int i = 0; i < n; i++)
	{
		niz[i] = pomocni[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cout << niz[i] << "-";
	}
	cout << endl;
}

void Sortiraj(int niz[], int n)
{
	int max = GetMax(niz, n);

	int exp = 1;
	while (max > 0)
	{
		RadixSort(niz, n, exp);
		exp *= 10;
		max /= 10;
	}
}

void Ispis(int niz[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << ", ";
	}
	cout << endl;
}

void main()
{
	int niz[]{ 5,9,4,  8, 353,2, 5, 9, 7, 55, 10, 98 ,44, 11, 87, 98, 14, 66 };
	int n = sizeof(niz) / sizeof(niz[0]);

	Sortiraj(niz, n);

	Ispis(niz, n);
	
	system("pause>0");
}