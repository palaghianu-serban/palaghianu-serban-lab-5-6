#include "RepoFile.h"


RepoFile::RepoFile()
{
	//constructor default Repofile
	this->file = NULL;
}


RepoFile::RepoFile(char * file)
{
	//constructor cu parametri
	//in: numele fisierului de intrare
	//out: -
	this->file= file;
	citireFileR(file);
}

void RepoFile::citireFileR(const char * file)
{
	//functie care citeste din fisier dat
	//in: numele fisierului de intrare
	//out: -
	ifstream fin;
	fin.open(file);
	if (!fin)
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}
	else
	{
		Masina masina;
		char* posesor = new char[50];
		char* nr = new char[50];
		char* status = new char[50];
		while (!fin.eof())
		{
			fin >> posesor >> nr >> status;
			masina = Masina(posesor, nr, status);
			this->addMasinaR(masina);

		}
	}
	fin.close();
}