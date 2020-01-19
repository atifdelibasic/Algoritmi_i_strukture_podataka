#include <iostream>

using namespace std;
//heap sort


void BubbleDown(int niz[], int n, int i)
{
	int LD = i*2 + 1;
	int DD = i*2 + 2;
	int maxI = i;

	if (LD<n && niz[LD]>niz[maxI])
		maxI = LD;
	if (DD<n && niz[DD]>niz[maxI])
		maxI = DD;
	if (maxI != i)
	{
		swap(niz[maxI], niz[i]);
		BubbleDown(niz, n, maxI);
	}
}

void HeapSort(int niz[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		BubbleDown(niz, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(niz[0], niz[i]);
		n--;
		BubbleDown(niz, n, 0);
	}
}

void Ispis(int niz[], int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << ", ";
	}
	cout << endl;
}

void main()
{
	int niz[] = { 1,2,11,3,100,204,132,101,55,23 };
	int vel = sizeof(niz) / sizeof(niz[0]);

	HeapSort(niz, vel);

	Ispis(niz, vel);


	system("pause>0");
}