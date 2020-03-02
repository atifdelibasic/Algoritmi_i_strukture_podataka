#pragma once

template <class Kljuc>
class BSCvor {
public:
	BSCvor* lijevoDijete;
	BSCvor* desnoDijete;
	Kljuc value;

	BSCvor(Kljuc value) 
	{
		lijevoDijete = desnoDijete = nullptr;
		this->value = value;
	}
};