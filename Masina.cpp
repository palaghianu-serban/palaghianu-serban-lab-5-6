#include "Masina.h"
#include <string.h>
#include <stdlib.h>

Masina::Masina()
{
	this->posesor = NULL;
	this->nr = NULL;
	this->status = NULL;
}

Masina::Masina(const char* p, const char* n, const char* s)
{
	this->posesor = new char[strlen(p) + 1];
	strcpy_s(this->posesor, strlen(p) + 1, p);
	this->nr = new char[strlen(n) + 1];
	strcpy_s(this->nr, strlen(n) + 1, n);
	this->status = new char[strlen(s) + 1];
	strcpy_s(this->status, strlen(s) + 1, s);
}

Masina::Masina(const Masina &m)
{
	//constructor cu 1 singur parametru
	//in: p de tip Project
	this->posesor = new char[strlen(m.posesor) + 1];
	strcpy_s(this->posesor, strlen(m.posesor) + 1, m.posesor);
	this->nr = new char[strlen(m.nr) + 1];
	strcpy_s(this->nr, strlen(m.nr) + 1, m.nr);
	this->status = new char[strlen(m.status) + 1];
	strcpy_s(this->status, strlen(m.status) + 1, m.status);
}

Masina::~Masina() {
	if (this->posesor) {
		delete[] this->posesor;
		this->posesor = NULL;
	}
	if (this->nr) {
		delete[] this->nr;
		this->nr = NULL;
	}
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}
}

char* Masina::getPosesor()
{
	//out: returns GitPath
	return this->posesor;
}

void Masina::setPosesor(const char* p)
{
	//setter GitPath
	//in: gitPathN (new value)
	//out: -
	if (this->posesor) {
		delete[] this->posesor;
	}
	this->posesor = new char[strlen(p) + 1];
	strcpy_s(this->posesor, strlen(p) + 1, p);
}

char* Masina::getNr()
{
	//out: returns GitPath
	return this->nr;
}

void Masina::setNr(const char* n)
{
	//setter GitPath
	//in: gitPathN (new value)
	//out: -
	if (this->nr) {
		delete[] this->nr;
	}
	this->nr = new char[strlen(n) + 1];
	strcpy_s(this->nr, strlen(n) + 1, n);
}

char* Masina::getStatus()
{
	//out: returns GitPath
	return this->status;
}

void Masina::setStatus(const char* s)
{
	//setter GitPath
	//in: gitPathN (new value)
	//out: -
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(s) + 1];
	strcpy_s(this->status, strlen(s) + 1, s);
}

Masina & Masina::operator=(const Masina &m)
{
	//suprascriere
	if (this != &m)
	{
		this->setPosesor(m.posesor);
		this->setNr(m.nr);
		this->setStatus(m.status);
	}
	return *this;
}

bool Masina::operator==(const Masina& m) {
	return (strcmp(this->posesor, m.posesor) == 0) && (strcmp(this->nr, m.nr)) && (strcmp(this->status, m.status) == 0);
}

ostream& operator<<(ostream& os, const Masina& m)
{
	os << m.posesor << " " << m.nr << " " << m.status;
	return os;
}

char* Masina::toString()
{
	//afisarea unei variabile de tip project
	if (this->posesor != NULL) {
		int noChars = strlen(this->posesor) + strlen(this->nr) + strlen(this->status) + 3 + 3 + 1;
		char* s = new char[noChars];
		char* aux = new char[5];
		strcpy_s(s, noChars, this->posesor);
		strcat_s(s, noChars, " | ");
		strcpy_s(s, noChars, this->nr);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, " | ");
		strcpy_s(s, noChars, this->status);
		strcat_s(s, noChars, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		return s;
	}
	else
		return NULL;
}