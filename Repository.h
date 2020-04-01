#pragma once
#include "Masina.h"
#include <vector>
class Repository {
private:
	vector<Masina> lista;
public:
	Repository();
	~Repository();
	void addMasinaR(Masina);
	bool findMasinaR(Masina);
	int getLenR();
	vector<Masina> getAllR();
};
