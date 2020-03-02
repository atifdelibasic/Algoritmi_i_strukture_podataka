#pragma once
#include "Cvor.h"
const char poruka[] = "Prioritetni red je prazan!";

template<class T>
class PrioritetniRedPov {
	Cvor<T>* prvi;
public:
	PrioritetniRedPov()
	{
		prvi = nullptr;
	}

	void Dodaj(T x) {
		Cvor<T>* t = prvi;
		Cvor<T>* bt = nullptr;
		while (t != nullptr && t->info < x)
		{
			bt = t;
			t = t->next;
		}
		Cvor<T>* n = new Cvor<T>(x, t);
		if (bt == nullptr) {
			prvi = n;
		}
		else {
			bt->next = n;
		}
	}

	void Ukloni() {
		if (JelPrazan())
			throw exception(poruka);
		Cvor<T>* t = prvi;
		prvi = prvi->next;
		delete t;
	}

	bool JelPrazan() {
		return prvi == nullptr;
	}

	void Print() {
		Cvor<T>* t = prvi;
		while (t != nullptr)
		{
			cout << t->info << " ";
			t = t->next;
		}
	}
};