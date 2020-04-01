#include "Masina.h"
#include "Repository.h"
#include "Tests.h"
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

int main()
{
	tests();
	tests_Repo();
	Repository repo;
	
	Masina m1 = Masina("Vlad", "SV31FWF", "inchiriat");
	Masina m2 = Masina(m1);

	cout << m1.toString() << endl;
	cout << m2.toString() << endl;

	system("pause");
	return 0;
}