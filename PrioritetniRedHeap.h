#pragma once
#include <iostream>
using namespace std;
template<class Tip>
class PrioritetniRedHeap
{
	int max;
	Tip* A;
	int n;

	int GetPozLijevoDijete(int i)
	{
		return i * 2;
	}
	int GetPozDesnoDijete(int i)
	{
		return i * 2 + 1;
	}
	int GetPozRoditelj(int i)
	{
		return i / 2;
	}
	bool JelImaDesnoDijete(int i)
	{
		return GetPozDesnoDijete(i) <= n;
	}
	bool JelImaLijevoDijete(int i)
	{
		return GetPozLijevoDijete(i) <= n;
	}
	bool JelList(int i)
	{
		return !JelImaLijevoDijete(i);
	}

	void Rotiraj(int i, int j)
	{
		Tip temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	void ProsiriPrRed() {
		int newMax = max * 2;
		Tip* temp = new Tip[newMax];
		for (int i = 0; i < max; i++)
		{
			temp[i] = A[i];
		}
		delete[] A;
		A = temp;
		max = newMax;
	}

public:
	PrioritetniRedHeap(int max=1) {
		n = 0;
		this->max = max;
		A = new Tip[this->max];
	}

	void Dodaj(Tip x)
	{
		if (JelPun())
			ProsiriPrRed();
		n++;
		A[n] = x;
		BubbleUp(n);
	}

	Tip Ukloni()
	{
		if (JelPrazan())
			return 0;
		Tip x = A[1];
		A[1] = A[n];
		n--;
		BubbleDown(1);
		return x;
	}

	void BubbleUp(int i)
	{
		if (i == 1)
			return;
		int r = GetPozRoditelj(i);

		if (A[r] < A[i])
		{
			Rotiraj(r, i);
			BubbleUp(r);
		}
	}

	void BubbleDown(int i)
	{
		if (JelList(i))
			return;
		int maxI = i;
		int LD = GetPozLijevoDijete(i);

		if (A[LD] > A[i])
			maxI = LD;
		if (JelImaDesnoDijete(i))
		{
			int DD = GetPozDesnoDijete(i);
			if (A[DD] > A[maxI])
				maxI = DD;
		}
		if (maxI != i)
		{
			Rotiraj(maxI, i);
			BubbleDown(maxI);
		}
	}

	bool JelPun()
	{
		return n == max-1;
	}

	bool JelPrazan()
	{
		return n == 0;
	}

};