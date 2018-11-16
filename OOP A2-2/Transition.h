#pragma once
#include <string>
using namespace std;
class Transition
{
public:
	Transition();
	Transition(const string&, const string&, const int&);
	~Transition();
	bool setCurrent(const string&);
	bool setNext(const string&);
	bool setValue(const int&);
	string getCurrent() const;
	string getNext()const;
	int getValue()const;
private:
	string current; // first state
	string next; // second state
	int value; // transition value
};
