#include "Masina.h"
#include "Repository.h"
#include "Tests.h"
#include <iostream>
#include <Windows.h>
#include "UI.h"

using namespace std;

int main()
{
	testMasina();
	testRepo();
	testServ();
	testRepoFile();

	cout << endl;
	
	UI u;
	u.menu();

	system("pause");
	return 0;
}