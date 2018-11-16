#include "AddExpInts.h"


AddExpInts::AddExpInts(const int& a, const int& b, Var* y) :first (a), second (b), result(y)	{ // construct an integers addition
	actionName = "AddExpInts";
}

AddExpInts::~AddExpInts()
{
	delete result;
}

bool AddExpInts::execute(){ // add
	(*result).setValue(first + second);
	return true;
}

string AddExpInts::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string AddExpInts::getString()const{
	return "";
}