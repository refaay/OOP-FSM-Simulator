#pragma once
#include <string>
#include <fstream> // for input streams
#include <sstream> // for string manipulation
#include <cctype>
#include <vector>

#include "Var.h"
#include "State.h"
#include "Transition.h"
#include "Wait.h"

// Finite State Machine class

static vector<string>* rM = new vector<string>; // vector of running machines' names

class Machine
{
	friend class Wait;
public:
	Machine(const string&);
	~Machine();
	bool findVar(const char&) const;
	Var* getVar(const char&)const;
	bool findState(const string&) const;
	bool findTrans(const string&, const string&, const int&) const;
	virtual bool execute();
	bool findFSM(const string&);//
	bool validateSleepAmount(const int&)const;
	
private:
	//string name; 
	string currentState; // currently executed state
	vector<Var*> Vars; // all variables
	vector<State>* States; // all states
	vector<Transition>* Transitions; // all transitions
	vector<Action*> currentActions; // current state's actions
	bool ended; // machine ended?
};

