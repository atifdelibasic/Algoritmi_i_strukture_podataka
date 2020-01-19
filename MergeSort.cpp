#include <iostream>

using namespace std;

void Merge(int niz[], int temp[], int pocetak1, int vel1, int pocetak2, int vel2)
{
	int i = pocetak1;
	int j = pocetak2;
	int k = pocetak1;
	while (i < pocetak1 + vel1 && j < pocetak2 + vel2)
	{
		if (niz[i] < niz[j])
			temp[k] = niz[i++];
		else
			temp[k] = niz[j++];
		k++;
	}

	while (i < pocetak1 + vel1)
	{
		temp[k++] = niz[i++];
	}
	while (j < pocetak2 + vel2)
	{
		temp[k++] = niz[j++];
	}
	for (int i = 0; i < vel1 + vel2 + pocetak1; i++)
	{
		niz[i] = temp[i];
	}
}

void MergeSort(int niz[], int temp[], int pocetak, int vel)
{
	if (vel <= 1)
		return;
	int pocetak1 = pocetak;
	int vel1 = vel / 2;
	int vel2 = vel - vel1;
	int pocetak2 = pocetak1 + vel1;

	MergeSort(niz, temp, pocetak1, vel1);
	MergeSort(niz, temp, pocetak2, vel2);
	Merge(niz, temp, pocetak1, vel1, pocetak2, vel2);
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
	int niz[] = { 1,10,124,55,1000,123,79,1,981,32,45 };
	int temp[] = { 1,10,124,55,1000,123,79,1,981,32,45 };
	int vel = sizeof(niz) / sizeof(niz[0]);

	MergeSort(niz, temp, 0, vel);

	Ispis(niz, vel);

	system("pause>0");

}