#include "Var.h"
#include <string>
using namespace std;

Var::Var() : name('x'), value(0) // default initialization
{
}

Var::Var(const char& n, const int& v)
{
	setName(n);
	setValue(v);
}

Var::~Var()
{
}

bool Var::setName(const char& n){
	name = n;
	return true;
}

char Var::getName() const{
	return name;
}

bool Var::setValue(const int& v){
	value = v;
	return true;
}

int Var::getValue()const{
	return value;
}