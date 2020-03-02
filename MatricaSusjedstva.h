#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ListaSekv.h"
using namespace std;

class MatricaSusjedstva {

public:
	int** M;
	int vel;

	MatricaSusjedstva(int vel) {
		this->vel = vel;
		M = new int* [vel];
		for (int i = 0; i < vel; i++)
		{
			M[i] = new int[vel];
			for (int j = 0; j < vel; j++)
			{
				M[i][j] = 0;
			}
		}
	}

	void UcitajMatricu(string filename) 
	{
		ifstream fin(filename);
		int a;
		for (int i = 0; i < vel; i++)
		{
			for (int j = 0; j < vel; j++)
			{
				fin >> a;
				M[i][j] = a;
			}
		}
		fin.close();
	}

	int IzlazniStepen(int i) {
		int suma = 0;
		for (int j = 0; j < vel; j++)
		{
			suma += M[i][j];
		}
		return suma;
	}

	int UlazniStepen(int j) {
		int suma = 0;
		for (int i = 0; i < vel; i++)
		{
			suma += M[i][j];
		}
		return suma;
	}

	int IzlazniStepenMax() {
		int maxI = 0;
		int maxV = IzlazniStepen(maxI);

		for (int i = 1; i < vel; i++)
		{
			int t = IzlazniStepen(i);
			if (t > maxV) {
				maxV = t;
				maxI = i;
			}
		}
		return maxI;
	}

	int UlazniStepenMax() {
		int maxI = 0;
		int maxV = UlazniStepen(maxI);

		for (int i = 1; i < vel; i++)
		{
			int t = UlazniStepen(i);
			if (t > maxV) {
				maxV = t;
				maxI = i;
			}
		}
		return maxI;
	}

	ListaSekv<int>* susjediTo(int x) {
		ListaSekv<int>* lista = new ListaSekv<int>;

		for (int j = 0; j < vel; j++)
		{
			if (isSusjed(x,j))
				lista->DodajNaKraj(j);
		}
		return lista;
	}

	ListaSekv<int>* susjediFrom(int x) {
		ListaSekv<int>* lista = new ListaSekv<int>();

		for (int i = 0; i < vel; i++)
		{
			if (isSusjed(i,x)) 
				lista->DodajNaKraj(i);
		}
		return lista;
	}

	int najbliziSusjed(int x) {
		ListaSekv<int>* lista = susjediTo(x);

		int minI = -1;
		int minTezina = INT_MAX;

		while (!lista->JelPrazna())
		{
			int s = lista->UkloniSaKraja();
			int t = tezina(x, s);

			if (t < minTezina) {
				minI = s;
				minTezina = t;
			}
		}
		return minI;
	}

	bool isSusjed(int i, int j) {
		return M[i][j] != 0;
	}

	int tezina(int i, int j) {
		return M[i][j];
	}

	void Ispis() {
		for (int i = 0; i < vel; i++)
		{
			for (int j = 0; j < vel; j++)
			{
				cout << M[i][j] << " ";
			}
			cout << endl;
		}
	}
};