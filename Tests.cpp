#include "Tests.h"
#include "Masina.h"
#include "Repository.h"
#include "Service.h"
#include <iostream>
#include <assert.h>
using namespace std;

void testMasina()
{
	//teste clasa Masina
	Masina m1 = Masina("Pala", "SV98BDJ", "liber");
	assert(strcmp(m1.getPosesor(), "Pala") == 0);
	m1.setNr("SV98SER");
	Masina m2 = Masina(m1);
	assert(m1.compare(m2) == true);
	assert(strcmp(m1.getNr(), m2.getNr()) == 0);
	m2.setStatus("inchiriat");
	assert(strcmp(m2.getStatus(), "inchiriat") == 0);
	Masina m = Masina();
	assert(m.getPosesor() == NULL);
	assert(m.getNr() == NULL);
	assert(m.getStatus() == NULL);
	m.setPosesor("VLADIMIR");
	assert(m.getPosesor() != NULL);
	cout << "Testele Masina OK!" << endl;
}

void testRepo()
{
	//teste clasa Repository
	Repository repo;
	assert(repo.getLenR() == 0);
	assert(repo.getAllR().empty() == true);

	Masina m1 = Masina("Pala", "SV32GWD", "liber");
	Masina m2 = Masina("Vlad", "SV52FWF", "inchiriat");
	Masina m3 = Masina("Gabi", "SV31FWD", "liber");
	Masina m4 = Masina("Mirik", "SV35FWD", "inchiriat");
	Masina m5 = Masina(m1);

	repo.addMasinaR(m1);
	repo.addMasinaR(m2);
	repo.addMasinaR(m3);
	repo.addMasinaR(m4);
	repo.addMasinaR(m5);

	assert(repo.getLenR() == 5);
	//repo.delMasinaR(m1);
	//assert(repo.getLenR() == 3);

	repo.updateMasinaR(2, m3);
	assert(repo.findElemR(m1) == true);
	assert(repo.getAllR().empty() == false);

	cout << "Testele Repository OK!" << endl;
}

void testServ()
{
	//teste clasa Service
	Service serv;
	assert(serv.getRepoC().getAllR().empty() == true);

	Masina m1 = Masina("Pala", "SV32GWD", "liber");
	Masina m2 = Masina("Vlad", "SV52FWF", "inchiriat");
	Masina m3 = Masina("Gabi", "SV31FWD", "liber");
	Masina m4 = Masina("Mirik", "SV35FWD", "inchiriat");

	serv.addMasinaC(m1);
	serv.addMasinaC(m2);
	serv.addMasinaC(m3);
	serv.addMasinaC(m4);

	assert(serv.getRepoC().getLenR() == 4);
	serv.updateMasinaC(0, m4);
	assert(serv.getRepoC().findElemR(m1) == false);

	//serv.deleteMasinaC(m4);
	//assert(serv.getLenC() == 2);

	serv.getRepoC().getAllR().clear();
	assert(serv.getLenC() != 0);
	assert(serv.getRepoC().getAllR().empty() == false);

	cout << "Testele Service OK!" << endl;
}

void testRepoFile()
{
	RepoFile repoFile;
	list<Masina>::iterator i = repoFile.getAllR().begin();
	Masina m = Masina("Andreea", "B312NGW", "ocupat");
	const char* file = new char[50];
	file = "intrare.txt";
	repoFile.citireFileR(file);
	assert(repoFile.getLenR() == 4);
	repoFile.delMasinaIndexR(1);
	assert(repoFile.getLenR() == 3);
	assert(repoFile.findElemR(m) == true);
	assert(repoFile.findNrR(m.getNr()) == true);

	cout << "Testele pentru clasa RepoFile functioneaza" << endl;
}