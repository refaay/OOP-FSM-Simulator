#include "AddExpVarInt.h"


AddExpVarInt::AddExpVarInt(Var* a, const int& b, Var* y) :first(a), second(b), result(y){ // construct an int+var exp
	actionName = "AddExpVarInt";
}

AddExpVarInt::~AddExpVarInt()
{
	delete first;
	delete result;
}

bool AddExpVarInt::execute(){ // add
	(*result).setValue((*first).getValue() + second);
	return true;
}

string AddExpVarInt::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string AddExpVarInt::getString()const{
	return "";
}