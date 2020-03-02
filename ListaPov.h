#pragma once
#include <iostream>
#include "Cvor.h"
using namespace std;

template<class T>
class ListaPov {
	Cvor<T>* prvi;

public:
	ListaPov() {
		prvi = nullptr;
	}

	void DodajNaPocetak(T info) {
		Cvor<T>* t = new Cvor<T>(info, prvi);
		prvi = t;

	}

	void DodajNaKraj(T info) {
		if (JelPrazna()) {
			prvi = new Cvor<T>(info, nullptr);
			return;
		}
		Cvor<T>* t = prvi;
		while (t->next!=nullptr)
		{
			t = t->next;
		}
		t->next = new Cvor<T>(info, nullptr);
	}

	void UkloniSaPocetka() {
		if (JelPrazna()) {
			cout << "Lista je prazna!" << endl;
			return;
		}
		Cvor<T>* t = prvi;
		prvi = prvi->next;
		delete t;
	}

	void UkloniSaKraja() {
		if (JelPrazna()) {
			cout << "Lista je prazna!" << endl;
			return;
		}
		Cvor<T>* t = prvi;
		Cvor<T>* bt = nullptr;
		while (t->next != nullptr) {
			bt = t;
			t = t->next;
		}
		if (bt == nullptr) {
			prvi = nullptr;
		}
		else {
			bt->next = nullptr;
		}
		delete t;
	}

	int GetBrojac() {
		Cvor<T>* t = prvi;
		int brojac = 0;
		while (t!=nullptr)
		{
			t = t->next;
			brojac++;
		}
		return brojac;
	}

	void DodajNti(T info, int index) {
		int brojac = GetBrojac();
		if (index > brojac || index < 0) { return; }
		if(index == 0){
			DodajNaPocetak(info);
			return;
		}
		if (index == brojac){ 
			DodajNaKraj(info); 
			return; 
		}
		Cvor<T>* t = prvi;
		Cvor<T>* bt = nullptr;
		int i = 0;
		while (i != index) {
			bt = t;
			t = t->next;
			i++;
		}
		bt->next = new Cvor<T>(info, t);
	}

	bool JelPrazna() {
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