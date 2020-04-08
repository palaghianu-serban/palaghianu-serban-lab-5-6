#include "Service.h"

Service::Service()
{
	//constructor default
	this->repo = {};
}

Service::~Service()
{
	//destructor
	if (!this->repo.getAllR().empty())
		this->repo.getAllR().clear();
}

void Service::addMasinaC(Masina m)
{
	//adauga o masina folosind functia add din repo
	//in: m de tip masina
	//out: -
	this->repo.addMasinaR(m);
}

void Service::updateMasinaC(int index, Masina m)
{
	//actualizeaza o masina folosind functia update din repo
	//in: index de tip int si m de tip masina
	//out: -
	this->repo.updateMasinaR(index, m);
}

void Service::delMasinaC(Masina m)
{
	//sterge o masina folosind functia delete din repo
	//in: m de tip masina
	//out: -
	this->repo.delMasinaR(m);
}

void Service::readMasiniC()
{
	//afiseaza lista de masini folosind toString
	for (auto elem : this->repo.getAllR())
		cout << elem.toString() << endl;
}

int Service::getLenC()
{
	//returneaza lungimea listei de masini
	//in: -
	//out: returneaza lungimea listei
	return this->repo.getAllR().size();
}

Repository Service::getRepoC()
{
	//returneaza toate elementele din repo
	//in: -
	//out: lista repourilor
	return this->repo;
}