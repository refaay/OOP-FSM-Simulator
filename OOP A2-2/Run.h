#pragma once
#include "Action.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// run action class
class Run : public Action
{
public:
	Run(const string&);
	~Run();
	virtual bool execute();
	virtual string getName()const;
	virtual string getString() const;
private:
	string runMachine;
};