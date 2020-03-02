#pragma once
using namespace std;

template<class T>
class PrioritetniRedSekv {
	T* niz;
	int brojac;
	int max;

	void ProsiriPrRed() {
		max = max * 2;
		T* temp = new T[max];
		for (int i = 0; i < brojac; i++)
		{
			temp[i] = niz[i];
		}
		delete[] niz;
		niz = temp;
	}

public:
	PrioritetniRedSekv(int max = 10)
	{
		this->max = max;
		brojac = 0;
		niz = new T[this->max];
	}

	void Dodaj(T x) {
		if (JelPun())
			ProsiriPrRed();
		niz[brojac++] = x;
	}

	void Ukloni() {
		if (JelPrazan())
			throw exception("Prioritetni red je prazan!");

		int maxI = 0;
		int maxV = niz[0];
		for (int i = 1; i < brojac; i++)
		{
			if (niz[i] > maxV) {
				maxV = niz[i];
				maxI = i;
			}
		}
		brojac--;
		niz[maxI] = niz[brojac];
	}

	bool JelPun() {
		return brojac == max;
	}

	bool JelPrazan() {
		return brojac == 0;
	}

	void Print() {
		for (int i = 0; i < brojac; i++)
		{
			cout << niz[i] << " ";
		}
	}
};