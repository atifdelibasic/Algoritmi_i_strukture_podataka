#pragma once
#include<iostream>
using namespace std;

template<class T>
class Cvor {
public:
	Cvor* next;
	T info;
	Cvor(T info, Cvor* next) {
		this->next = next;
		this->info = info;
	}
};