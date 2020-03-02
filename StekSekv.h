#pragma once
#include <iostream>
using namespace std;

template<class T>
class StekSekv {
	T* niz;
	int brojac;
	int max;

	void ProsiriStek() {
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
	StekSekv(int max = 10)
	{
		this->max = max;
		brojac = 0;
		niz = new T[this->max];
	}

	void Dodaj(T x) {
		if (JelPun())
			ProsiriStek();
		niz[brojac++] = x;
	}

	void Ukloni() {
		if (JelPrazan())
			throw exception("Stek je prazan!");
		brojac--;
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