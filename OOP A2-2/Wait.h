#pragma once
#include <string>
#include "Transition.h"
#include "State.h"
#include <vector>
#include <iostream>
#include "Action.h"
//#include "Machine.h"
using namespace std;
// wait action class
class Wait : public Action
{
public:
	Wait(const string&);
	~Wait();
	bool setCurrentState(const string&);
	string getCurrentState() const;
	virtual string getString() const;
	bool setTrans(vector<Transition>*);
	virtual bool execute();
	virtual string getName()const;
private:
	string currentState;
	string nextState;
	vector<Transition>* trans;
};