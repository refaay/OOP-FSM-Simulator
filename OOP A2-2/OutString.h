#pragma once
#include "Action.h"
#include <iostream>
#include <string>
using namespace std;
// Print string class
class OutString : public Action
{
public:
	OutString(const string&);
	~OutString();
	virtual bool execute();
	virtual string getName()const;
	virtual string getString() const;
private:
	string value; // to be printed
};

