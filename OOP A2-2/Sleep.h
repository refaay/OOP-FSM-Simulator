#pragma once
#include "Action.h"
#include <windows.h>
using namespace std;
// sleep action class
class SleepA : public Action
{
public:
	SleepA(const int&);
	~SleepA();
	virtual bool execute();
	virtual string getName()const;
	virtual string getString() const;
private:
	int amount;
};

