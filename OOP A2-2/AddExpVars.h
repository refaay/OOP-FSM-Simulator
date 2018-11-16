#pragma once
#include "AddExp.h"
#include "Var.h"
#include <vector>
//using namespace std;
// add two variables
class AddExpVars: public AddExp
{
public:
	AddExpVars( Var*,  Var*, Var*);
	~AddExpVars();
	virtual bool execute();
	virtual string getName()const;
	virtual string getString() const;
private:
	Var* first;
	Var* second;
	Var* result;
};

