#include "Sleep.h"


SleepA::SleepA(const int& a) : amount(a) // construct
{
	actionName = "SleepA";
}

SleepA::~SleepA()
{
}

bool SleepA::execute(){
	SleepEx(amount * 1000, false); // sleeps
	return true;
}

string SleepA::getName()const{ // to differentiate actions' kinds
	return actionName;
}

string SleepA::getString()const{
	return "";
}