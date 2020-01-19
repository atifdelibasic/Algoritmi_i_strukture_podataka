//Binary Search
#include <iostream>

using namespace std;


int BinarySearch(int niz[], int pocetak, int kraj, int x)
{
	while (pocetak<=kraj)
	{
	int sredina = pocetak + (kraj - pocetak) / 2;
		if (niz[sredina] == x)
			return sredina;
		
		if (niz[sredina] < x)
			pocetak = sredina + 1;
		else
			kraj = sredina - 1;
	}
	return -1;
}

void main()
{
	int niz[] = { 2,3,4,10,40 };
	int vel = sizeof(niz) / sizeof(niz[0]);
	int pretraga = 4;

	int rezultat = BinarySearch(niz, 0, vel - 1, pretraga);
	if (rezultat != -1)
		cout << "Indeks: " << rezultat << endl;
	else
		cout << "Broj ne postoji!" << endl;

	system("pause>0");
}
