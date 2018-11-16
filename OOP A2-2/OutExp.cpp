#include "OutExp.h"


OutExp::OutExp(Var* var) : v(var) // validation done in machine
{
	actionName = "OutExp";
}

OutExp::~OutExp()
{
	delete v;
}

bool OutExp::execute(){ // print
	cout << (*v).getValue() << endl;
	return true;
}

string OutExp::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string OutExp::getString()const{
	return "";
}