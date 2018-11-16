#include "OutString.h"


OutString::OutString(const string& s) : value(s) // assign the string to be printed
{
	actionName = "OutString";
}

OutString::~OutString()
{
}

bool OutString::execute(){ // print
	cout << value << endl;
	return true;
}

string OutString::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string OutString::getString()const{
	return "";
}