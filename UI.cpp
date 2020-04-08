#include "UI.h"
#include <iostream>

using namespace std;

void UI::printMenu()
{
	cout << "0. Iesi din meniu." << endl;
	cout << "1. Add: " << endl;
	cout << "2. Display: " << endl;
	cout << "3. Update: " << endl;
	cout << "4. Delete: " << endl;
}

void UI::menu()
{
	bool ok =true;
	int opt;
	Repository repo;
	Masina m1 = Masina("Serban", "SV98SER", "ocupat");
	Masina m2 = Masina("Vlad", "CJ31ABA", "ocupat");
	Masina m3 = Masina("Cioata", "GL31DFM", "liber");
	Masina m4 = Masina("Andreea", "B312NGW", "ocupat");

	this->serv.addMasinaC(m1);
	this->serv.addMasinaC(m2);
	this->serv.addMasinaC(m3);
	this->serv.addMasinaC(m4);

	while (ok == true)
	{
		printMenu();
		cout << "Alegeti o optiune: " << endl;
		cin >> opt;
		if (opt == 0)
		{
			ok = false;
			system("pause");
		}
		else if (opt == 1)
		{
			char* posesor = new char[50];
			char* nr = new char[50];
			char* status = new char[50];
			cout << "Nume: ";
			cin >> posesor;
			cout << "Numar: ";
			cin >> nr;
			cout << "Status: ";
			cin >> status;
			Masina m = Masina(posesor, nr, status);
			this->serv.addMasinaC(m);
		}
		else if (opt == 2)
		{
			this->serv.readMasiniC();
			cout << endl;
		}
		else if (opt == 3)
		{
			int i;
			char* posesorN = new char[50];
			char* nrN = new char[50];
			char* statusN = new char[50];
			cout << "A cata masina: ";
			cin >> i;
			cout << "Nume nou: ";
			cin >> posesorN;
			cout << "Nr nou: ";
			cin >> nrN;
			cout << "Status nou: ";
			cin >> statusN;
			Masina mN = Masina(posesorN, nrN, statusN);
			this->serv.updateMasinaC(i, mN);
		}
		else if (opt == 4)
		{
			char* posesorV = new char[50];
			char* nrV = new char[50];
			char* statusV = new char[50];
			cout << "Nume: ";
			cin >> posesorV;
			cout << "Numar: ";
			cin >> nrV;
			cout << "Status: ";
			cin >> statusV;
			Masina mV = Masina(posesorV, nrV, statusV);
			this->serv.delMasinaC(mV);
		}
	}
}