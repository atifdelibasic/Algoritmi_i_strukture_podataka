#pragma once
#include <iostream>
#include "Cvor.h"
using namespace std;

template<class T>
class StekPov {
	Cvor<T>* prvi;

public:
	StekPov() 
	{
		prvi = nullptr;
	}
	void Dodaj(T info) {
		Cvor<T>* t = new Cvor<T>(info, prvi);
		prvi = t;
	}

	void UkloniSaPocetka() {
		if (JelPrazan()) {
			throw exception("Stek je prazan!");
		}
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
			cout << t->info << endl;
			t = t->next;
		}
	}
};