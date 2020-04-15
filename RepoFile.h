#pragma once
#include "Repository.h"
#include <fstream>
#include <iostream>

using namespace std;

class RepoFile : public Repository
{
private:
	char* file;
public:
	RepoFile();
	RepoFile(char* file);
	void citireFileR(const char* file);

};
