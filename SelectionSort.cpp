#include <iostream>

using namespace std;

void SelectionSort(int niz[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		int minI = i;
		for (int j = i+1; j < n; j++)
		{
			if (niz[j] < niz[minI]) 
				minI = j;
		}
		if (minI != i) {
			swap(niz[minI], niz[i]);
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

	SelectionSort(niz, vel);
	Ispis(niz, vel);

	system("pause>0");
}