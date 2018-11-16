#include "Transition.h"


Transition::Transition() // default constructor
{
}

Transition::Transition(const string& c, const string& n, const int& v) // normal constructor
{
	setCurrent(c);
	setNext(n);
	setValue(v);
}

Transition::~Transition()
{
}

bool Transition::setCurrent(const string& n){
	current = n;
	return true;
}
bool Transition::setNext(const string& n){
	next = n;
	return true;
}
bool Transition::setValue(const int& v){
	value = v;
	return true;
}
string Transition::getCurrent()const{
	return current;
}
string Transition::getNext()const{
	return next;
}
int Transition::getValue()const{
	return value;
}