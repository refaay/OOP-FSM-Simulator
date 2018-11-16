#include "Run.h"


Run::Run(const string& r) : runMachine(r) // construct a run object
{
	actionName = "Run";
}


Run::~Run()
{
}

bool Run::execute(){ // does nothing here
	return true;
}

string Run::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string Run::getString()const{ // return machine to be run name
	return runMachine;
}