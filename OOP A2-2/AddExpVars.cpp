#include "AddExpVars.h"


AddExpVars::AddExpVars( Var* a,  Var* b, Var* y) : first(a), second(b), result(y){ // construct variables addition exp
	actionName = "AddExpVars";
}

AddExpVars::~AddExpVars()
{
	delete first;
	delete second;
	delete result;
}

bool AddExpVars::execute(){ // add
	(*result).setValue((*first).getValue()+(*second).getValue());
	return true;
}

string AddExpVars::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string AddExpVars::getString()const{
	return "";
}