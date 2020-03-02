#pragma once
#include "BSCvor.h"
#include "ListaPov.h"
#include "BinarnoStablo.h"

template<class Kljuc>
class BSObilazak {

	BSObilazak() {

	}

	static void rekurzija_PostOrder(BSCvor<Kljuc>*& cvor,ListaPov<Kljuc> *lista ) 
	{
		if (cvor != nullptr)
		{
			rekurzija_PostOrder(cvor->lijevoDijete, lista);
			rekurzija_PostOrder(cvor->desnoDijete, lista);
			lista->DodajNaKraj(cvor->value);
		}
	}

	static void rekurzija_PreOrder(BSCvor<Kljuc>* cvor, ListaPov<Kljuc>* lista)
	{
		if (cvor != nullptr)
		{
			lista->DodajNaKraj(cvor->value);
			rekurzija_PreOrder(cvor->lijevoDijete, lista);
			rekurzija_PreOrder(cvor->desnoDijete, lista);
		}
	}
	static void rekurzija_InOrder(BSCvor<Kljuc>*cvor, ListaPov<Kljuc>* lista)
	{
		if (cvor != nullptr)
		{
			rekurzija_InOrder(cvor->lijevoDijete, lista);
			lista->DodajNaKraj(cvor->value);
			rekurzija_InOrder(cvor->desnoDijete, lista);
		}
	}
public:

	static ListaPov<Kljuc>* PreOrder(Binarnostablo<Kljuc> stablo) 
	{
		ListaPov<Kljuc>* lista = new ListaPov<Kljuc>();
		rekurzija_PreOrder(stablo.korijen, lista);
		return lista;
	}

	static ListaPov<Kljuc>* PostOrder(Binarnostablo<Kljuc> stablo)
	{
		ListaPov<Kljuc>* lista = new ListaPov<Kljuc>();
		rekurzija_PostOrder(stablo.korijen, lista);
		return lista;
	}

	static ListaPov<Kljuc>* InOrder(Binarnostablo<Kljuc>& stablo)
	{
		ListaPov<Kljuc>* lista = new ListaPov<Kljuc>();
		rekurzija_InOrder(stablo.korijen, lista);
		return lista;
	}

};