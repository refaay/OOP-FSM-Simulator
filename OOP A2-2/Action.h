#pragma once
#include <string>
#include <vector>
using namespace std;
// Abstract action class
class Action
{
public:
	Action();
	~Action();
	virtual bool execute() = 0;
	string getName()const;
	virtual string getString()const = 0;
	string actionName;	
};