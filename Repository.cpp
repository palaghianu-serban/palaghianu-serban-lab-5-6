#include "Repository.h"
#include <iostream>
#include <cstddef>


Repository::Repository() {
}
Repository::~Repository() {
}
void Repository::addMasinaR(Masina m) 
{
	lista.push_back(m);
}

bool Repository::findMasinaR(Masina m) {
	vector<Masina>::iterator i;
	i = find(lista.begin(), lista.end(), m);
	if (i != lista.end()) 
		return true;
	return false;
}
int Repository::getLenR() {

	return lista.size();
}
vector<Masina> Repository::getAllR() {

	return lista;
}











