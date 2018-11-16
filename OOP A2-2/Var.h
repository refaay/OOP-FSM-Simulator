#pragma once
#include <string>
using namespace std;
// variables class
class Var
{
public:
	Var();
	Var(const char&, const int&);
	~Var();
	bool setName(const char&);
	char getName() const;
	bool setValue(const int&);
	int getValue() const;
private:
	char name; // variable's name
	int value; // variable's value
};