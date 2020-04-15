#include "Repository.h"
#include <iostream>
#include <ostream>


Repository::Repository()
{
	//constructor default
	this->masini = {};
}
Repository::~Repository()
{
	//destructor
	if (!this->masini.empty())
		this->masini.clear();
}
void Repository::addMasinaR(Masina m) 
{
	//functie de add folosind operatiile specifice unei liste
	//in: m de tip Masina
	//out: -
	masini.push_back(m);
}

void Repository::delMasinaR(Masina m)
{
	//functie de delete folosind operatiile specifice unei liste
	//in: m de tip Masina
	//out: -
	masini.remove(m);
}

void Repository::delMasinaIndexR(int index)
{
	//functie de delete dupa index folosind operatiile specifice unei liste
	//in: index de tip int(a cata masina se doreste stearsa)
	//out: -
	this->i = masini.begin();
	advance(i, index);
	masini.erase(i);
}

void Repository::updateMasinaR(int index, Masina m)
{
	//functie de update folosind operatiile specifice unei liste
	//in: index de tip int si m de tip Masina
	//out: -
	try
	{
		this->i = masini.begin();
		advance(i, index);
		i->setPosesor(m.getPosesor());
		i->setNr(m.getNr());
		i->setStatus(m.getStatus());
	}
	catch (exception exp)
	{
		cout << "Masina pe care doriti sa o inlocuiti nu a fost gasita" << endl;
	}
}

int Repository::getLenR()
{
	//returneaza lungimea listei de masini
	//in: -
	//out: returneaza lungimea listei de masini(cate masini sunt in adaugate in lista)
	return masini.size();
}

bool Repository::findElemR(Masina m)
{
	//cauta un element m in lista de masini
	//in: m de tip Masina
	//out: true daca masian a fost gasita, false altfel
	for (auto elem : this->masini)
		if (elem.compare(m) == true)
			return true;
	return false;
}

bool Repository::findNrR(char* n)
{
	for (auto elem : this->masini)
	{
		if (strcmp(elem.getNr(), n) == 0)
		{
			return true;
		}
	}
	return false;
}

char* Repository::getStatusR(int index)
{
	this->i = masini.begin();
	advance(this->i, index);
	return this->i->getStatus();
}

void Repository::updateStatusR(const char* newStatus, int index)
{
	this->i = masini.begin();
	advance(this->i, index);
	this->i->setStatus(newStatus);
}


list<Masina> Repository::getAllR()
{
	//returneaza toate elementele din lista
	//in: -
	//out: returns o lista cu toate masinile
	return masini;
}











