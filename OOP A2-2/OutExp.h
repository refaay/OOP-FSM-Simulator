#pragma once
#include "Action.h"
#include "Var.h"
#include <vector>
#include <iostream>
using namespace std;
// print variable's value class
class OutExp: public Action
{
public:
	OutExp(Var*);
	~OutExp();
	virtual bool execute();
	virtual string getName()const;
	virtual string getString() const;
private:
	Var* v; // to be printed
};

