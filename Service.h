#pragma once
#include "Repository.h"
#include "RepoFile.h"
#include "Masina.h"
#include <iostream>

using namespace std;

class Service
{
private:
	RepoFile repoFile;
public:
	Service();
	~Service();
	void addMasinaC(Masina m);
	void updateMasinaC(int index, Masina m);
	void delMasinaC(Masina m);
	void readMasiniC();
	int getLenC();
	void citireFileC(const char* file);
	char* getStatusC(int index);
	void updateStatusC(const char* newStatus, int index);
	int getOcupatC();
	Repository getRepoC();
};