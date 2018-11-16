#include "Action.h"


Action::Action()
{
}


Action::~Action()
{
}

bool Action::execute(){ 
	return true; 
}

std::string Action::getName()const{ // to differentiate actions' kinds
	return actionName;
}