#pragma once
#include <iostream>
using namespace std; 

const char *poruka = "Niz je prazan!";

template<class T>
class ListaSekv {
	T* niz;
	int brojac;
	int max;
	void ProsiriNiz() {
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
	ListaSekv(int max=10)
	{
		this->max = max;
		brojac = 0;
		niz = new T[this->max];
	}

	void DodajNaPocetak(T x) {
		if (JelPun())
			ProsiriNiz();
		
		for (int i = brojac; i > 0; i--)
		{
			niz[i] = niz[i - 1];
		}
		niz[0] = x;
		brojac++;
	}

	void DodajNaKraj(T x) {
		if (JelPun())
			ProsiriNiz();
		niz[brojac++] = x;
	}

	void UkloniSaPocetka() {
		if (JelPrazna()) 
			throw exception(poruka);

		for (int i = 1; i < brojac; i++)
		{
			niz[i - 1] = niz[i];
		}
		brojac--;
	}

	T UkloniSaKraja() {
		if (JelPrazna()) 
			throw exception(poruka);

		T el = niz[brojac];
		brojac--;
		return el;
	}

	bool JelPun() {
		return brojac == max;
	}

	bool JelPrazna() {
		return brojac == 0;
	}

	void Print() {
		for (int i = 0; i < brojac; i++)
		{
			cout << niz[i] << " ";
		}
	}
};