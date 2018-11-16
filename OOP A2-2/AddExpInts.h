#pragma once
#include "AddExp.h"
#include "Var.h"
#include <vector>
using namespace std;
// adds two 1 digit numbers and puts result in a variable
class AddExpInts : public AddExp
{
public:
	AddExpInts(const int&, const int&, Var*);
	~AddExpInts();
	virtual bool execute();
	virtual string getName()const;
	virtual string getString() const; 
private:
	// addition operands
	int first; 
	int second;
	Var* result;
};

