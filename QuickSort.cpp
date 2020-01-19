#include <iostream>

using namespace std;

void Swap(int niz[], int low, int pivotloc)
{
	int temp = niz[low];
	niz[low] = niz[pivotloc];
	niz[pivotloc] = temp;
}

int Partition(int niz[], int low, int high)
{
	int pivotloc = low;
	int pivotkey = niz[low];
	for (int i = low + 1; i <= high; i++)
	{
		if (niz[i] < pivotkey)
			Swap(niz, ++pivotloc, i);
	}
	Swap(niz, low, pivotloc);
	return pivotloc;
}

void Rekurzija(int niz[], int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(niz, low, high);
		Rekurzija(niz, low, pivotloc - 1);
		Rekurzija(niz, pivotloc + 1, high);
	}
}
void Ispis(int niz[], int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << endl;
	}
}
void main()
{
	int niz[] = { 11,32,4,0,10,151 };
	int vel = sizeof(niz) / sizeof(niz[0]);
	Rekurzija(niz, 0, vel - 1);

	Ispis(niz, vel);

	system("pause>0");
}