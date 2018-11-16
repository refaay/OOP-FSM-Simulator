#include "Wait.h"


Wait::Wait(const string& s) : currentState(s) // default constructor
{
	actionName = "Wait";
}

Wait::~Wait()
{
	delete trans;
}

bool Wait::setCurrentState(const string& n){
	currentState = n;
	return true;
}

string Wait::getCurrentState()const{
	return currentState;
}

string Wait::getString()const{ // general get string virtual function
	return nextState;
}

bool Wait::execute(){ // full execution
	int v;
	unsigned int i;
	bool found = false;
	do{ // get a valid user input
		cout << "Enter transition value while in state " + getCurrentState() + ": ";
		cin >> v;
		for (i = 0; i < (*trans).size() && !found; i++){
			found = (v == (*trans)[i].getValue() && currentState == (*trans)[i].getCurrent()); // i points to right transition
		}
		if (!found) cout << "Re-";
	} while (!found); // till a valid input is got
	i--;
	nextState = (*trans)[i].getNext(); // update
	return true;
}

bool Wait::setTrans(vector<Transition>* s){
	trans = s;
	return true;
}

string Wait::getName()const{ // to differentiate actions' kinds
	return actionName;
}