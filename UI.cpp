#include "UI.h"
#include <iostream>

using namespace std;

void UI::printMenu()
{
	cout << "0. Iesire." << endl;
	cout << "1. Add." << endl;
	cout << "2. Display." << endl;
	cout << "3. Update." << endl;
	cout << "4. Delete." << endl;
	cout << endl << endl;
	cout << "5. Intrare masina in parcare" << endl;
	cout << "6. Iesire masina din parcare" << endl;
}

void UI::menu()
{
	bool ok =true;
	int opt;
	RepoFile repoFile;
	/*Masina m1 = Masina("Serban", "SV98SER", "ocupat");
	Masina m2 = Masina("Vlad", "CJ31ABA", "ocupat");
	Masina m3 = Masina("Cioata", "GL31DFM", "liber");
	Masina m4 = Masina("Andreea", "B312NGW", "ocupat");

	this->serv.addMasinaC(m1);
	this->serv.addMasinaC(m2);
	this->serv.addMasinaC(m3);
	this->serv.addMasinaC(m4);*/

	const char* file = new char[50];
	file = "intrare.txt";
	this->serv.citireFileC(file);

	int capMax = 3;
	int capCur = this->serv.getOcupatC();

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
			if (strcmp(status, "ocupat") == 0)
			{
				if (capCur < capMax)
				{
					Masina m1 = Masina(posesor, nr, status);
					this->serv.addMasinaC(m1);
					capCur++;
				}
				else
					cout << "FULL!" << endl << endl;
			}
			else
			{
				Masina m1= Masina(posesor, nr, status);
				this->serv.addMasinaC(m1);
			}
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
			if (strcmp(statusN, "ocupat") == 0)
				capCur++;
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
			if (strcmp(statusV, "ocupat") == 0)
				cout << "Nu se pot sterge masinile ocupate" << endl;
			else
			{
				Masina mV = Masina(posesorV, nrV, statusV);
				this->serv.delMasinaC(mV);
				cout << "Masina a fost stearsa" << endl << endl;
			}
		}
		else if (opt == 5)
		{
			int i = 0;
			this->serv.readMasiniC();
			cout << endl;
			if (capCur < capMax)
			{
				cout << "Introduceti indexul masinii: ";
				cin >> i;
				if (strcmp(this->serv.getStatusC(i), "liber") == 0)
				{
					this->serv.updateStatusC("ocupat", i);
					capCur++;
				}
				else
					cout << "Nu se poate intra cu o masina deja ocupata" << endl;
			}
			else
				cout << "FULL" << endl << endl;
		}
		else if (opt == 6)
		{
			int j = 0;
			this->serv.readMasiniC();
			cout << endl;
			cout << "Introduceti indexul masinii: ";
			cin >> j;
			if (strcmp(this->serv.getStatusC(j), "ocupat") == 0)
			{
				this->serv.updateStatusC("liber", j);
				capCur--;
			}
			else
				cout << "Nu se poate iesi cu o masina libera" << endl;
		}
	}
}