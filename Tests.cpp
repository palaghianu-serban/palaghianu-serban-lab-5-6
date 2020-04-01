#include "Tests.h"
#include "Masina.h"
#include "Repository.h"
#include <iostream>
#include <assert.h>
using namespace std;


void tests() {
	Masina m("Vlad", "SV98ABC", "inchiriat");
	m.setPosesor("Pala");
	char* posesor;
	posesor = m.getPosesor();
	assert(m.getPosesor() == posesor);
	m.setNr("AB31CRA");
	assert(m.getNr() == "AB31CRA");
	m.setStatus("liber");
	char* status;
	status = m.getStatus();
	assert(m.getStatus() == status);

	Masina m2 = m;                     
	Masina m3;			                 
	m3 = m2;
	assert(m3 == m2);

	cout << "Class tests working!" << endl;
}

void tests_Repo()
{
	Repository repo;
	assert(repo.getLenR() == 0);
	vector<Masina> masini;
	Masina m1("Vlad", "SV98ABC", "inchiriat");
	Masina m2("Serban", "AB88SAL", "liber");
	repo.addMasinaR(m1);
	repo.addMasinaR(m2);
	masini = repo.getAllR();
	assert(repo.getLenR() == 2);
	Masina m3;
	Masina m4;
	m3 = m1;
	m4 = m2;
	assert(masini[0] == m3);
	assert(masini[1] == m4);

	cout << "Repo tests working!" << endl;
}