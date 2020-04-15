#pragma once
#include "Masina.h"
#include <list>
#include <iterator>

class Repository {
private:
	list<Masina> masini;
	list<Masina>::iterator i;
public:
	Repository();
	~Repository();
	void addMasinaR(Masina m);
	void delMasinaR(Masina m);
	void delMasinaIndexR(int index);
	void updateMasinaR(int index, Masina m);
	int getLenR();
	bool findElemR(Masina m);
	bool findNrR(char* n);
	char* getStatusR(int index);
	void updateStatusR(const char* newStatus, int index);
	list<Masina> getAllR();
};
