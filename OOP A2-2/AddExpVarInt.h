#pragma once
#include "AddExp.h"
#include "Var.h"
#include <vector>
// add variable to 1 digit int
class AddExpVarInt: public AddExp
{
public:
	AddExpVarInt( Var*, const int&, Var*);
	~AddExpVarInt();
	virtual bool execute();
	virtual string getName()const;	
	virtual string getString() const;
private:
	Var* first;
	int second;
	Var* result;
};

