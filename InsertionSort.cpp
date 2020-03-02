#include <iostream>

using namespace std;

void InsertionSort(int niz[], int n) {
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j>0 && niz[j]< niz[j-1])
		{
			swap(niz[j], niz[j - 1]);
			j--;
		}
	}
}

void Ispis(int niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}

void main() {
	int niz[] = { 1,23,11,9,32,105,2 };
	int vel = sizeof(niz) / sizeof(niz[0]);

	InsertionSort(niz, vel);
	Ispis(niz, vel);

	system("pause>0");
}