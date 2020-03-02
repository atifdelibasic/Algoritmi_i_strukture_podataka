#pragma once
#include "Ivica.h"
#include "ListaSekv.h"
#include "MatricaSusjedstva.h"

class DijkstraAlgoritam {
	MatricaSusjedstva* M;
	int* dist;
	int* pred;
	bool* posjecen;
	int startVrh, endVrh;

	DijkstraAlgoritam(MatricaSusjedstva *M, int startVrh, int endVrh) 
	{
		this->M = M;
		dist = new int[M->vel];
		posjecen = new bool[M->vel];
		pred = new int[M->vel];

		this->startVrh = startVrh;
		this->endVrh = endVrh;
	}
	int minNeposjecenVrh() 
	{
		int minI = -1;
		int minDist = INT_MAX;
		for (int i = 0; i < M->vel; i++)
		{
			if (!posjecen[i] && dist[i] < minDist) {
				minI = i;
				minDist = dist[i];
			}
		}
		return minI;
	}
	
	ListaSekv<Ivica*>* _start() 
	{
		ListaSekv<Ivica*>* rezultat = new ListaSekv <Ivica*>;

		for (int i = 0; i < M->vel; i++)
		{
			dist[i] = INT_MAX;
			posjecen[i] = false;
		}

		dist[startVrh] = 0;

		for (int i = 0; i < M->vel; i++)
		{
			int nVrh = minNeposjecenVrh();
			posjecen[nVrh] = true;

			int nDist = dist[nVrh];
			for (int sVrh = 0; sVrh < M->vel; sVrh++)
			{
				if (M->isSusjed(nVrh,sVrh))
				{
					int tezina = M->tezina(nVrh, sVrh);
					int xDist = nDist + tezina;

					if (xDist < dist[sVrh]) 
					{
						pred[sVrh] = nVrh;
						dist[sVrh] = xDist;
					}
				}
			}
		}

		int end = endVrh;
		int sumDist = 0;
		while (end!=startVrh)
		{
			int start = pred[end];
			int tezina = M->tezina(start,end);
			sumDist += tezina;
			rezultat->DodajNaKraj(new Ivica(start, end, tezina));
			end = start;
		}
		cout << "Ukupna distanca je: " << sumDist << endl;
		return rezultat;
	}
public:
	static ListaSekv<Ivica*>* start(MatricaSusjedstva* M, int startVrh, int endVrh)
	{
		return DijkstraAlgoritam(M, startVrh, endVrh)._start();
	}
};