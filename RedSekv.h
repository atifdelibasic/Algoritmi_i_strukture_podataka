#pragma once
using namespace std;

template<class T> 
class RedSekv {
	T* niz; 
	int brojac;
	int max;
	int pocetak, kraj;

	void ProsiriRed() 
	{
		int newMax = max * 2;
		T* temp = new T[newMax];
		int newI = 0;
		int oldI = pocetak;
		while (newI < brojac)
		{
			temp[newI++] =niz[oldI++];
			if (oldI == max)
				oldI = 0;
		}
		max = newMax;
		delete[] niz;
		niz = temp;
		pocetak = 0;
		kraj = brojac;
	}
public:
	RedSekv(int max = 1)
	{
		this->max = 10;
		niz = new int[this->max];
		brojac = pocetak = kraj = 0;
	}

	void Dodaj(T x) {
		if (JelPun()) 
			ProsiriRed();

		niz[kraj++] = x;
		if (kraj == max) 
			kraj = 0;
		
		brojac++;
	}

	void Ukloni() {
		if (JelPrazan())
			throw exception("Red je prazan!");

		pocetak++;
		if (pocetak == max) 
			pocetak = 0;
		
		brojac--;
	}

	bool JelPrazan() {
		return brojac == 0;
	}

	bool JelPun() {
		return brojac == max;
	}

	void Print() {
		int i = pocetak;
		int b = 0;
		while (b++ < brojac)
		{
			cout << niz[i++] << " ";
			if (i == max)
				i = 0;
		}
	}
};