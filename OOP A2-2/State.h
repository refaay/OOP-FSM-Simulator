#pragma once
#include "Action.h"
#include "Sleep.h"
#include "Wait.h"
#include "End.h"
#include "AddExp.h"
#include "AddExpVars.h"
#include "AddExpVarInt.h"
#include "AddExpInts.h"
#include "OutExp.h"
#include "OutString.h"
#include "Run.h"
#include <string>
#include <vector>
using namespace std;
// states class
class State
{
public:
	State();
	State(const string&, const vector<Action*>&);
	~State();
	bool setName(const string&);
	string getName() const;
	vector<Action*>getActions()const;
	bool setActions(const vector<Action*>&);
	string getNextState()const;
private:
	string name;
	string nextState;
	string nextMachine;
	vector<Action*> actions;
};