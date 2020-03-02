#pragma once
#include <iostream>

using namespace std;

class Ivica {
	int startVrh;
	int endVrh;
	int tezina;
public:
	Ivica(int startVrh, int endVrh, int tezina) 
	{
		this->startVrh = startVrh;
		this->endVrh = endVrh;
		this->tezina = tezina;
	}

	friend ostream& operator<<(ostream& o, Ivica* i)
	{
		return operator<<(o, *i);
	}
	friend ostream& operator<<(ostream& o, Ivica& i)
	{
		o << "t(" << i.startVrh << "," << i.endVrh << ") = " << i.tezina;
		return o;
	}

	friend bool operator>(Ivica& left, Ivica& right)
	{
		return left.tezina < right.tezina;
	}
};