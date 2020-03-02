#pragma once
#include "Cvor.h"

template<class T>
class RedPov {
	Cvor<T>* pocetak;
	Cvor<T>* kraj;
public:
	RedPov()
	{
		pocetak = kraj = nullptr;
	}

	void Dodaj(T x) {
		Cvor<T>* n = new Cvor<T>(x, nullptr);
		if (pocetak == nullptr) {
			pocetak = n;
		}
		else {
			kraj->next = n;
		}
		kraj = n;
	}

	void Ukloni() {
		if (JelPrazan())
			throw exception("Red je prazan!");

		Cvor<T>* t = pocetak;
		pocetak = pocetak->next;
		if (pocetak == nullptr)
			kraj == nullptr;
		delete t;
	}

	bool JelPrazan() {
		return pocetak == nullptr;
	}

	void Print() {
		Cvor<T>* t = pocetak;
		while () {

		}
	}
};