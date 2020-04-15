#include "Service.h"

Service::Service()
{
	//constructor default
	this->repoFile = {};
}

Service::~Service()
{
	//destructor
	if (!this->repoFile.getAllR().empty())
		this->repoFile.getAllR().clear();
}

void Service::addMasinaC(Masina m)
{
	//adauga o masina folosind functia add din repo
	//in: m de tip masina
	//out: -
	if (this->repoFile.findNrR(m.getNr()) == true)
		cout << "Aceasta masina nu poate fi adaugata!" << endl;
	else
		this->repoFile.addMasinaR(m);
}

void Service::updateMasinaC(int index, Masina m)
{
	//actualizeaza o masina folosind functia update din repo
	//in: index de tip int si m de tip masina
	//out: -
	this->repoFile.updateMasinaR(index, m);
}

void Service::delMasinaC(Masina m)
{
	//sterge o masina folosind functia delete din repo
	//in: m de tip masina
	//out: -
	this->repoFile.delMasinaR(m);
}

void Service::readMasiniC()
{
	//afiseaza lista de masini folosind toString
	for (auto elem : this->repoFile.getAllR())
		cout << elem.toString() << endl;
}

int Service::getLenC()
{
	//returneaza lungimea listei de masini
	//in: -
	//out: returneaza lungimea listei
	return this->repoFile.getAllR().size();
}

void Service::citireFileC(const char * file)
{
	//citeste datele din fisier apeland functia citireFileR din repo
	//in: numele fisierului
	//out: -
	this->repoFile.citireFileR(file);
}

char* Service::getStatusC(int index)
{
	//functia returneaza statusul unei masini in functie de indexul acesteia
	//in: indexul masinii
	//out: statusul masinii de la acel index
	return this->repoFile.getStatusR(index);
}

void Service::updateStatusC(const char* newStatus, int index)
{
	//functia actualizeaza statusul unei masini
	//in: newStatus - char*, noul status al masinii, index - int, indexul masinii la care se modifica statusul
	//out: -
	this->repoFile.updateStatusR(newStatus, index);
}

int Service::getOcupatC()
{
	//functia returneaza nr masinilor cu statusul "ocupat"
	//in: -
	//out: nr masinilor cu statusul "ocupat"
	int ocupat = 0;
	for (auto elem : this->repoFile.getAllR())
		if (strcmp(elem.getStatus(), "ocupat") == 0)
			ocupat++;
	return ocupat;
}

Repository Service::getRepoC()
{
	//returneaza toate elementele din repo
	//in: -
	//out: lista repourilor
	return this->repoFile;
}