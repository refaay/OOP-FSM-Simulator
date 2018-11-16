#include "State.h"

State::State() :name("Unnamed") // default constructor
{
}

State::State(const string& s, const vector<Action*>& v) : name(s) // normal constructor
{
	for (unsigned int i = 0; i < v.size(); i++){
		(actions).push_back(v[i]);
	}
}

State::~State() // destructor
{
	/*for (int p = 0; p < actions.size(); p++)
		delete actions[p];*/
}

bool State::setName(const string& n){
	name = n;
	return true;
}

string State::getName() const{
	return name;
}

vector<Action*> State::getActions()const{
	return actions;
}

string State::getNextState()const{
	return nextState;
}

bool State::setActions(const vector<Action*>& v){
	for (unsigned int i = 0; i < v.size(); i++){
		actions.push_back(v[i]);
	}
	return true;
}