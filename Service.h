#pragma once
#include "Repository.h"
#include "Masina.h"
#include <iostream>

using namespace std;

class Service
{
private:
	Repository repo;
public:
	Service();
	~Service();
	void addMasinaC(Masina m);
	void updateMasinaC(int index, Masina m);
	void delMasinaC(Masina m);
	void readMasiniC();
	int getLenC();
	Repository getRepoC();
};