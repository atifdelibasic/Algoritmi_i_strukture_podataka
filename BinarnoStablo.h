#pragma once
#include<iostream>
#include "BSCvor.h"

using namespace std;

template<class Kljuc>
class Binarnostablo {

	bool rekurzija_dodaj(BSCvor<Kljuc>*& bscvor, Kljuc value) 
	{
		if (bscvor == nullptr) {
			bscvor = new BSCvor<Kljuc>(value);
			return true;
		}
		if (bscvor->value == value)
			return false;
		if (value < bscvor->value)
			rekurzija_dodaj(bscvor->lijevoDijete, value);
		else
			rekurzija_dodaj(bscvor->desnoDijete, value);
	}

	BSCvor<Kljuc>* rekurzija_trazi(BSCvor<Kljuc>*& bscvor, Kljuc value)
	{
		if (bscvor == nullptr)
			return nullptr;
		if (bscvor->value == value)
			return bscvor;
		if (value< bscvor->value)
			rekurzija_trazi(bscvor->lijevoDijete, value);
		else
			rekurzija_trazi(bscvor->desnoDijete, value);
	}

public:
	BSCvor<Kljuc>* korijen;

	Binarnostablo()
	{
		korijen = nullptr;
	}

	bool Dodaj(Kljuc value) {
		return rekurzija_dodaj(korijen, value);
	}

	BSCvor<Kljuc>* Trazi(Kljuc value) {
		return rekurzija_trazi(korijen, value);
	}

};