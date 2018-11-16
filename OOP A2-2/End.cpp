#include "End.h"


End::End() // constructor
{
	actionName = "End";
}


End::~End()
{
}

bool End::execute(){ // does nothing here
	return true;
}

string End::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string End::getString()const{
	return "";
}